#include <stdio.h>
#include <stdlib.h>
#include "mc.h"

void long_loop_step() {
    // 1. Pick a random starting vertex
    int x = rand() % N;
    int y = rand() % N;
    int start_x = x, start_y = y;   // // Save starting coordinates

    // 2. Init: prevent immediate backtracking
    int exclude_dir = -1; // 0=up, 1=right, 2=down, 3=left

    // 3. Loop
    while (1) {
        // 4. Determine indices of 4 neighboring vertices (periodic BC)
        int up_i    = MOD(x - 1, N);
        int down_i  = MOD(x + 1, N);
        int left_j  = MOD(y - 1, N);
        int right_j = MOD(y + 1, N);

        // 5. Collect all outgoing edges  (where does the arrow point AWAY from the vertex)
        int dirs[4];        // Array containing all outgoing edges (max 4)
        int n_out = 0;      // Number of outgoing edges

        // Check if edge goes outward, exclude the direction we just came from (no U-turns possible)

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

        if (n_out == 0) {
            // fail-safe, shouldn't be possible
            printf("ERROR: No outgoing edge in long loop!\n");
            break;
        }

        // 6. Randomly choose an outgoing edge
        int idx = rand() % n_out;
        int chosen_dir = dirs[idx];

        // 7. Perform the flip and move (x,y) according to the chosen outgoing edge
        // Modify exclude_dir depending on the chosen edge (no U-turns)
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

        // 8. Finish when the long loop is closed (i.e. when we are back at starting coordinates)
        if (x == start_x && y == start_y) {
            break;
        }
    }
}

void short_loop_step() {
    // Random start vertex (S0)
    int x = rand() % N;
    int y = rand() % N;
    int start_x = x, start_y = y;

    int exclude_dir = -1; // 0=up, 1=right, 2=down, 3=left

    // Preparing to save path
    // path_x[k], path_y[k] = vertex before step k
    // path_dir[k] = chosen direction at step k
    // Max N*N steps 
    int path_x[N*N], path_y[N*N], path_dir[N*N];
    int len = 0;

    while (1) {
        int up_i    = MOD(x - 1, N);
        int down_i  = MOD(x + 1, N);
        int left_j  = MOD(y - 1, N);
        int right_j = MOD(y + 1, N);

        // Collecting all outgoing edges (excl. U-turn)
        int dirs[4], n_out = 0;
        if (exclude_dir != 0 && v[up_i][y]   == -1) dirs[n_out++] = 0;  // UP
        if (exclude_dir != 1 && h[x][y]      ==  1) dirs[n_out++] = 1;  // RIGHT
        if (exclude_dir != 2 && v[x][y]      ==  1) dirs[n_out++] = 2;  // DOWN
        if (exclude_dir != 3 && h[x][left_j] == -1) dirs[n_out++] = 3;  // LEFT

        if (n_out == 0) {
            printf("ERROR: No outgoing edge in short loop!\n");
            return;
        }

        // Randomly choose outgoing edge
        int idx = rand() % n_out;
        int chosen_dir = dirs[idx];

        // Record step in the path
        path_x[len]   = x;
        path_y[len]   = y;
        path_dir[len] = chosen_dir;
        len++;

        // Flip chosen edge and move (x,y), update exclude_dir
        if (chosen_dir == 0) {        // UP
            v[up_i][y] *= -1;
            x = up_i;
            exclude_dir = 2;          
        }
        else if (chosen_dir == 1) {   // RIGHT
            h[x][y] *= -1;
            y = right_j;
            exclude_dir = 3;          
        }
        else if (chosen_dir == 2) {   // DOWN
            v[x][y] *= -1;
            x = down_i;
            exclude_dir = 0;         
        }
        else if (chosen_dir == 3) {   // LEFT 
            h[x][left_j] *= -1;
            y = left_j;
            exclude_dir = 1;          
        }

        // If we are back at starting coordinates -> loop was generated without crossing itself first
        // This routine then essentially did the same as the long loop
        if (x == start_x && y == start_y) {
            return;
        }

        // Check if we crossed this (x,y) point already (earlier in the path):
        // We search path_x[0...len-2], because  len-1 was just added to the path
        for (int i = 0; i < len-1; i++) {
            if (x == path_x[i] && y == path_y[i]) {
                // If the same point was found, the path crosses itself at Sl = path_x[i],path_y[i]
                int loop_start = i;
                // Retrace back from Sl to S0, flip edges again
                // So the path from S0->...->Sl is reverted back to original 
                for (int j = loop_start - 1; j >= 0; j--) {
                    int px = path_x[j];
                    int py = path_y[j];
                    int dir = path_dir[j];
                    int pi_up = MOD(px - 1, N);
                    int pj_left = MOD(py - 1, N);
                    // Flip edge for the second time
                    if      (dir == 0) {        // UP
                        v[pi_up][py] *= -1;
                    }
                    else if (dir == 1) {        // RIGHT
                        h[px][py] *= -1;
                    }
                    else if (dir == 2) {        // DOWN
                        v[px][py] *= -1;
                    }
                    else if (dir == 3) {        // LEFT
                        h[px][pj_left] *= -1;
                    }
                }

                return;
            }
        }
    }

}

