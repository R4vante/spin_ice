#ifndef UTILS_H
#define UTILS_H

#include "config.h"

void initialize_grid(int grid[L][L]);
void print_grid(int grid[L][L]);
int check_ice_rules(int grid[L][L], int i, int j);

#endif // !UTILS_H
