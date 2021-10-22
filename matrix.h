/*
 * matrix.h
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct mat
{
	double **elem;
	int row;
	int col;
} mat_t;

/**
 * Matrix initialization and extractions.
 */

mat_t *init(int, int);
mat_t *get_v_col(mat_t *, int);
mat_t *get_v_row(mat_t *, int);
mat_t *mat_transpose(mat_t *);

/**
 * Inform the status of the linear algebra functions such as whether or not it succeeded.
 */

typedef enum
{
	NO_ERROR,		// No error
	SINGULARITY,    // Singularity
	NOT_SQUARE,	    // Matrix is not a square.
	DIM_MISMATCH,   // There is dimensional mismatches when performing a mathematical operation
					// on two matrices.
	NOT_INVERTIBLE, // Matrix cannot be inverted.
	OUT_OF_MEM,		// Out of memory.
	NULL_IMPROPER	// A null is improperly used.
} mat_op_stat_t;

/**
 * Mathematical linear algebra functions for computing quantities such as determinants, inverses,
 * factorizations, etc.
 */

mat_op_stat_t mat_mult(mat_t **, mat_t *, mat_t *);
mat_op_stat_t lu_fact(mat_t **, mat_t **, mat_t *);
mat_op_stat_t inv_u(mat_t **, mat_t *);
mat_op_stat_t inv_l(mat_t **, mat_t *);
mat_op_stat_t inv(mat_t **, mat_t *);
mat_op_stat_t det_2_2_mat(double *, mat_t *);
mat_op_stat_t det(double *, mat_t *);

/**
 * Cleanup
 */

void free_mat(mat_t *);

/**
 * Diagnostics
 */

void print_mat(mat_t *);

#endif