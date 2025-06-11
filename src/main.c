#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "grid.h"
#include "mc.h"
#include "calc.h"

int main() {
    srand(time(NULL));
    generate_grid();
    save_to_file("ice_grid_0.dat");

    FILE* f_out = fopen("quantities.dat", "w");
    if (!f_out) {
        perror("Can't open quantities file");
        return 1;
    }

    fprintf(f_out, "Step\tEntropy\tMagnetization\n");

    /* for (int i = 0; i < 100000; i++) { */
    /*     short_loop_step(); */
    /**/
    /*     if (i % 100 == 0) { */
    /*         double entropy = compute_entropy(); */
    /*         double magnetization = compute_magnetization(); */
    /*         fprintf(f_out, "%d\t%.6f\t%.6f\n", i, entropy, magnetization); */
    /*         printf("Step %d:\tEntropy = %.6f\tMagnetization = %.6f\n", i, entropy, magnetization); */
    /*     } */
    /**/
    /* } */
    /* save_to_file("ice_grid_1.dat"); */


    for (int i = 0; i < 100000; i++) {
        long_loop_step();

        if (i % 100 == 0) {
            double entropy = compute_entropy();
            double magnetization = compute_magnetization();
            fprintf(f_out, "%d\t%.6f\t%.6f\n", i, entropy, magnetization);
            printf("Step %d:\tEntropy = %.6f\tMagnetization = %.6f\n", i, entropy, magnetization);
        }
    }
    save_to_file("ice_grid_2.dat");
    return 0;

}
