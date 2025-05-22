#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

Vertex grid[N][N];

const Vertex allowed[6] = {
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 0}
};


void generate_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pick = rand() % 6;
            grid[i][j] = allowed[pick];
        }
    }
}

void save_to_file(const char* filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("File could not be opened");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(f, "%d%d%d%d ", grid[i][j].up, grid[i][j].down, grid[i][j].left, grid[i][j].right);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
