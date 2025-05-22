#ifndef GRID_H
#define GRID_H

#include "vertex.h"

#define N 10

extern Vertex grid[N][N];

void generate_grid();
void save_to_file(const char* filename);

#endif // !GRID_H
