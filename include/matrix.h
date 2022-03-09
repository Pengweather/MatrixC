/*
 * matrix.h
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

typedef enum
{
	NO_MAT_ERROR,
	MAT_MEM_ROW_ALLOC_FAIL,
	MAT_MEM_STRUCT_ALLOC_FAIL,
	MAT_VAL_INVALID_FAIL
} mat_stat_t;

/**
 * Matrix initialization and extractions.
 */

typedef struct mat mat_t;

mat_t *zero_mat(size_t row, size_t col);
mat_t *eye_mat(size_t n);
mat_t *copy_mat(mat_t *m);
mat_t *get_v_col(mat_t *m, size_t col);
mat_t *get_v_row(mat_t *m, size_t row);
mat_t *mat_transpose(mat_t *m);
mat_t *mat_mult(mat_t *m_A, mat_t *m_B);
mat_t *mat_mult_n(size_t n_mat, ...);
mat_t *gauss_elim(mat_t *m);

int lu_fact(mat_t **m_l, mat_t **m_u, mat_t **m_p, mat_t *m);
int row_subst(mat_t *, size_t row_1, size_t row_2);
int set_elem(mat_t *m, size_t i, size_t j, double val);

mat_t *inv_u(mat_t *m);
mat_t *inv_l(mat_t *m);
mat_t *inv(mat_t *m);

int is_mat_ref(mat_t *m);
int get_rank_ref(mat_t *m);
int is_full_rank(mat_t *m);
int zero_count_row(mat_t *m, size_t row);
int zero_count_col(mat_t *m, size_t col);

/**
 * Cleanup
 */

void free_mat(mat_t *);

/**
 * Diagnostics
 */

void print_mat(mat_t *);

#endif