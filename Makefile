USERNAME = danieldirks

# short names used for targets
KEYBOARDS = k7_pro

# full keyboard identifier as in `qmk list-keyboards`
IDENTIFIER_k7_pro = keychron/k7_pro/ansi/rgb

# set to non-empty string to flash on build
FLASH =


.PHONY: help
help:
	@echo "Build and flash firmware for keyboards."
	@echo
	@echo "Usage: make <keyboard> [FLASH=yes]"
	@echo "  keyboards: $(KEYBOARDS)"

.PHONY: clean
clean:
	rm -rf ./build/
	rm -rf ./qmk_firmware/

.PHONY: setup
setup: qmk_firmware
	./qmk_firmware/util/qmk_install.sh

qmk_firmware:
	git submodule update --init --recursive
	git -C qmk_firmware submodule update --init --recursive

.PHONY: $(KEYBOARDS)
$(KEYBOARDS): qmk_firmware
	rm -rf ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USERNAME)
	rm -rf ./qmk_firmware/users/$(USERNAME)
	mkdir -p ./build

	cp -r $(shell pwd)/$(@) ./qmk_firmware/keyboards/$(IDENTIFIER_$@)/keymaps/$(USERNAME)
	cp -r $(shell pwd)/user ./qmk_firmware/users/$(USERNAME)

	make -C qmk_firmware BUILD_DIR=$(shell pwd)/build -j1 $(IDENTIFIER_$@):$(USERNAME)

	@if [ ! -z $(FLASH) ]; then \
		make -C qmk_firmware BUILD_DIR=$(shell pwd)/build -j1 $(IDENTIFIER_$@):$(USERNAME):flash; \
	fi
