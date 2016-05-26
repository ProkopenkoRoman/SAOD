#include <stdio.h>
#include "graph.h"
#include "binary_heap.h"

int main () {
    struct graph *g;
    g = graph_create(20);
    graph_set_edge(g, 1, 2, 3);
    graph_set_edge(g, 1, 7, 10);
    graph_set_edge(g, 1, 18, 3);
    graph_set_edge(g, 1, 20, 2);
    graph_set_edge(g, 2, 9, 4);
    graph_set_edge(g, 3, 18, 8);
    graph_set_edge(g, 4, 15, 7);
    graph_set_edge(g, 5, 11, 8);
    graph_set_edge(g, 5, 12, 7);
    graph_set_edge(g, 6, 17, 5);
    graph_set_edge(g, 7, 14, 3);
    graph_set_edge(g, 7, 17, 2);
    graph_set_edge(g, 8, 15, 9);
    graph_set_edge(g, 9, 10, 2);
    graph_set_edge(g, 10, 14, 11);
    graph_set_edge(g, 10, 15, 5);
    graph_set_edge(g, 11, 13, 4);
    graph_set_edge(g, 12, 13, 7);
    graph_set_edge(g, 12, 20, 1);
    graph_set_edge(g, 13, 18, 1);
    graph_set_edge(g, 16, 19, 5);
    graph_set_edge(g, 17, 19, 6);
    graph_set_edge(g, 19, 20, 4);
    
    int *prev = malloc(g->nvertices * sizeof(int));
    int *d = malloc(g->nvertices * sizeof(int));
    int i, j;
    struct g_path *path;
    
    for (i = 2; i <= g->nvertices; i++) {
		printf("Min path from 1 to %d\n", i);
		path = Serch_Shortest_Path(g, 1, i);
		printf("partlen: %d\n", path->pathlen);
		printf("path ");
		for (j = 0; j <= path->edge; j++)
	    	printf("%d ", path->path[j]);
		printf("\n\n");
    }
    
    return 0;
}
