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

	set_elem(A, 0, 0, 1);
	set_elem(A, 0, 1, 4);
	set_elem(A, 0, 2, 0);
	set_elem(A, 0, 3, 1);

	set_elem(A, 1, 0, 2);
	set_elem(A, 1, 1, 0);
	set_elem(A, 1, 2, 11);
	set_elem(A, 1, 3, 4);

	set_elem(A, 2, 0, 0);
	set_elem(A, 2, 1, 0);
	set_elem(A, 2, 2, 12);
	set_elem(A, 2, 3, 0);

	set_elem(A, 3, 0, 0);
	set_elem(A, 3, 1, 2);
	set_elem(A, 3, 2, 12);
	set_elem(A, 3, 3, 10);

	mat_t *result = inv(A);
	print_mat(result);

	free_mat(result);
	free_mat(A);

	return 0;
}