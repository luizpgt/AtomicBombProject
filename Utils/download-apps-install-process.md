# create .local/opt/

```sh
mkdir ~/.local/opt
```

# Extract inside dir 

```sh
mkdir -p ~/.local/opt/postman
```

```sh
tar -xvf Postman-linux-x64.tar.gz -C ~/.local/opt/postman
```

# Create Symlink

If the main Postman executable is `Postman`

```sh
ln -s ~/.local/opt/postman/Postman ~/.local/bin/postman
```

# Create a desktop file 

```sh
[Desktop Entry]
Name=Postman
Comment=API development environment
Exec=postman
Icon=postman
Terminal=false
Type=Application
Categories=Development;
```sh
