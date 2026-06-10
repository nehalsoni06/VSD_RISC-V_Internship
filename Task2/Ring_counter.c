#include <stdio.h>

int main() {

    int ring[4] = {1, 0, 0, 0};

    printf("Ring Counter Sequence:\n");

    for(int i = 0; i < 8; i++) {

        printf("%d%d%d%d\n",
               ring[0], ring[1],
               ring[2], ring[3]);

        int temp = ring[3];

        ring[3] = ring[2];
        ring[2] = ring[1];
        ring[1] = ring[0];
        ring[0] = temp;
    }

    return 0;
}
