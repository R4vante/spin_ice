#ifndef GRID_H
#define GRID_H

#include "vertex.h"

#define N 10

#define MOD(a, b) (((a) + (b)) % (b))

extern int h[N][N];
extern int v[N][N];

Vertex get_vertex(int i, int j);
int is_valid_vertex(Vertex v);
void generate_grid();
void save_to_file(const char* filename);
int get_vertex_type(Vertex v);

#endif // !GRID_H
