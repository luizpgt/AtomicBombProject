#include <stdio.h>
#include <stdlib.h>

int main(){
  char path[1053];
  FILE *fp = popen("ls -l", "r");
  while (fgets(path, sizeof(path), fp) != NULL) printf("%s", path);
  return 0;
}
