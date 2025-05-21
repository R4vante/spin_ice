#include "config.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grid[L][L];

    srand(time(NULL));

    initialize_grid(grid);
    print_grid(grid);
    printf("%d", check_ice_rules(grid, 0, 0));


    return 0;
}
