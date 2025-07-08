# Image Magick

[Docs: imagemagick.org](https://imagemagick.org/script/index.php)

ImageMagick® is a free, open-source software suite, used for editing and manipulating digital images. It can be used to create, edit, compose, or convert bitmap images, and supports a wide range of file formats, including JPEG, PNG, GIF, TIFF, and Ultra HDR.

- [Convert PDF to PNG high quality](README.md#convert-pdf-to-png-high-quality)

# Convert PDF to PNG high quality

---
Of course. To convert a PDF to a high-quality PNG using the ImageMagick command-line tool in Linux, the key is to specify a high density (DPI) *before* reading the input file.

Here is the recommended command:

```bash
magick -density 300 input.pdf -quality 100 output.png
```

### Breakdown of the Command

  * `magick`: The core ImageMagick command for conversions.
  * `-density 300`: This is the most important option for quality. It sets the dots per inch (DPI) to 300, which is a standard resolution for high-quality printing. ImageMagick's default is 72 DPI, which would result in a low-resolution, pixelated image. You must place this *before* the input PDF file.
  * `input.pdf`: The path to your source PDF file.
  * `-quality 100`: For PNG (a lossless format), this parameter controls the compression level. 100 means less compression, which can result in a larger file size but ensures maximum fidelity.
  * `output.png`: The name of the output PNG file.

-----

### Converting a Specific Page

If your PDF has multiple pages, the command above will create a sequence of images (`output-0.png`, `output-1.png`, etc.). To convert only a single page (for example, the first page), specify the page number in brackets (remembering that pages are zero-indexed):

```bash
magick -density 300 input.pdf[0] -quality 100 output_page_1.png
```

### Tips for Best Results

  * **For even higher quality:** If you need archival or ultra-high quality, you can increase the density further (e.g., `-density 600`). Be aware this will significantly increase the image dimensions and file size.
  * **Trimming whitespace:** If your PDF has large margins, you can add the `-trim` option to automatically crop the surrounding whitespace from the image.
    ```bash
    magick -density 300 input.pdf[0] -quality 100 -trim output_trimmed.png
    ```
  * **Transparency:** If your PDF has a transparent background that you want to preserve, ensure your version of ImageMagick supports it. If you want to flatten it against a white background (which is more common), add the `-flatten` option.
