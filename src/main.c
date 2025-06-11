#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "grid.h"
#include "mc.h"
#include "calc.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    generate_grid();
    save_to_file("ice_grid_0.dat");

    FILE* f_out = fopen("quantities.dat", "w");
    if (!f_out) {
        perror("Can't open quantities file");
        return 1;
    }

    fprintf(f_out, "Step\tEntropy\tMagnetization\n");


    // simple command line argument handling

    int use_long_loop = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "-ll") == 0 || strcmp(argv[1], "--long-loop") == 0) {
            use_long_loop = 1;
        } else if (strcmp(argv[1], "-sl") == 0 || strcmp(argv[1], "--short-loop") == 0) {
            use_long_loop = 0;
        } else{
            fprintf(stderr, "Usage: %s [-ll | --long-loop] [-sl | --short-loop]\n", argv[0]);
            return 1;
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (use_long_loop) {
            long_loop_step();
        } else {
            short_loop_step();
        }

        if (i % 100 == 0) {
            double entropy = compute_entropy();
            double magnetization = compute_magnetization();
            fprintf(f_out, "%d\t%.6f\t%.6f\n", i, entropy, magnetization);
            printf("Step %d: Entropy = %.6f, Magnetization = %.6f\n", i, entropy, magnetization);
        }
    }


    save_to_file("ice_grid_2.dat");
    return 0;

}
