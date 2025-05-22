#include <stdlib.h>
#include <time.h>
#include "grid.h"

int main() {
    srand(time(NULL));
    generate_grid();
    save_to_file("ice_grid.txt");
    return 0;
}
