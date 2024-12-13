# Downsize all JPG images on a folder

Decrease the size of all jpg images inside a folder (maintaining the original files alongsize).

All new files named: `[original name]_mod.jpg`

```bash
#!/bin/bash

# Check if the directory is provided as an argument
# if [ "$#" -ne 1 ]; then
#     echo "Usage: $0 <directory>"
#     exit 1
# fi

# Navigate to the specified directory
# cd "$1" || { echo "Directory not found"; exit 1; }

# Loop through all JPEG images in the directory
for img in *.jpg; do
    # Check if any JPEG files exist
    if [ "$img" != "*.jpg" ]; then
        # Construct the output filename
        output="${img%.jpg}_mod.jpg"

        # Apply the ImageMagick command
        magick "$img" -strip -interlace Plane -gaussian-blur 0.05 -quality 85% "$output"

        echo "Processed: $img -> $output"
    else
        echo "No JPEG files found in the directory."
    fi
done
```

