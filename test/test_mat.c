#include "test_mat.h"

mat_t *test_1(void)
{
    mat_t *A = zero_mat(3, 3);

	set_elem(A, 0, 0,   0);
	set_elem(A, 0, 1,   5);
	set_elem(A, 0, 2,   1);
	
	set_elem(A, 1, 0,  64);	
	set_elem(A, 1, 1,   8);
	set_elem(A, 1, 2,   1);
	
	set_elem(A, 2, 0, 144);
	set_elem(A, 2, 1,  12);
	set_elem(A, 2, 2,   1);

    return A;
}

mat_t *test_2(void)
{
    mat_t *A = zero_mat(3, 3);

	set_elem(A, 0, 0,  0);
	set_elem(A, 0, 1,  0);
	set_elem(A, 0, 2,  4);

	set_elem(A, 1, 0,  0);
	set_elem(A, 1, 1,  1);
	set_elem(A, 1, 2,  1);

	set_elem(A, 2, 0,  1);
	set_elem(A, 2, 1,  0);
	set_elem(A, 2, 2, -3);
}

mat_t *test_3(void)
{
    mat_t *A = zero_mat(3, 3);

	set_elem(A, 0, 0, 1);
	set_elem(A, 0, 1, 2);
	set_elem(A, 0, 2, 3);

	set_elem(A, 1, 0, 2);
	set_elem(A, 1, 1, 4);
	set_elem(A, 1, 2, 5);

	set_elem(A, 2, 0, 1);
	set_elem(A, 2, 1, 3);
	set_elem(A, 2, 2, 4);

    return A;
}

mat_t *test_4(void)
{
    mat_t *A = zero_mat(5, 2);

	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 2);
	
	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 1);
	
	set_elem(A, 2, 0, 0);
	set_elem(A, 2, 1, 5);
	
	set_elem(A, 3, 0, 1);
	set_elem(A, 3, 1, 6);

	set_elem(A, 4, 0, 1);
	set_elem(A, 4, 1, 2);

    return A;
}

mat_t *test_5(void)
{
    mat_t *A = zero_mat(3, 5);

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
	set_elem(A, 2, 4, 8);

    return A;
}

mat_t *test_6(void)
{
    mat_t *A = zero_mat(3, 5);

    set_elem(A, 0, 0, 0);
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
	set_elem(A, 2, 4, 8);

    return A;
}

mat_t *test_7(void)
{
    mat_t *A = zero_mat(4, 5);

	set_elem(A, 0, 0, 2);
	set_elem(A, 0, 1, 1);
	set_elem(A, 0, 2, 1);
	set_elem(A, 0, 3, 0);
	set_elem(A, 0, 4, 7);
	
	set_elem(A, 1, 0, 4);
	set_elem(A, 1, 1, 3);
	set_elem(A, 1, 2, 9);
	set_elem(A, 1, 3, 5);
	set_elem(A, 1, 4, 2);
	
	set_elem(A, 2, 0, 8);
	set_elem(A, 2, 1, 7);
	set_elem(A, 2, 2, 9);
	set_elem(A, 2, 3, 5);
	set_elem(A, 2, 4, 2);

	set_elem(A, 3, 0, 6);
	set_elem(A, 3, 1, 7);
	set_elem(A, 3, 2, 1);
	set_elem(A, 3, 3, 8);
	set_elem(A, 3, 4, 0);

    return A;
}

mat_t *test_8(void)
{
	mat_t *A = zero_mat(4, 4);

	set_elem(A, 0, 0, 1);
	set_elem(A, 0, 1, 0);
	set_elem(A, 0, 2, 0);
	set_elem(A, 0, 3, 1);
	
	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 2);
	set_elem(A, 1, 2, 1);
	set_elem(A, 1, 3, 2);
	
	set_elem(A, 2, 0, 2);
	set_elem(A, 2, 1, 1);
	set_elem(A, 2, 2, 0);
	set_elem(A, 2, 3, 1);
	
	set_elem(A, 3, 0, 2);
	set_elem(A, 3, 1, 0);
	set_elem(A, 3, 2, 1);
	set_elem(A, 3, 3, 4);

    return A;
}

