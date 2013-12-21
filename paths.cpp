/*	
	paths.c
	Enumerate the paths in a graph via backtracking

	begun: August 1, 2006
	by: Steven Skiena
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

#include "graph.h"
#include "backtrack.h"
#include <stdio.h>

int solution_count;			/* how many solutions are there? */

graph g;				/* graph to traverse */

void process_solution(int a[], int k)
{
	int i;				/* counter */

	solution_count ++;

        printf("{");
        for (i=1; i<=k; i++)
                printf(" %d",a[i]);
        printf(" }\n");

}

bool is_a_solution(int a[], int k, int t)
{
	return (a[k] == t);
}

void make_move(int a[], int k, int n)
{
}

void unmake_move(int a[], int k, int n)
{
}


/*	What are possible elements of the next slot in the path
*/

int start_vertex;

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int i;				/* counters */
	bool in_sol[NMAX];		/* what's already in the solution? */
	edgenode *p;			/* temporary pointer */
	int last;			/* last vertex on current path */

        for (i=1; i<NMAX; i++) in_sol[i] = false;
	for (i=1; i<k; i++) in_sol[ a[i] ] = true;

	if (k==1) {			/* always start from vertex 1 */
		c[0] = start_vertex;
		*ncandidates = 1;
	}
	else	{
		*ncandidates = 0;
		last = a[k-1];
		p = g.edges[last];
		while (p != NULL) {
			if (!in_sol[ p->y ]) {
				c[*ncandidates] = p->y;
                        	*ncandidates = *ncandidates + 1;
			}
			p = p->next;
		}
	}
}

#include <iostream>

main()
{
    int a[NMAX];            /* solution vector */
    int i;              /* counter */

    read_graph(&g, false);
    print_graph_dot_5x5(&g);

/*
    for ( int c2 = 1; c2 <= 16; c2++ )
    {
        for ( int c1 = 1; c1 <= 16; c1++ )
        {
            //std::cout << c2 << " " << c1 << "\n";
            //std::cout << "Paths from " << c2 << " to " << c1 << ":\n";
            start_vertex = c2;
            backtrack(a, 0, c1);
        }
    }
    */

}

