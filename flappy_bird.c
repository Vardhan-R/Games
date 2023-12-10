#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define RESET "\x1B[0m"
#define BLK "\x1B[30m"
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"

void updatePipes(int* p_arr, int, int, int);

int main() {
    float g = 0.1, vel = 0;
    int width = 64, height = 100, running = 1, pipes_on_scrn = 5, t = 20, tm = 0, c;
    float pos = height / 2;
    int pipes[pipes_on_scrn][3];
    // disp_arr[height][width]; // {x, top, bottom}, [row][col]
    time_t t_0;

    srand((unsigned) time(&t_0));

    pipes[4][0] = width / 2;
    pipes[4][1] = rand() % (height - 3 * t - 1) + t; // min = t; max = height - 2 * t
    pipes[4][2] = rand() % (height - 2 * t - pipes[4][1]) + pipes[4][1] + t; // [0][1] + t to height - t
    for (int i = 0; i < 4; i++) {
        updatePipes(&pipes[0][0], width, height, t);
    }
    // pipes[1][0] = 3 * width / 4;
    // pipes[1][1] = rand() % (height - 3 * t - 1) + t; // min = t; max = height - 2 * t
    // pipes[1][2] = rand() % (height - 2 * t - pipes[1][1]) + pipes[1][1] + t; // [1][1] + t to height - t
    // pipes[2][0] = width;
    // pipes[2][1] = rand() % (height - 3 * t - 1) + t; // min = t; max = height - 2 * t
    // pipes[2][2] = rand() % (height - 2 * t - pipes[2][1]) + pipes[2][1] + t; // [2][1] + t to height - t
    // pipes[3][0] = 5 * width / 4;
    // pipes[3][1] = rand() % (height - 3 * t - 1) + t; // min = t; max = height - 2 * t
    // pipes[3][2] = rand() % (height - 2 * t - pipes[3][1]) + pipes[3][1] + t; // [3][1] + t to height - t

    while (running) {
        // check for input
        if (GetAsyncKeyState(0x20) & 0x01) {
            vel = -5;
        }

        // update vel
        vel += g;

        // update pos
        pos += vel;

        // update pipes
        for (int i = 0; i < pipes_on_scrn; i++) {
            pipes[i][0]--;
        }
        tm = (tm + 1) % (width / 4);
        if (!tm) {
            updatePipes(&pipes[0][0], width, height, t);
        }

        // collision detection
        for (int i = 0; i < 2; i++) {
            if ((pipes[i][0] <= width / 4 + t / 2) && (pipes[i][0] + t >= width / 4) && ((pos <= pipes[i][1]) || (pos + t / 2 >= pipes[i][2]))) {
                running = 0;
                break;
            }
        }

        // display
        for (int i = 0; i < height; i++) { // row
            for (int j = 0; j < width; j++) { // col
                c = 1;
                for (int k = 0; k < pipes_on_scrn; k++) {
                    if (((i <= pipes[k][1]) || (i >= pipes[k][2])) && (j >= pipes[k][0]) && (j <= pipes[k][0] + t)) {
                        // disp_arr[i][j] = 2;
                        printf(GRN "%c%c", 219, 219);
                        c = 0;
                        break;
                    }
                }
                if (c) {
                    if ((i >= pos) && (i <= pos + t / 2) && (j >= width / 4) && (j <= width / 4 + t / 2)) {
                        // disp_arr[i][j] = 1;
                        printf(RED "%c%c", 219, 219);
                    } else {
                        // disp_arr[i][j] = 0;
                        printf(RESET "%c%c", 219, 219);
                    }
                }
            }
            printf("\n");
        }

        // for (int i = 0; i < pipes_on_scrn; i++) {
        //     x = 0;
        //     for (int j = x; j < pipes[i][0]; j++) {
        //         printf(RESET "%c", 219);
        //     }
        //     for (int j = (pipes[i][0] > 0 ? pipes[i][0] : 0); j < pipes[i][0] + t; j++) {
        //         printf(GRN "%c", 219);
        //     }
        // }
        printf("\n");
    }

    return 0;
}

void updatePipes(int* p_arr, int width, int height, int t) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            *(p_arr + 4 * i + j) = *(p_arr + 4 * (i + 1) + j);
        }
    }
    *(p_arr + 12) = *(p_arr + 8) + width / 4;
    *(p_arr + 13) = rand() % (height - 3 * t - 1) + t;
    *(p_arr + 14) = rand() % (height - 2 * t - *(p_arr + 13)) + *(p_arr + 13) + t;
}

// check for input
// update vel
// update pos
// collision detection
// display