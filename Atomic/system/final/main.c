#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH1 "/home/gokbuck/Videos/yt_dlp/music/$(yt-dlp --print filename --restrict-filenames -o '%(playlist)s/*' %s)" //sera passado o link para completar
#define PATH2 "/home/gokbuck/Videos/yt_dlp/music/MISC/$(yt-dlp --print filename --restrict-filenames -o '%(title)s.mp3' %s)"
#define YTDLP "yt-dlp -f 'ba' -x --audio-format mp3 %s -P ~/Videos/yt_dlp/music/ --restrict-filenames -o '%%(playlist)s/%%(playlist_index)s-%%(title)s.%%(ext)s'"
#define YTDLP2 "yt-dlp -f 'ba' -x --audio-format mp3 %s -P ~/Videos/yt_dlp/music/MISC/ --restrict-filenames -o '%%(title)s.%%(ext)s'"
#define KDEC "kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share "

/*
 * yt-dlp -f 'ba' -x --audio-format mp3 %s -P ~/Videos/yt_dlp/music/ -o '%%(playlist)s/%%(playlist_index)s - %%(title)s.%%(ext)s'
 * yt-dlp -f 'ba' -x --audio-format mp3 %s -P ~/Videos/yt_dlp/music/MISC/
 * kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share /home/user/Videos/yt_dlp/music/
 * yt-dlp --print filename -o '%(title)s.%(ext)s' https://youtu.be/ooooooooooo
 * yt-dlp --print filename -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s' https://youtu.be/ooooooooooo
 */

int main (int argc, char *argv[]) {
    int len_yt_dlp, len_path;
    char yt_dlp[500], kde_connect[300], path[200];
    int len_link = strlen(argv[1]);
    strcpy(kde_connect, KDEC);
    len_yt_dlp = strlen(argv[1]) + strlen(YTDLP);
    if (len_link > 26) { // caso playlist
        len_path = strlen(PATH1) + strlen(argv[1]);
        snprintf(path, len_path, PATH1, argv[1]);
        snprintf(yt_dlp, len_yt_dlp, YTDLP, argv[1]);
    } else { // caso musica simples
        len_path = strlen(PATH2) + strlen(argv[1]);
        snprintf(path, len_path, PATH2, argv[1]);
        snprintf(yt_dlp, len_yt_dlp, YTDLP2, argv[1]);
    }
    strcat(kde_connect, path); 
    system(yt_dlp);
//    system(kde_connect);
    return 0;
}
