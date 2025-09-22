# How to remove metadata from video 

---

### Video Metadata – Summary

* **Hidden data in videos**: Besides audio/video, files may include metadata (title, author, GPS, timestamps), subtitles, attachments, or unused streams.

* **Remove metadata**:

  * With `ffmpeg`:

    ```bash
    ffmpeg -i in.mp4 -map 0:v -map 0:a -c copy -map_metadata -1 out.mp4
    ```

    Keeps only audio/video, strips metadata.
  * Full re-encode if you want to guarantee clean file.
  * For MKV: use `mkvpropedit --delete-attachments`.

* **Extract metadata**:

  * `ffprobe -show_format -show_streams -print_format json file.mp4` → technical + stream info.
  * `exiftool file.mp4` → full metadata, including GPS/author/device if present.
  * `mediainfo file.mp4` → summary view.

* **Your sample output (ffprobe)**:

  * Only technical info (codec, resolution, bitrate).
  * Generic handler names and encoder tag.
  * No author, no GPS, no personal info.
  * Filename (`bigtilo`) is outside metadata, just the file name.

* **Extra safety**:

  * Use `exiftool` to double-check hidden tags:

    ```bash
    exiftool -Author -Creator -Make -Model -Location -GPS* -CreationDate file.mp4
    ```
  * Exiftool can also remove all tags if needed.

---

Would you like me to also add the **one-liner exiftool command to wipe all metadata** so it’s in your notes for future use?

Great — here’s the one-liner you can keep in your notes:

```bash
exiftool -all= file.mp4
```

* `-all=` → removes **all metadata tags**.
* Creates a new cleaned copy named `file.mp4_original` (Exiftool’s default backup).
* If you don’t want the backup:

```bash
exiftool -all= -overwrite_original file.mp4
```

---

👉 That, together with the `ffmpeg` command, gives you two safe ways to strip metadata.

