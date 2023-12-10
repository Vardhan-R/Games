#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GRN "\x1B[32m"

int main() {
    int t = 0, pause_tm = 500000, size = 1, density = 20, collision = 0, c, f;
    int body[density * density][2], vel[2] = {0, -1}, food[2];
    time_t t_0;

    body[0][0] = body[0][1] = density / 2;

    srand((unsigned) time(&t_0));
    food[0] = rand() % density;
    food[1] = rand() % density;
    // food[0] = 3;
    // food[1] = 5;

    while (!collision) {
        // check for input
        if (GetAsyncKeyState(0x57) & 0x01) {
            if (vel[0]) {
                vel[0] = 0;
                vel[1] = -1;
            }
        } else if (GetAsyncKeyState(0x41) & 0x01) {
            if (vel[1]) {
                vel[0] = -1;
                vel[1] = 0;
            }
        } else if (GetAsyncKeyState(0x53) & 0x01) {
            if (vel[0]) {
                vel[0] = 0;
                vel[1] = 1;
            }
        } else if (GetAsyncKeyState(0x44) & 0x01) {
            if (vel[1]) {
                vel[0] = 1;
                vel[1] = 0;
            }
        }

        if (!t) {
            // if (m == 5) {
            //     vel[0] = -1;
            //     vel[1] = 0;
            // }
            // else if (m == 13) {
            //     vel[0] = 0;
            //     vel[1] = 1;
            // }

            // move snake
            for (int i = size - 1; i > 0; i--) {
                body[i][0] = body[i - 1][0];
                body[i][1] = body[i - 1][1];
            }
            body[0][0] = (body[0][0] + vel[0]) % density;
            if (body[0][0] < 0) {
                body[0][0] += density;
            }
            body[0][1] = (body[0][1] + vel[1]) % density;
            if (body[0][1] < 0) {
                body[0][1] += density;
            }

            // collision detection
            collision = 0;
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (body[i][0] == body[j][0] && body[i][1] == body[j][1]) {
                        collision = 1;
                        break;
                    }
                }
                if (collision) {
                    break;
                }
            }
            // for (int i = 0; i < (size - 3) * size / 2; i++) {
            //     if (body[i / (size - 1)][0] == body[i % size][0] && body[i / (size - 1)][1] == body[i % size][1]) {
            //         collision = 1;
            //         break;
            //     }
            // }

            // food detection
            if (body[0][0] == food[0] && body[0][1] == food[1]) {
                body[size][0] = body[0][0];
                body[size][1] = body[0][1];
                size++;
                food[0] = rand() % density;
                food[1] = rand() % density;
            }

            // display
            f = 1;
            for (int i = 0; i < density; i++) {
                for (int j = 0; j < density; j++) {
                    if (f && food[0] == j && food[1] == i) {
                        // printf(",");
                        printf(RED "%c%c" RESET, 219, 219);
                        f = 0;
                        continue;
                    }
                    c = 1;
                    for (int k = 0; k < size; k++) {
                        if (body[k][0] == j && body[k][1] == i) {
                            // printf(".");
                            printf(GRN "%c%c" RESET, 219, 219);
                            c = 0;
                            break;
                        }
                    }
                    if (c) {
                        // printf("-");
                        printf("%c%c", 219, 219);
                    }
                }
                printf("\n");
            }
            printf("\n");
            // m++;
        }
        t = (t + 1) % pause_tm;
    }

    return 0;
}

// check for input
// food detection
// move snake
// collision detection
// display
// update "t"