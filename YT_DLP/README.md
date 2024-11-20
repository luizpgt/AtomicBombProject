# Download musics and videos using yt-dlp

Docs and Github: [yt-dlp github](https://github.com/yt-dlp/yt-dlp)


# Download video using cookies for acessing account

```bash
yt-dlp --cookies-from-browser firefox _!link!_
```

# Download entire youtube playlist

No filename modification: 
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ -o '%(playlist)s/%(playlist_index)s_%(title)s.%(ext)s' _!playlist_link!_
```

Automatic filename modification:
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ --restrict-filenames -o '%(playlist)s/%(playlist_index)s_%(title)s.%(ext)s' _!playlist_link!_
```

Manual filename modification: 
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ --replace-in-metadata "playlist" "[ /]" "_" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s' _!playlist_link!_ 
```

# Download a single youtube music 

No filename modification: 
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ -o 'music/%(title)s.%(ext)s' _!link!_
```

Automatic filename modification:
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ --restrict-filenames -o 'music/%(title)s.%(ext)s' _!link!_
```
