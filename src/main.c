#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "mc.h"

int main() {
    srand(time(NULL));
    generate_grid();
    save_to_file("ice_grid_0.dat");

    for (int i = 0; i < 10000; i++) {
        short_loop_step();
    }
    save_to_file("ice_grid_1.dat");
    return 0;
}
