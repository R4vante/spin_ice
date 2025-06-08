#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

int h[N][N+1];
int v[N+1][N];

Vertex get_vertex(int i, int j) {
    Vertex vtx;

    // Up pijl tussen (i,j) en (i-1,j)
    if (i == 0)
        vtx.up = -1; // randconditie (of periodic mogelijk)
    else
        vtx.up = (v[i-1][j] == 1) ? 0 : 1;

    // Down pijl tussen (i,j) en (i+1,j)
    if (i == N)
        vtx.down = -1;
    else
        vtx.down = (v[i][j] == 1) ? 1 : 0;

    // Left pijl tussen (i,j) en (i,j-1)
    if (j == 0)
        vtx.left = -1;
    else
        vtx.left = (h[i][j-1] == 1) ? 0 : 1;

    // Right pijl tussen (i,j) en (i,j+1)
    if (j == N)
        vtx.right = -1;
    else
        vtx.right = (h[i][j] == 1) ? 1 : 0;

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
            fprintf(f, "%d%d%d%d ",
            (vtx.up >= 0) ? vtx.up : 0,
            (vtx.right >= 0) ? vtx.right : 0,
            (vtx.down >= 0) ? vtx.down : 0,
            (vtx.left >= 0) ? vtx.left : 0);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}
