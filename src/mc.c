#include <stdio.h>
#include <stdlib.h>
#include "mc.h"

void short_loop_step() {
    // 1. Kies random startvertex
    int x = rand() % N;
    int y = rand() % N;
    int start_x = x, start_y = y;

    // 2. Init
    int exclude_dir = -1; // 0=up, 1=right, 2=down, 3=left

    // 3. Loop
    while (1) {
        // 4. Bepaal pijlen bij vertex
        int up_i    = MOD(x - 1, N);
        int down_i  = MOD(x + 1, N);
        int left_j  = MOD(y - 1, N);
        int right_j = MOD(y + 1, N);

        // 5. Kijk naar outgoing edges (waar wijst pijl van vertex AF)
        int dirs[4];
        int n_out = 0;

        // UP edge
        if (exclude_dir != 0 && v[up_i][y] == -1) {
            dirs[n_out] = 0;
            n_out++;
        }

        // RIGHT edge
        if (exclude_dir != 1 && h[x][y] == 1) {
            dirs[n_out] = 1;
            n_out++;
        }

        // DOWN edge
        if (exclude_dir != 2 && v[x][y] == 1) {
            dirs[n_out] = 2;
            n_out++;
        }

        // LEFT edge
        if (exclude_dir != 3 && h[x][left_j] == -1) {
            dirs[n_out] = 3;
            n_out++;
        }

        // 6. Random kies 1 outgoing edge
        if (n_out == 0) {
            // fail-safe, kan eigenlijk niet
            printf("ERROR: No outgoing edge!\n");
            break;
        }

        int idx = rand() % n_out;
        int chosen_dir = dirs[idx];

        // 7. Flip de gekozen edge
        if (chosen_dir == 0) {
            // UP → flip v[up_i][y]
            v[up_i][y] *= -1;
            x = up_i;
            exclude_dir = 2; // exclude DOWN next
        }
        else if (chosen_dir == 1) {
            // RIGHT → flip h[x][y]
            h[x][y] *= -1;
            y = right_j;
            exclude_dir = 3; // exclude LEFT next
        }
        else if (chosen_dir == 2) {
            // DOWN → flip v[x][y]
            v[x][y] *= -1;
            x = down_i;
            exclude_dir = 0; // exclude UP next
        }
        else if (chosen_dir == 3) {
            // LEFT → flip h[x][left_j]
            h[x][left_j] *= -1;
            y = left_j;
            exclude_dir = 1; // exclude RIGHT next
        }

        // 8. Check of we terug bij start zijn
        if (x == start_x && y == start_y) {
            break;
        }
    }
}

