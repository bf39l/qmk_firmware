# dactyl

Custom Dactyl keyboard build for this repository.

* Keyboard Maintainer: [bf39L](https://github.com/bf39l)
* Hardware Supported: Dactyl PCB/handwired build, RP2040 controllers
* Hardware Availability: See the build files and PCB sources in this repository

Manual Compile firmware for this keyboard:

    qmk compile -kb bf39l/dactyl -km default

Via:

    qmk compile -kb bf39l/dactyl -km via

Make example for this keyboard (after setting up your build environment):

    make bf39l/dactyl:default

Flashing example for this keyboard:

    make bf39l/dactyl:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
