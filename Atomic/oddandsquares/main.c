#include <stdio.h>

int main () {
    unsigned int x = 0;
    int odd = 1;
    printf("atomic bomb project\n");
    printf("40^2 : %d\n", 40*40);

    for (int i = 0; i < 40; i++) {
        x += odd;
        odd += 2;
    }

    printf("x = %d\n", x);
    return 0;
}
