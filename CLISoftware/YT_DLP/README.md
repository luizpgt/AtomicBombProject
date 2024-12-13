# Download musics and videos using yt-dlp

Docs and Github: [yt-dlp github](https://github.com/yt-dlp/yt-dlp)


# Download video using cookies for acessing account

```bash
yt-dlp --cookies-from-browser firefox _link_
```

# Download entire youtube playlist

No filename modification: 
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ -o '%(playlist)s/%(playlist_index)s_%(title)s.%(ext)s' _playlistLink_
```

Automatic filename modification:
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ --restrict-filenames -o '%(playlist)s/%(playlist_index)s_%(title)s.%(ext)s' _playlistLink_
```

Manual filename modification: 
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ --replace-in-metadata "playlist" "[ /]" "_" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s' _playlistLink_ 
```

# Download a single youtube music 

No filename modification: 
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ -o 'music/%(title)s.%(ext)s' _link_
```

Automatic filename modification:
```bash
yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P ./ --restrict-filenames -o 'music/%(title)s.%(ext)s' _link_
```

# Download video and audio separately using yt-dlp and then merge them into one file using ffmpeg

```bash
yt-dlp -f _value_ _link_
```

```bash
ffmpeg -i _inputVideoMP4_ -i _inputAudioM4A_  -c:v copy -c:a aac -strict experimental _outputVideoMP4_
```
