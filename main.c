/*
 * main.c
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#include "matrix.h"
#include "test_mat.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	clock_t t;
    t = clock();

	// Put code here
	mat_t *A = test_1();
	mat_t *B = test_2();
	mat_t *C = test_3();

	free_mat_n(3, A, B, C);
	
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

	return 0;
}