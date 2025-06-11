#include <stdlib.h>
#include <math.h>
#include "calc.h"
#include "grid.h"


double compute_entropy() {
    int counts[6] = {0}; // Count occurrences of each vertex type
    int total = 0; // Total number of vertices

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Vertex v = get_vertex(i, j);
            int type = get_vertex_type(v);
            if (type >= 0) {
                counts[type]++;
                total++;
            }
        }
    }

    double entropy = 0.0;
    for (int i = 0; i < 6; i++) {
        if (counts[i] > 0) {
            double p = (double)counts[i] / total;
            entropy -= p * log(p);
        }
    }

    return entropy;
}


double compute_magnetization() {

    double magnetization = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Vertex v = get_vertex(i, j);
            magnetization += abs(v.up) + abs(v.down) + abs(v.left) + abs(v.right);
        }
    }

    return magnetization / (double)(N*N);
}
