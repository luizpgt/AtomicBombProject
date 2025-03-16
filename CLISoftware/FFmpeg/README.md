# A complete, cross-platform solution to record, convert and stream audio and video.


Docs: [FFmpeg](https://www.ffmpeg.org/)

# Merge video and audio into one file using ffmpeg

```bash
ffmpeg -i _inputVideoMP4_ -i _inputAudioM4A_  -c:v copy -c:a aac -strict experimental _outputVideoMP4_
```

# Splitting MP4 with Same Quality

[More at: superuser.com](https://superuser.com/questions/140899/ffmpeg-splitting-mp4-with-same-quality)

Split from 0s to 50 mins from the original video:

```bash
ffmpeg -ss 00:00:00 -t 00:50:00 -i largefile.mp4 -acodec copy -vcodec copy smallfile.mp4
```

