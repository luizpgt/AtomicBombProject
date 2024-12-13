/*                  more info at bottom [normal-mode + G] */
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>

#define HEAD \
  "yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail" 
#define PATH \
  "-P /home/gokbuck/Videos/yt_dlp/music/"
#define PFILE_FORMAT \
  "--replace-in-metadata \"playlist\" \"[ /]\" \"_\" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'"
#define MFILE_FORMAT \
  "-o '_mu_noplaylist/%(title)s.%(ext)s'"

void lsopt();
char *appendString(char *str, char *part);
int askCmdConfirmation(char *cmd);

int main (int argc, char **argv) {
  int c;
  opterr = 0;
  char *url = NULL;

  char *command = (char *)malloc(0*sizeof(char));
  command = appendString(command, HEAD);
  command = appendString(command, PATH);
  char const *target_directory;
  char const *target_phone;
  while ((c = getopt (argc, argv, "p:f:")) != -1)
    switch (c)
      {
      case 'p':
        target_phone = optarg;       
        printf("%ld", sizeof(target_phone));
        printf(target_phone);
        break;
      case 'f':
        target_directory = optarg;       
        printf(target_directory);
        break;
      default:
        abort ();
      }

  if (askCmdConfirmation(command))
    system(command);
  return 0;
}

int askCmdConfirmation(char *cmd) {
  printf("COMMAND:\t%s\n\nProceed to download? [Y/n] ", cmd);
  fflush(stdout);
  if ((int)'n' == fgetc(stdin))
    return 0;
  return 1;
}

char *appendString(char *str, char *part) {
  unsigned short int l = strlen(str) + strlen(part) + 1;
  str = realloc(str, l*sizeof(char));
  strcat(str, " ");
  l++;
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
