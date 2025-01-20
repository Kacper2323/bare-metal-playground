#!/usr/bin/bash

rule_string='SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="374b", MODE="0666"'

printf "Setting up the mcu toochain."

pkgs=(gdb-multiarch gcc-arm-none-eabi make openocd usbutils)

sudo apt-get install -y --ignore-missing "${pkgs[@]}"

printf $rule_string > /etc/udev/rules.d/usb.rules

printf "Creating VSCode configuration.\n"

mkdir .vscode

printf '{
    "cortex-debug.variableUseNaturalFormat": true,
    "cortex-debug.openocdPath": "/usr/bin/openocd",
    "cortex-debug.gdbPath": "gdb-multiarch",
    "cortex-debug.objdumpPath": "/usr/bin/arm-none-eabi-objdump"
}' > ./.vscode/settings.json

printf '{
    "configurations":[

        {
            "type":"cortex-debug",
            "request": "launch",
            "servertype": "openocd",
            "cwd": "./",
            "executable": "firmware.elf",
            "name": "Debug openocd STML4",
            "device": "STM32L476",
            "svdFile": "./libs/STM32L4x6.svd",
            "configFiles": [
                "/usr/share/openocd/scripts/interface/stlink.cfg",
                "/usr/share/openocd/scripts/target/stm32l4x.cfg"
            ],
        }

    ]
}' > ./.vscode/launch.json

