/*
	backtrack.h     
	A header file for generic backtracking 

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


#define MAXCANDIDATES   100		/* max possible next extensions */
#define NMAX            100		/* maximum solution size */

typedef char* data;			/* type to pass data to backtrack */

bool is_a_solution(int a[], int k, int t);
void process_solution(int a[], int k);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void make_move(int a[], int k, int n);
void unmake_move(int a[], int k, int n);
void backtrack(int a[], int k, int input);
