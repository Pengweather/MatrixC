/*
 * main.c
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	mat_t *A = init(4, 4);

	(A->elem)[0][0] = 0;
	(A->elem)[0][1] = 4;
	(A->elem)[0][2] = 0;
	(A->elem)[0][3] = 1;

	(A->elem)[1][0] = 2;
	(A->elem)[1][1] = 0;
	(A->elem)[1][2] = 11;
	(A->elem)[1][3] = 4;

	(A->elem)[2][0] = 0;
	(A->elem)[2][1] = 0;
	(A->elem)[2][2] = 12;
	(A->elem)[2][3] = 0;

	(A->elem)[3][0] = 0;
	(A->elem)[3][1] = 2;
	(A->elem)[3][2] = 12;
	(A->elem)[3][3] = 10;

	mat_t *B = init(2, 2);

	(B->elem)[0][0] = 2;
	(B->elem)[0][1] = 4;

	(B->elem)[1][0] = 2;
	(B->elem)[1][1] = 2;

	mat_t *result = NULL;

	inv(&result, A);
	print_mat(result);

	free_mat(result);
	result = NULL;

	double det_result = 0.0;
	det(&det_result, A);

	free_mat(A);
	A = NULL;

	free_mat(B);
	B = NULL;

	free_mat(result);
	result = NULL;
}