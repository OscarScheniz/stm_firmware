# Firmware for STM32F303

This project contains the firmware for the Nucleo STM32F303.
The project is built and flashed using Makefile and is edited in VSCode.

## Build

Run `make` in the terminal to build the project.

## Flash

Run `make flash` in the terminal to flash the project onto the MCU.

## Debug

### SEGGER Ozone
Segger Ozone has many features that makes debugging easier. In order to use Ozone we need a Segger JLink Debugger or we could use the STLink Debugger fitted on the Nucleo Board.
To use the STLink Debugger we need to reflash it with JLink FW. Do this by following these steps: https://www.segger.com/products/debug-probes/j-link/models/other-j-links/st-link-on-board/

### STM32CubeIDE
You could also use the STM32CubeIDE to debug but it is not recommended.
