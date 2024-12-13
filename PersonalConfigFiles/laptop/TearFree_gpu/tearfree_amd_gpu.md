# Set TearFree on inside X

Install required drivers:
```
sudo pacman -S mesa xf86-video-amdgpu
```
references: https://wiki.archlinux.org/title/Xorg

To check the current status of this option on all your currently connected displays, run the following command:
```
xrandr --verbose | grep "TearFree"
```

At `/etc/X11/xorg.conf.d/20-amdgpu.conf`:
```
Section "Device"
    Identifier "AMD Graphics"
    Driver "amdgpu"
    Option "TearFree" "true"
EndSection

```
references: https://davejansen.com/quick-how-to-fix-screen-tearing-in-ubuntu-with-amd-gpus/
