# A complete, cross-platform solution to record, convert and stream audio and video.


Docs: [FFmpeg](https://www.ffmpeg.org/)

# Merge video and audio into one file using ffmpeg

```bash
ffmpeg -i _inputVideoMP4_ -i _inputAudioM4A_  -c:v copy -c:a aac -strict experimental _outputVideoMP4_
```