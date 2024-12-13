# Keyboard layout/model/variant

# Using localectl

List available keymaps:
```
localectl list-keymaps
```

Set:
```
loadkeys br-abnt2 
```

# Inside Xsession: 

The layout name is usually a 2-letter country code. To see a full list of keyboard models, layouts, variants and options, along with a short description, open /usr/share/X11/xkb/rules/base.lst. Alternatively, you may use one of the following commands to see a list without a description:

```
localectl list-x11-keymap-models
localectl list-x11-keymap-layouts
localectl list-x11-keymap-variants [layout]
localectl list-x11-keymap-options
```

The usage is as follows (see setxkbmap(1)):
```
setxkbmap [-model xkb_model] [-layout xkb_layout] [-variant xkb_variant] [-option xkb_options]
```

## Using X configuration files

This method creates system-wide configuration which is persistent across reboots.

Here is an example:

At `/etc/X11/xorg.conf.d/00-keyboard.conf`

```
Section "InputClass"
        Identifier "system-keyboard"
        MatchIsKeyboard "on"
        Option "XkbLayout" "br"
        Option "XkbModel" "thinkpad"
EndSection
```

references: https://wiki.archlinux.org/title/Xorg/Keyboard_configuration
