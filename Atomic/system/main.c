#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://youtu.be/6v2rhgNFnLs
// kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share
// /home/gokbuck/Videos/yt_dlp/music/*
int main(int argc, char *argv[]) {
  int len = 114 + strlen(argv[1]);
  char cmd[len + 3];
  char path[len];

  // concatenate string
  strcpy(path, "~/Videos/yt_dlp/music/");
  // argv 1 : playlist link
  if (strlen(argv[1]) > 29) {
    snprintf(
        cmd, len + 3,
        "yt-dlp -f 'ba' -x --audio-format mp3 %s -P ~/Videos/yt_dlp/music/ -o "
        "'%%(playlist)s/%%(playlist_index)s - %%(title)s.%%(ext)s'",
        argv[1]);
  } else {
    strcpy(path, "~/Videos/yt_dlp/music/MISC");
    snprintf(cmd, len + 3,
             "yt-dlp -f 'ba' -x --audio-format mp3 %s -P "
             "~/Videos/yt_dlp/music/MISC/",
             argv[1]);
  }

  printf("ola mundo");
  printf("cmd :: %s\n", cmd);

  system(cmd);

  /*
  // send to device
  len = (87 - 28) + strlen(path);
  char cmdDevice[len];
  snprintf(cmdDevice, len,
           "kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share %s", path);
  system(cmdDevice);
  */
  // kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share
  // /home/gokbuck/Videos/yt_dlp/music/*
  return 0;
}
