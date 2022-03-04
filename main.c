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

	set_elem(A, 0, 0, 2);
	set_elem(A, 0, 1, 1);
	set_elem(A, 0, 3, 2);

	set_elem(A, 1, 0, 8);
	set_elem(A, 1, 1, 1);
	set_elem(A, 1, 2, 1);

	set_elem(A, 2, 0, 2);
	set_elem(A, 2, 1, 2);
	set_elem(A, 2, 3, 7);

	set_elem(A, 3, 0, 2);
	set_elem(A, 3, 1, 1);

	mat_t *result = eye_mat(5);
	print_mat(inv(A));
	printf("\n");

	gauss_elim(&A);
	print_mat(A);

	free_mat(result);
	free_mat(A);

	return 0;
}