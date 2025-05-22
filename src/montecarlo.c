// montecarlo.c
#include <stdlib.h>
#include "grid.h"

typedef struct {
    int x, y;
} VertexCoord;

void short_loop_step() {
    int x = rand() % N;
    int y = rand() % N;

    VertexCoord visited[N * N];
    int visited_count = 0;

    char exclude = 0; // 'L', 'R', 'U', 'D'

    while (1) {
        // Check of vertex al bezocht is
        for (int i = 0; i < visited_count; i++) {
            if (visited[i].x == x && visited[i].y == y) return; // loop gesloten
        }

        visited[visited_count++] = (VertexCoord){x, y};

        int l = (x > 0)     ? h[y][x]     : -2;
        int r = (x < N)     ? h[y][x + 1] : -2;
        int u = (y < N)     ? v[y][x]     : -2;
        int d = (y > 0)     ? v[y - 1][x] : -2;

        // Verzamel uitgaande pijlen
        int dirs[4] = {0}; // 1 = actief
        int num = 0;

        if (l == -1 && exclude != 'L') dirs[num++] = 'L';
        if (r == 1  && exclude != 'R') dirs[num++] = 'R';
        if (u == 1  && exclude != 'U') dirs[num++] = 'U';
        if (d == -1 && exclude != 'D') dirs[num++] = 'D';

        if (num == 0) return; // Geen geldige pijlen

        // Kies willekeurige richting
        char dir = dirs[rand() % num];

        // Flip pijl
        switch (dir) {
            case 'L':
                h[y][x] *= -1;
                x--;
                exclude = 'R';
                break;
            case 'R':
                h[y][x + 1] *= -1;
                x++;
                exclude = 'L';
                break;
            case 'U':
                v[y][x] *= -1;
                y++;
                exclude = 'D';
                break;
            case 'D':
                v[y - 1][x] *= -1;
                y--;
                exclude = 'U';
                break;
        }
    }
}

