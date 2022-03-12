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

void test(void)
{
	/*mat_t *A = init(3, 3);

	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 0);
	set_elem(A, 0, 2, 4);

	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 1);
	set_elem(A, 1, 2, 1);

	set_elem(A, 2, 0, 1);
	set_elem(A, 2, 1, 0);
	set_elem(A, 2, 2, -3);*/

	mat_t *A = zero_mat(3, 3);

	set_elem(A, 0, 0,  0);
	set_elem(A, 0, 1,  5);
	set_elem(A, 0, 2,  1);
	
	set_elem(A, 1, 0, 64);	
	set_elem(A, 1, 1,  8);
	set_elem(A, 1, 2,  1);
	
	set_elem(A, 2, 0,144);
	set_elem(A, 2, 1, 12);
	set_elem(A, 2, 2, 1);
	
	
	/*mat_t *A = init(3, 3);

	set_elem(A, 0, 0, 1);
	set_elem(A, 0, 1, 2);
	set_elem(A, 0, 2, 3);

	set_elem(A, 1, 0, 2);
	set_elem(A, 1, 1, 4);
	set_elem(A, 1, 2, 5);

	set_elem(A, 2, 0, 1);
	set_elem(A, 2, 1, 3);
	set_elem(A, 2, 2, 4);*/
	
	/*mat_t *A = init(5, 2);

	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 2);
	
	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 1);
	
	set_elem(A, 2, 0, 0);
	set_elem(A, 2, 1, 5);
	
	set_elem(A, 3, 0, 1);
	set_elem(A, 3, 1, 6);

	set_elem(A, 4, 0, 1);
	set_elem(A, 4, 1, 2);*/

	/*mat_t *A = init(3, 5);

	set_elem(A, 0, 0, 1);
	set_elem(A, 0, 1, 2);
	set_elem(A, 0, 2, 1);
	set_elem(A, 0, 3, 3);
	set_elem(A, 0, 4, 2);

	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 0);
	set_elem(A, 1, 2, 2);
	set_elem(A, 1, 3, 5);
	set_elem(A, 1, 4, 5);

	set_elem(A, 2, 0, 0);
	set_elem(A, 2, 1, 0);
	set_elem(A, 2, 2, 7);
	set_elem(A, 2, 3, 1);
	set_elem(A, 2, 4, 8);*/

	/*set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 1);
	set_elem(A, 0, 2, 2);
	set_elem(A, 0, 3, 0);
	set_elem(A, 0, 4, 5);

	set_elem(A, 1, 0, 3);
	set_elem(A, 1, 1, 2);
	set_elem(A, 1, 2, 0);
	set_elem(A, 1, 3, 4);
	set_elem(A, 1, 4, 2);

	set_elem(A, 2, 0, 5);
	set_elem(A, 2, 1, 6);
	set_elem(A, 2, 2, 7);
	set_elem(A, 2, 3, 1);
	set_elem(A, 2, 4, 8);*/

	print_mat(A);
	printf("\n");
	mat_t *l_mat = NULL, *u_mat = NULL, *p_mat = NULL;

	printf("%d\n", lu_fact(&l_mat, &u_mat, &p_mat, A));
	print_mat(l_mat);
	printf("\n");
	print_mat(u_mat);
	printf("\n");
	print_mat(mat_op_n(mat_mult, 2, l_mat, u_mat));

	printf("%d\n", get_rank_ref(u_mat));
	printf("%d\n", is_full_rank(u_mat));

	free_mat(A);
}

int main()
{
	clock_t t;
    t = clock();

	mat_t *A = zero_mat(3, 3);

	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 0);
	set_elem(A, 0, 2, 4);

	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 1);
	set_elem(A, 1, 2, 1);

	set_elem(A, 2, 0, 1);
	set_elem(A, 2, 1, 0);
	set_elem(A, 2, 2, -3);

	mat_t *B = zero_mat(3, 3);

	set_elem(B, 0, 0, 0);
	set_elem(B, 0, 1, 0);
	set_elem(B, 0, 2, 4);

	set_elem(B, 1, 0, 0);
	set_elem(B, 1, 1, 1);
	set_elem(B, 1, 2, 1);

	set_elem(B, 2, 0, 1);
	set_elem(B, 2, 1, 0);
	set_elem(B, 2, 2, -3);

	mat_t *C = zero_mat(3, 3);

	set_elem(C, 0, 0, 0);
	set_elem(C, 0, 1, 0);
	set_elem(C, 0, 2, 4);

	set_elem(C, 1, 0, 0);
	set_elem(C, 1, 1, 1);
	set_elem(C, 1, 2, 1);

	set_elem(C, 2, 0, 1);
	set_elem(C, 2, 1, 0);
	set_elem(C, 2, 2, -3);

	mat_t *m_result = mat_op_n(mat_mult, 3, A, B, C);
	print_mat(m_result);
	
	free_mat(m_result);
	free_mat(A);
	free_mat(B);
	free_mat(C);
	
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("fun() took %f seconds to execute \n", time_taken);
	return 0;
}