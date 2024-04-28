#include <stdio.h>
#include <string.h>

int main (void) {
    char palavra[] = "AtomicBombProject";
    char *teste;
    teste = strdup(palavra);
    printf("%s\n", teste);
    return 0;
}
