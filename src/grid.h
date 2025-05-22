#ifndef GRID_H
#define GRID_H

#include "vertex.h"

#define N 10

extern int h[N][N+1];
extern int v[N+1][N];

Vertex get_vertex(int i, int j);
int is_vallid_vertex(Vertex v);
void generate_grid();
void save_to_file(const char* filename);

#endif // !GRID_H
