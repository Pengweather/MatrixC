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
	mat_t *A = init(5, 2);

	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 0);

	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 1);

	set_elem(A, 2, 0, 1);
	set_elem(A, 2, 1, 2);

	set_elem(A, 3, 0, 0);
	set_elem(A, 3, 1, 1);

	set_elem(A, 4, 0, 1);
	set_elem(A, 4, 1, 2);

	print_mat(A);
	printf("\n");

	row_subst(A, 3, 1);
	print_mat(A);

	free_mat(A);
	return 0;
}