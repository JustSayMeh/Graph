#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

Graph *new_graph(int V)
{
	Graph *g = calloc(1, sizeof(Graph));
	g->verticles = calloc(V, sizeof(Verticle));
	g->V = V;
	for (int i = 0 ; i < V; i++)
		g->verticles[i].r_size = std_sz;
	return g;
}

int addVerticle(Verticle *v, int x)
{
	if (v->ribs_c == v->r_size)
		return 1;
	v->ribs[v->ribs_c] = x;
	v->ribs_c += 1;
	return 0;
}

int addEdge(Graph *g, int w , int x)
{
	addVerticle(g->verticles + w, x);
	addVerticle(g->verticles + x, w);
	g->E += 1;
	return 0;
}

Graph *build_graph(char *i)
{
	int V, E, w, x;
	FILE *in = fopen(i, "r");
	fscanf(in, "%d%d", &V, &E);
	Graph *g = new_graph(V);
	for (int i = 0; i < E; i++)
	{
		fscanf(in, "%d%d", &w, &x);
		addEdge(g, w, x);
	}
	fclose(in);
	return g;
} 