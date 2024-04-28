#include <stdio.h>
#define PATH_MAX 500

int main(void) {
    FILE *fp;
    int status;
    char path[PATH_MAX];

    fp = popen("ls *", "r");
    if (fp == NULL)
        return 0;
    while (fgets(path, PATH_MAX, fp) != NULL)
        printf("%s", path);
    status = pclose(fp);
    return 0;
}
