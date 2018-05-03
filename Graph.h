#include <stdlib.h>
#include <stdio.h>
#define std_sz 4
typedef struct _verticle{
	int ribs_c, r_size;
	int ribs[std_sz];
} Verticle;
typedef struct _graph{
	int V, E;
	Verticle *verticles;
} Graph;
Verticle *create_verticle();
Graph *new_graph(int );
int addVerticle(Verticle *, int );
int addEdge(Graph *, int  , int );
Graph *build_graph(char *);