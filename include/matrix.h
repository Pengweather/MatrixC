/*
 * matrix.h
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#ifndef MATRIX_H_
#define MATRIX_H_

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

mat_t *init(size_t, size_t);
mat_t *eye_mat(size_t);
mat_t *copy_mat_t(mat_t *);
mat_t *get_v_col(mat_t *, size_t);
mat_t *get_v_row(mat_t *, size_t);
mat_t *mat_transpose(mat_t *);
mat_t *mat_mult(mat_t *, mat_t *);

int lu_fact(mat_t **, mat_t **, mat_t *);
int gauss_jordan_elim(mat_t **);
int row_subst(mat_t *, size_t, size_t);
int set_elem(mat_t *m, size_t i, size_t j, double val);

mat_t *inv_u(mat_t *);
mat_t *inv_l(mat_t *);
mat_t *inv(mat_t *);

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