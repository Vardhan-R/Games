#include <stdio.h>
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

void collision(float, float, float*, float);
void show(float, float, float*, float);
void update(float*, float*, float, float);

int main() {
    float width = 64, height = 35, g = 1, dt = 1, size = 5;
    float pos[2] = {width / 2, height / 3}, vel[2] = {0, 0}; // pos ==> top-left

    while (1) {
        collision(width, pos[1], &vel[0], size);
        update(&pos[0], &vel[0], g, dt);
        show(width, height, &pos[0], size);
    }

    return 0;
}

void collision(float w, float pos_y, float* vel, float s) {
    if (pos_y + s >= w) {
        *(vel + 1) *= -1;
    }
}

void show(float w, float h, float* pos, float s) {
    for (int i = 0; i < pos[1]; i++) {
        for (int j = 0; j < w; j++) {
            printf(WHT "%c%c", 219, 219);
        }
        printf("\n");
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < *(pos); j++) {
            printf(WHT "%c%c", 219, 219);
        }

        for (int j = 0; j < s; j++) {
            printf(RED "%c%c", 219, 219);
        }

        for (int j = *(pos) + s; j < w; j++) {
            printf(WHT "%c%c", 219, 219);
        }
        printf("\n");
    }

    for (int i = *(pos + 1) + s; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf(WHT "%c%c", 219, 219);
        }
        printf("\n");
    }

    printf("\n");
}

void update(float* pos, float* vel, float g, float dt) {
    *(vel + 1) += g * dt;
    *(pos + 1) += *(vel + 1) * dt;
}