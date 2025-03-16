# Automating Image Download from URLs using JS + Python + wget

Get the list of image urls from a static page:

```js
copy($$('div.file a.fileThumb').map(a => a.href.startsWith('//') ? 'https:' + a.href : a.href))
```

Update on image_urls:

```python
import subprocess
import os
from datetime import datetime

# Get image_urls from browser's console:
# copy($$('div.file a.fileThumb').map(a => a.href.startsWith('//') ? 'https:' + a.href : a.href))

# List of image URLs 
image_urls = [
  "https://source.cdn.org/image.png",  
  "https://source.cdn.org/image.png",
  "https://source.cdn.org/image.png"
]

# Get the current date and time formatted as YYYY-MM-DD_HH-MM
current_time = datetime.now().strftime('%Y-%m-%d_%H-%M')

# Create a directory based on the current date and time
download_folder = f"imgdown/{current_time}"
os.makedirs(download_folder, exist_ok=True)  # Create the folder if it doesn't exist

print(f"Images will be saved in: {download_folder}")

# Iterate over each URL and download it using wget
for url in image_urls:
    print(f"Downloading: {url}")
    # Use wget with the -P option to specify the directory for saving
    subprocess.run(['wget', '-P', download_folder, url])
    print(f"Downloaded: {url}")

print("All downloads completed!")
```
