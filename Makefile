USER = danieldirks

KEYBOARDS = q1v2  # short names used for targets
# full keyboard identifier as in `qmk list-keyboards`
IDENTIFIER_q1v2 = keychron/q1v2/ansi_encoder


all: $(KEYBOARDS)

.PHONY: all setup $(KEYBOARDS) clean

qmk_firmware:
	git submodule update --init --recursive
	git submodule update --remote

setup: qmk_firmware
	./qmk_firmware/util/qmk_install.sh

$(KEYBOARDS): qmk_firmware
	rm -rf ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USER)
	rm -rf ./qmk_firmware/users/$(USER)
	mkdir -p ./build

	ln -s $(shell pwd)/$(@) ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USER)
	ln -s $(shell pwd)/user ./qmk_firmware/users/$(USER)

	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(IDENTIFIER_$@):$(USER)

clean:
	rm -rf ./build/
	rm -rf ./qmk_firmware/
