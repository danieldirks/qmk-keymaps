USERNAME = danieldirks

KEYBOARDS = q1v2 q0  # short names used for targets
# full keyboard identifier as in `qmk list-keyboards`
IDENTIFIER_q0 = keychron/q0/plus
IDENTIFIER_q1v2 = keychron/q1v2/ansi_encoder


all: $(KEYBOARDS)

.PHONY: all setup $(KEYBOARDS) clean

qmk_firmware:
	git submodule update --init --recursive
	git -C qmk_firmware submodule update --init --recursive

setup: qmk_firmware
	./qmk_firmware/util/qmk_install.sh

$(KEYBOARDS): qmk_firmware
	rm -rf ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USERNAME)
	rm -rf ./qmk_firmware/users/$(USERNAME)
	mkdir -p ./build

	cp -r $(shell pwd)/$(@) ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USERNAME)
	cp -r $(shell pwd)/user ./qmk_firmware/users/$(USERNAME)

	make -C qmk_firmware BUILD_DIR=$(shell pwd)/build -j1 $(IDENTIFIER_$@):$(USERNAME)

clean:
	rm -rf ./build/
	rm -rf ./qmk_firmware/
