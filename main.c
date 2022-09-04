/*
 * main.c
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#include "matrix.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*mat_t *A = zero_mat(4, 4);
	
	set_elem(A, 0, 0, 2);
	set_elem(A, 0, 1, 5);
	set_elem(A, 0, 2, 1);
	set_elem(A, 0, 3, 4);
	
	set_elem(A, 1, 0, 4);	
	set_elem(A, 1, 1, 1);
	set_elem(A, 1, 2, 6);
	set_elem(A, 1, 3, 3);

	set_elem(A, 2, 0, 5);
	set_elem(A, 2, 1, 3);
	set_elem(A, 2, 2, 7);
	set_elem(A, 2, 3, 2);

	set_elem(A, 3, 0, 1);
	set_elem(A, 3, 1, 0);
	set_elem(A, 3, 2, 2);
	set_elem(A, 3, 3, 4);*/

	mat_t *A = zero_mat(1, 1);
	
	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 0);
	set_elem(A, 0, 2, 0);
	
	set_elem(A, 1, 0, 0);	
	set_elem(A, 1, 1, 1);
	set_elem(A, 1, 2, 0);

	set_elem(A, 2, 0, 0);
	set_elem(A, 2, 1, 0);
	set_elem(A, 2, 2, 0);

	printf("%f\n", get_det(A));
	free_mat(A);

	return 0;
}