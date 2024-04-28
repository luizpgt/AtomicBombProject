#!/bin/bash
echo "Do you want to download:"
echo "   [0]PLAYLIST"
echo "   [1]SINGLE MUSIC"

read OP

if [[ OP -ne 0 && OP -ne 1 ]]; then
    echo "Invalid operation!"
    exit 1
fi

echo "Enter your link:"
read LINK

if [[ OP -eq 0 ]]; then
    DWN_FILE_NAME=$(yt-dlp --flat-playlist --restrict-filenames --print playlist --replace-in-metadata "playlist" "[ /]" "_" $LINK | head -n 1)
    if [[ $DWN_FILE_NAME != _mu_* ]]; then
        DWN_FILE_NAME="_mu_${DWN_FILE_NAME}"
    fi
elif [[ OP -eq 1 ]]; then
    DWN_FILE_NAME=$(yt-dlp --print "%(title)s.mp3" $LINK)
fi

echo $DWN_FILE_NAME

#yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P LINK --replace-in-metadata "playlist" "[ /]" "_" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'


