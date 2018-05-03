#include <stdio.h>
#include "Graph.h"
#include <string.h>
#define T int
#include "C:\Users\user\collections\LABS_PMI\templates\stack_t.h"
int process(Graph *, int **);
int Kuhn(int , Graph *, int *, int *);
int process(Graph *g,  int **ret)
{
	int th, wcount = 0, i, j = 1,
	*consum = calloc(g->V, sizeof(int)),
	*marked = malloc(g->V * sizeof(int));
	stack_int *stack = new_stack_int();
	stack_int *white = new_stack_int();
	push_int(stack, 0);
	consum[0] = 1;
	while(!is_stack_empty_int(stack))
	{
		pop_int(stack, &th);
		if (consum[th] == 1)
		{
			push_int(white, th);
			wcount += 1;
		}
		for (int i = 0; i < g->verticles[th].ribs_c; i++)
		{
			int index = g->verticles[th].ribs[i];
			if (!consum[index])
			{
				push_int(stack, index);
				consum[index] = -consum[th];
			}
		}
	}
	if (g->V - 2 * wcount == 0)
	{
		j = 0;
		memset(consum, -1, g->V * sizeof(int));
		while (!is_stack_empty_int(white))
		{
			pop_int(white, &i);
			memset(marked, 0, g->V * sizeof(int));
			Kuhn(i, g, consum, marked);
		}
	}
	*ret = consum;
	free(marked);
	clear_int(stack);
	clear_int(white);
	return j;
}


int Kuhn(int thi, Graph *g, int *path, int *marked)
{
	if (marked[thi])
		return 0;
	marked[thi] = 1;
	for (int i = 0; i < g->verticles[thi].ribs_c; i++)
	{
		int index = g->verticles[thi].ribs[i];
		if (path[index] == -1 || Kuhn(path[index], g, path, marked))
		{
			path[index] = thi;
			return 1;
		}
	}
	return 0;
}