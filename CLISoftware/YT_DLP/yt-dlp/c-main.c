/*                  more info at bottom [normal-mode + G] */
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>

#define PATH \
  "/home/gokbuck/Videos/yt_dlp/music/"
#define DEVICE_ID \
  "06e8714dce2b3c2d"

// yt-dlp command 
#define HEAD \
  "yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P " PATH
#define PFILE_FORMAT \
  "--replace-in-metadata \"playlist\" \"[ /]\" \"_\" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'"
#define MFILE_FORMAT \
  "-o '_mu_noplaylist/%(title)s.%(ext)s'"

// kdeconnect command
#define KDE \
  "kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share " PATH 

void lsopt();
char *appendString(char *str, char *part);
int askCmdConfirmation(char *cmd);

int main (int argc, char **argv) {
  short int c;
  opterr = 0;
  char *url = NULL;

  printf("%s\n", HEAD);
  char *filep = PFILE_FORMAT;
  char *filem = PFILE_FORMAT;

  char *ytcommand = (char *)malloc(0*sizeof(char));
  char *kdecommand = (char *)malloc(0*sizeof(char));
  ytcommand = appendString(ytcommand, HEAD);
  ytcommand = appendString(ytcommand, PATH);

  while ((c = getopt (argc, argv, "hpml:")) != -1)
    switch (c)
      {
      case 'h':
        lsopt();
        return 0;
        break;
      case 'p':
        ytcommand = appendString(ytcommand, filep);
        break;
      case 'm':
        ytcommand = appendString(ytcommand, filem);
        break;
      case 'l':
        url = optarg;
        ytcommand = appendString(ytcommand, url); 
        break;
      case '?':
        if (optopt == 'l') fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt)) fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        return 1;
      default:
        abort ();
      }

  if (askCmdConfirmation(ytcommand)) {
    system(ytcommand);
    system(kdecommand);
  }
  return 0;
}

int askCmdConfirmation(char *cmd) {
  printf("COMMAND:\t%s\n\nProceed to download? [Y/n] ", cmd);
  fflush(stdout);
  if ((int)'n' == fgetc(stdin)) return 0;
  return 1;
}

char *appendString(char *str, char *part) {
  short int l = strlen(str) + strlen(part) + 1;
  printf("num len string: %hi\n", l);
  str = realloc(str, l++*sizeof(char));
  strcat(str, " ");
  strcat(str, part);
  return str;
}

void lsopt() {
  puts("usage: ./main.out [options] -l [url]");
  puts("[options]: \tgeneral options:");
  puts("\t\t-h\t\tprint this help text and exit.");
  puts("\t\t-p\t\tto download multiple videos from a playlist as mp3.");
  puts("\t\t-m\t\tto download a single video as mp3.");
  puts("\t\t-t\t\t[default behaviour] saves a thumbnail to a file.");
  puts("\t\t-l [url]\t\t[must have] permits you to enter the url.");
}

/*
 * PROGRAM NAME: yt-dlp-helper
 * AUTHOR: luiz paulo grafetti terres - luizpgt
 *
 *  choosing options: 
 *  -h    : help                IMPLEMENTED
 *  -p    : playlist            IMPLEMENTED 
 *  -m    : single music        IMPLEMENTED
 *  -t    : thumbnail           DEFAULT
 *  -c    : custom path +(arg)
 *  -r    : restrict filename
 *  -l    : url +(arg)         IMPLEMENTED 
 *  -v    : video download (+ list all formats asks for format)
 *  -k    : send to device
 *
 *  06e8714dce2b3c2d
 *
 */
