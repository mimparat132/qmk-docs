## Dactyl Manuform TLDR Guide

### Setting up QMK

-   Clone the qmk firmware repository

```bash
cd ~/git
git clone git@github.com:qmk/qmk_firmware.git
cd qmk_firmware
```

-   Initialize the qmk git repository. This step ensures all the git submodules have been cloned

```bash
qmk setup
```

-   The rest of the commands assume a working directory of `~/git/qmk_firmware`

-   Install the qmk CLI tool
-   [source for install docs](https://github.com/qmk/qmk_fpm)

```bash
# Add the QMK source to your apt repositories list:
echo "deb https://linux.qmk.fm/ $(lsb_release --codename --short) main" | sudo tee /etc/apt/sources.list.d/qmk.list

# Add the QMK GPG Key:
wget -qO - https://linux.qmk.fm/gpg_pubkey.txt | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/qmk-gpg-pubkey.gpg > /dev/null

# Update apt:
sudo apt update

# Install QMK:
sudo apt install qmk
```

-   Configure qmk CLI with the target keyboard and keymap file
-   [QMK cli config docs](https://github.com/qmk/qmk_firmware/blob/master/docs/cli_configuration.md#cli-documentation-qmk-config)

```bash
qmk config compile.keyboard=handwired/dactyl_manuform/5x6

# Create a custom keymap file by cloning the default layout directory
cp -r ~/git/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/default ~/git/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/jacks-config

# Modify the keymap.c file to the way you like it

# Set the default keymap compile target
qmk config compile.keymap=jacks-layout
```

-   See [QMK keycode docs](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md) for a complete list of qmk keycodes you can use to make your keymap.

-   In order to communicate with the bootloader device when flashing your keyboard, you'll need to update your udev rules. You could just run sudo with the commands but updating your udev rules is the reccomended approach.
-   [Update udev rules for linux environments](https://github.com/qmk/qmk_firmware/blob/master/docs/faq_build.md#linux-udev-rules-linux-udev-rules)
-   Follow this documentation to setup your udev rules.

### Flash your keyboard

-   [Flashing source docs](https://github.com/qmk/qmk_firmware/blob/master/docs/newbs_flashing.md#flash-your-keyboard-from-the-command-line)
-   The flashing instructions need to be done on each half separtely.

1. Connect the usb cable to the keyboard keyboard half. Make sure the two halves are not connected to each other
2. Run `qmk flash` from the `~/git/qmk_firmware` directory. You'll see output like the following:

```bash
$ qmk flash

Flashing for bootloader: caterina
Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)..........
```

3. Reset your keyboard. Press the blue button on the back of the keyboard next to the usb cable. You should only have to press it once, but if nothing happens, give it another press.
4. You should see it flash your keyboard.
5. Disconnect the keyboard half and repeat this process on the other half.

### Debugging

-   A good way to debug your keyboard is to run the qmk console to check for key presses.
-   [qmk console docs](https://docs.qmk.fm/cli_commands#qmk-console)

```bash
# Run the qmk console command
qmk console
```

-   It should find your keyboard and you'll be able to see if you keys are sending the right keycodes
