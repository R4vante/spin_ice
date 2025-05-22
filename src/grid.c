#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

int h[N][N+1];
int v[N+1][N];

Vertex get_vertex(int i, int j) {
    Vertex vtx;
    vtx.up = v[i][j];
    vtx.down = v[i+1][j];
    vtx.left = h[i][j];
    vtx.right = h[i][j+1];
    return vtx;
}

int is_valid_vertex(Vertex v) {
    int in = v.up + v.left;
    int out = v.down + v.right;
    return (in == 1 && out == 1) || (in == 2 && out == 2);
}

const int valid_vertices[6][4] = {
    {1, 0, 0, 1}, // up, down, left, right
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1}
};


// grid.c (snippet)
void generate_grid() {
   for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            h[i][j] = 1; // right
        }
    }

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N; j++) {
            v[i][j] = 1; // up
        }
    }
}

void save_to_file(const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        perror("Fout bij openen bestand");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Vertex vtx = get_vertex(i, j);
            fprintf(f, "%d%d ", vtx.up, vtx.right);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
