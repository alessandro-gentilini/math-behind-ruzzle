
/*	graph.c         

	A generic adjacency list graph data type.

	by: Steven Skiena
	begun: March 6, 2002

*/

/*
Copyright 2003 by Steven S. Skiena; all rights reserved. 

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/


#include <stdio.h>
#include "graph.h"
#include <cstdlib>

void insert_edge(graph *g, int x, int y, bool directed);

void initialize_graph(graph *g, bool directed)
{
	int i;				/* counter */

	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;

	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
	for (i=1; i<=MAXV; i++) g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
	int i;				/* counter */
	int m;				/* number of edges */
	int x, y;			/* vertices in edge (x,y) */

	initialize_graph(g, directed);

	scanf("%d %d",&(g->nvertices),&m);

	for (i=1; i<=m; i++) {
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p;			/* temporary pointer */

	p = (edgenode *)malloc(sizeof(edgenode));	/* allocate storage for edgenode */

	p->weight = 0;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;		/* insert at head of list */

	g->degree[x] ++;

	if (directed == false)
		insert_edge(g,y,x,true);
	else
		g->nedges ++;
}


void delete_edge(graph *g, int x, int y, bool directed)
{
	int i;				/* counter */
	edgenode *p, *p_back;		/* temporary pointers */

	p = g->edges[x];
	p_back = NULL;

	while (p != NULL) 
		if (p->y == y) {
			g->degree[x] --;
			if (p_back != NULL) 
				p_back->next = p->next;
			else
				g->edges[x] = p->next;

			free(p);

			if (directed == false)
				delete_edge(g,y,x,true);
			else
				g->nedges --;

			return;
		}
		else
			p = p->next;

	printf("Warning: deletion(%d,%d) not found in g.\n",x,y);
}


void print_graph(graph *g)
{
	int i;				/* counter */
	edgenode *p;			/* temporary pointer */

	for (i=1; i<=g->nvertices; i++) {
		fprintf(stderr,"%d: ",i);
		p = g->edges[i];
		while (p != NULL) {
			fprintf(stderr," %d",p->y);
			p = p->next;
		}
		fprintf(stderr,"\n");
	}
}

class Couple
{
public:
	int a,b;
	Couple(int aa,int bb):a(aa),b(bb){}
	bool operator==(const Couple& rhs ) const
	{
		return (a==rhs.a && b==rhs.b) || (a==rhs.b && b==rhs.a);
	}
};

#include <vector>
#include <algorithm>

void print_graph_dot_4x4(graph *g)
{
	int i;				/* counter */
	edgenode *p;			/* temporary pointer */

char preamble[]=R"(
graph
{
13 [pos = "0,0!"]

14 [pos = "1,0!"]

15 [pos = "2,0!"]

16 [pos = "3,0!"]

9 [pos = "0,1!"]

10 [pos = "1,1!"]

11 [pos = "2,1!"]

12 [pos = "3,1!"]

5 [pos = "0,2!"]

6 [pos = "1,2!"]

7 [pos = "2,2!"]

8 [pos = "3,2!"]

1 [pos = "0,3!"]

2 [pos = "1,3!"]

3 [pos = "2,3!"]

4 [pos = "3,3!"])";

printf("%s\n\n", preamble );


std::vector<Couple> couples;

	for (i=1; i<=g->nvertices; i++) {
		p = g->edges[i];
		while (p != NULL) {
			//printf("%d -- %d\n",i,p->y);
			Couple c(i,p->y);
			if ( std::find(couples.begin(),couples.end(),c) == couples.end() ) {
				couples.push_back(c);
			}
			p = p->next;
		}
		//printf("\n");
	}

	for ( size_t i = 0; i < couples.size(); i++ ) {
		printf("%d -- %d\n",couples[i].a,couples[i].b);
	}

	printf("}\n");
}

void print_graph_dot_2x2(graph *g)
{
	int i;				/* counter */
	edgenode *p;			/* temporary pointer */

char preamble[]=R"(
graph
{
3 [pos = "0,2!"]

4 [pos = "1,2!"]

1 [pos = "0,3!"]

2 [pos = "1,3!"])";


printf("%s\n\n", preamble );


std::vector<Couple> couples;

	for (i=1; i<=g->nvertices; i++) {
		p = g->edges[i];
		while (p != NULL) {
			//printf("%d -- %d\n",i,p->y);
			Couple c(i,p->y);
			if ( std::find(couples.begin(),couples.end(),c) == couples.end() ) {
				couples.push_back(c);
			}
			p = p->next;
		}
		//printf("\n");
	}

	for ( size_t i = 0; i < couples.size(); i++ ) {
		printf("%d -- %d\n",couples[i].a,couples[i].b);
	}

	printf("}\n");
}