mat_t *test_9(void)
{
	mat_t *A = zero_mat(5, 2);

	set_elem(A, 0, 0, 0);
	set_elem(A, 0, 1, 2);
	
	set_elem(A, 1, 0, 0);
	set_elem(A, 1, 1, 1);
	
	set_elem(A, 2, 0, 0);
	set_elem(A, 2, 1, 5);
	
	set_elem(A, 3, 0, 1);
	set_elem(A, 3, 1, 6);

	set_elem(A, 4, 0, 1);
	set_elem(A, 4, 1, 2);

    return A;
}

mat_t *test_10(void)
{
	mat_t *A = zero_mat(4, 5);

	set_elem(A, 0, 0,  2);
	set_elem(A, 0, 1,  4);
	set_elem(A, 0, 2, -1);
	set_elem(A, 0, 3,  5);
	set_elem(A, 0, 4, -2);
	
	set_elem(A, 1, 0, -4);
	set_elem(A, 1, 1, -5);
	set_elem(A, 1, 2,  3);
	set_elem(A, 1, 3, -8);
	set_elem(A, 1, 4,  1);
	
	set_elem(A, 2, 0,  2);
	set_elem(A, 2, 1, -5);
	set_elem(A, 2, 2, -4);
	set_elem(A, 2, 3,  1);
	set_elem(A, 2, 4,  8);

	set_elem(A, 3, 0, -6);
	set_elem(A, 3, 1,  0);
	set_elem(A, 3, 2,  7);
	set_elem(A, 3, 3, -3);
	set_elem(A, 3, 4,  1);

    return A;
}

mat_t *test_11(void)
{
	mat_t *A = zero_mat(5, 5);

	set_elem(A, 0, 0,  2);
	set_elem(A, 0, 1,  4);
	set_elem(A, 0, 2, -2);
	set_elem(A, 0, 3,  3);
	
	set_elem(A, 1, 0,  6);
	set_elem(A, 1, 1, -9);
	set_elem(A, 1, 2, -5);
	set_elem(A, 1, 3,  8);
	
	set_elem(A, 2, 0,  2);
	set_elem(A, 2, 1, -7);
	set_elem(A, 2, 2, -3);
	set_elem(A, 2, 3,  9);

	set_elem(A, 3, 0,  4);
	set_elem(A, 3, 1, -2);
	set_elem(A, 3, 2, -2);
	set_elem(A, 3, 3, -1);

	set_elem(A, 4, 0, -6);
	set_elem(A, 4, 1,  3);
	set_elem(A, 4, 2,  3);
	set_elem(A, 4, 3,  4);
}

mat_t *test_12(void)
{
	mat_t *A = zero_mat(5, 4);

	set_elem(A, 0, 0,  2);
	set_elem(A, 0, 1, -4);
	set_elem(A, 0, 2, -2);
	set_elem(A, 0, 3,  3);
	
	set_elem(A, 1, 0,  6);
	set_elem(A, 1, 1, -9);
	set_elem(A, 1, 2, -5);
	set_elem(A, 1, 3,  8);
	
	set_elem(A, 2, 0,  2);
	set_elem(A, 2, 1, -7);
	set_elem(A, 2, 2, -3);
	set_elem(A, 2, 3,  9);

	set_elem(A, 3, 0,  4);
	set_elem(A, 3, 1, -2);
	set_elem(A, 3, 2, -2);
	set_elem(A, 3, 3, -1);

	set_elem(A, 4, 0, -6);
	set_elem(A, 4, 1,  3);
	set_elem(A, 4, 2,  3);
	set_elem(A, 4, 3,  4);

    return A;
}