#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Vector {
    int x, y, z;
} Vector;

int main() {
    Vector pos, vel;

    time_t t_0;

    srand((unsigned) time(&t_0));

    printf("%d\n", rand() % 10);

    int arr[15] = {0}, t = 0, t_max = pow(10, 3), n = 0, n_max = 5, jump = 0, jump_tm = 0, jump_tm_max = 3;
    for (int i = 0; i < 3; i++) {
            arr[5 * i + 4] = rand() % 2;
    }

    while (1) {
        // check for input
        if (GetAsyncKeyState(0x20) & 0x1) {
            jump = 1;
        }

        if (!t) {
            // collision
            if (arr[0] && !jump) {
                break;
            }

            // l_shift arr
            for (int i = 0; i < 14; i++) {
                arr[i] = arr[i + 1];
            }
            arr[14] = 0;

            if (!n) {
                arr[14] = rand() % 2;
                // arr[14] = 1;
            }
            n = (n + 1) % n_max;

            if (jump) {
                jump_tm = (jump_tm + 1) % jump_tm_max;
            }
            if (!jump_tm) {
                jump = 0;
            }
        }

        if (jump) {
            printf("%c\n ", 219);
        }
        else {
            printf("\n%c", 219);
        }
        for (int i = 0; i < 15; i++) {
            printf("%c", 187 * arr[i] + 32);
        }
        printf("\n\n");

        t = (t + 1) % t_max;
    }

    return 0;
}