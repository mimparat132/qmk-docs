## Dactyl Manuform TLDR Guide

### Setting up QMK

- Clone the qmk firmware repository

```bash
cd ~/git
git clone git@github.com:qmk/qmk_firmware.git
cd qmk_firmware
```

- Initialize the qmk git repository. This step ensures all the git submodules have been cloned

```bash
qmk setup
```

- The rest of the commands assume a working directory of `~/git/qmk_firmware`

- Install the qmk CLI tool
- [source for install docs](https://github.com/qmk/qmk_fpm)

```bash
# Install pipx - need it to install qmk since the apt package is no longer
# maintained/deprecated

sudo apt-get install pipx

# install qmk

pipx install qmk

# make sure you add the following path to your path so your system can find
# applications installed via pipx

export PATH="$HOME/.local/bin:$PATH"
```

- Configure qmk CLI with the target keyboard and keymap file
- [QMK cli config docs](https://github.com/qmk/qmk_firmware/blob/master/docs/cli_configuration.md#cli-documentation-qmk-config)

```bash
qmk config compile.keyboard=handwired/dactyl_manuform/5x6

# Create a custom keymap file by cloning the default layout directory
cp -r ~/git/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/default ~/git/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/jacks-config

# Modify the keymap.c file to the way you like it

# These config commands allow you to not have to pass them in at flash or compile time
qmk config compile.keymap=jacks-layout
qmk config user.keyboard=handwired/dactyl_manuform/5x6
qmk config user.keymap=jacks-layout
qmk config flash.keyboard=handwired/dactyl_manuform/5x6

```

- See [QMK keycode docs](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md) for a complete list of qmk keycodes you can use to make your keymap.

- In order to communicate with the bootloader device when flashing your keyboard, you'll need to update your udev rules. You could just run sudo with the commands but updating your udev rules is the reccomended approach.
- [Update udev rules for linux environments](https://github.com/qmk/qmk_firmware/blob/master/docs/faq_build.md#linux-udev-rules-linux-udev-rules)
- Follow this documentation to setup your udev rules.

### Flash your keyboard

- [Flashing source docs](https://github.com/qmk/qmk_firmware/blob/master/docs/newbs_flashing.md#flash-your-keyboard-from-the-command-line)
- The flashing instructions need to be done on each half separtely.

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

### Another way to flash your keyboard

- If the keyboard folder is `mimparat_4x6` and the keymap directory is `wille` you can also compile and flash the keyboard in one command without setting any config variables like so:

```bash
make mimparat_4x6:wille:flash
```

### Debugging

- A good way to debug your keyboard is to run the qmk console to check for key presses.
- [qmk console docs](https://docs.qmk.fm/cli_commands#qmk-console)

```bash
# Run the qmk console command
qmk console
```

- It should find your keyboard and you'll be able to see if you keys are sending the right keycodes
