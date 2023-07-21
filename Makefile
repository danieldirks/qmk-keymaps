USER = danieldirks

KEYBOARDS = q1v2  # short names used for targets
# full keyboard identifier as in `qmk list-keyboards`
IDENTIFIER_q1v2 = keychron/q1v2/ansi_encoder


all: $(KEYBOARDS)

.PHONY: all setup clean $(KEYBOARDS)

setup:
	./qmk_firmware/util/qmk_install.sh

qmk_firmware:
	git submodule update --init --recursive
	git submodule update --remote

clean:
	rm -rf ./build/
	rm -rf ./qmk_firmware/

$(KEYBOARDS): qmk_firmware
	rm -rf ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USER)
	rm -rf ./qmk_firmware/users/$(USER)
	mkdir -p ./build

	ln -s $(shell pwd)/$(@) ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USER)
	ln -s $(shell pwd)/user ./qmk_firmware/users/$(USER)

	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(IDENTIFIER_$@):$(USER)
