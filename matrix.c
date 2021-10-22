/*
 * matrix.c
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#include "matrix.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

mat_t *init(int row, int col)
{
	mat_t *m = (mat_t *) malloc(sizeof(mat_t));

	/**
	 * Check that memory has been properly allocated for the matrix object. If memory hasn't been properly allocated,
	 * then we will simply return NULL.
	 */

	if (m)
	{
		m->row = row;
		m->col = col;

		m->elem = (double **) calloc(m->row, sizeof(double *));

		if (!m->elem)
		{
			free(m);
			m = NULL;

			return NULL;
		}

		for (int i = 0; i < m->row; i++)
		{
			m->elem[i] = NULL;
		}

		for (int i = 0; i < m->row; i++)
		{
			m->elem[i] = (double *) calloc(m->col, sizeof(double));

			if (!m->elem[i])
			{
				free_mat(m);
			}
		}
	}

	return m;
}

mat_t *get_v_col(mat_t *m_src, int target_col)
{
	int m = m_src->row;
	int n = m_src->col;

	if (target_col > n || target_col < 0)
	{
		return NULL;
	}

	mat_t *m_col = init(m, 1);

	if (m_col)
	{
		for (int i = 0; i < m; i++)
		{
			m_col->elem[i][0] = m_src->elem[i][target_col];
		}
	}

	return m_col;
}

mat_t *get_v_row(mat_t *m_src, int target_row)
{
	int m = m_src->row;
	int n = m_src->col;

	if (target_row > m || target_row < 0)
	{
		return NULL;
	}

	mat_t *m_row = init(1, n);

	if (m_row)
	{
		for (int i = 0; i < m; i++)
		{
			m_row->elem[0][i] = m_src->elem[target_row][i];
		}
	}

	return m_row;
}

mat_t *mat_transpose(mat_t *m_A)
{
	mat_t *m_transpose = init(m_A->col, m_A->row);

	if (m_transpose)
	{
		for (int i = 0; i < m_A->col; i++)
		{
			for (int j = 0; j < m_A->row; j++)
			{
				m_transpose->elem[i][j] = m_A->elem[j][i];
			}
		}
	}

	return m_transpose;
}

mat_op_stat_t mat_mult(mat_t **result_out, mat_t *m_A, mat_t *m_B)
{
	if (!m_A || !m_B)
	{
		return NULL_IMPROPER;
	}

	mat_t *m_result = init(m_A->row, m_B->col);

	if (m_result)
	{
		for (int i = 0; i < m_result->row; i++)
		{
			for (int j = 0; j < m_result->col; j++)
			{
				m_result->elem[i][j] = 0;

				for (int k = 0; k < m_result->col; k++)
				{
					m_result->elem[i][j] += m_A->elem[i][k]*m_B->elem[k][j];
				}
			}
		}
	}

	if (result_out)
	{
		*result_out = m_result;
	}

	return NO_ERROR;
}

mat_op_stat_t lu_fact(mat_t **m_l_out, mat_t **m_u_out, mat_t *m_src)
{
	mat_t *m_l = init(m_src->row, m_src->row);

	if (!m_l)
	{
		return OUT_OF_MEM;
	}

	mat_t *m_u = init(m_src->row, m_src->col);

	if (!m_u)
	{
		return OUT_OF_MEM;
	}

	for (int i = 0; i < m_src->row; i++)
	{
		/**
		 * Populate mat_l and mat_u with known immediate values from mat_src based on their
		 * definitions.
		 */

		m_u->elem[0][i] = m_src->elem[0][i];
		m_l->elem[i][i] = 1;
		m_l->elem[i][0] = m_src->elem[i][0]/m_src->elem[0][0];

		/**
		 * Solve unknowns in row i for mat_l.
		 */

		for (int j = 1; j < i; j++)
		{
			m_l->elem[i][j] = m_src->elem[i][j];

			for (int k = 0; k < j; k++)
			{
				m_l->elem[i][j] -= m_l->elem[i][k]*m_u->elem[k][j];
			}

			m_l->elem[i][j] = m_l->elem[i][j]/m_u->elem[j][j];
		}

		/**
		 * Solve unknowns in row j for mat_u.
		 */

		for (int j = i; j < m_src->col; j++)
		{
			m_u->elem[i][j] = m_src->elem[i][j];

			for (int k = 0; k < i; k++)
			{
				m_u->elem[i][j] -= m_l->elem[i][k]*m_u->elem[k][j];
			}
		}
	}

	/**
	 * Check for singularity in mat_l or mat_u.
	 */

	for (int i = 0; i < m_src->row; i++)
	{
		if (!m_l->elem[i][i] || !m_u->elem[i][i])
		{
			return SINGULARITY;
		}
	}

	if (m_l_out)
	{
		*m_l_out = m_l;
	}

	if (m_u_out)
	{
		*m_u_out = m_u;
	}

	return NO_ERROR;
}

mat_op_stat_t inv_u(mat_t **m_u_inv_out, mat_t *m_u)
{
	if (m_u->row != m_u->col)
	{
		return NOT_SQUARE;
	}

	mat_t *m_u_inv = init(m_u->col, m_u->col);

	if (!m_u_inv)
	{
		return OUT_OF_MEM;
	}

	for (int i = 0; i < m_u->col - 1; i++)
	{
		m_u_inv->elem[i][i] = 1/m_u->elem[i][i];

		for (int j = i + 1; j < m_u->col; j++)
		{
			for (int k = 0; k < j; k++)
			{
				m_u_inv->elem[i][j] -= m_u_inv->elem[i][k]*m_u->elem[k][j];
			}

			m_u_inv->elem[i][j] = m_u_inv->elem[i][j]/m_u->elem[j][j];
		}
	}

	m_u_inv->elem[m_u->col - 1][m_u->col - 1] = 1/m_u->elem[m_u->col - 1][m_u->col - 1];

	if (m_u_inv_out)
	{
		*m_u_inv_out = m_u_inv;
	}

	return NO_ERROR;
}

mat_op_stat_t inv_l(mat_t **m_l_inv_out, mat_t *m_l)
{
	if (m_l->row != m_l->col)
	{
		return NOT_SQUARE;
	}

	mat_t *m_l_inv = init(m_l->col, m_l->col);

	if (!m_l_inv)
	{
		return OUT_OF_MEM;
	}

	for (int i = 0; i < m_l->col; i++)
	{
		m_l_inv->elem[i][i] = 1;

		for (int j = i - 1; j >= 0; j--)
		{
			m_l_inv->elem[i][j] = -1*m_l->elem[i][j];

			for (int k = i - 1; k > j; k--)
			{
				m_l_inv->elem[i][j] -= m_l_inv->elem[i][k]*m_l->elem[k][j];
			}
		}
	}

	if (m_l_inv_out)
	{
		*m_l_inv_out = m_l_inv;
	}

	return NO_ERROR;
}

mat_op_stat_t inv(mat_t **m_inv_out, mat_t *m_src)
{
	if (m_src->row != m_src->col)
	{
		return NOT_SQUARE;
	}

	mat_t *m_l = NULL;
	mat_t *m_u = NULL;

	mat_op_stat_t stat = NO_ERROR;

	if ((stat = lu_fact(&m_l, &m_u, m_src)) != NO_ERROR)
	{
		free_mat(m_l);
		free_mat(m_u);

		return stat;
	}

	mat_t *m_inv_u = NULL;
	
	if ((stat = inv_u(&m_inv_u, m_u)) != NO_ERROR)
	{
		free_mat(m_inv_u);
		free_mat(m_u);

		return stat;
	}

	free_mat(m_u);
	mat_t *m_inv_l = NULL;

	if ((stat = inv_l(&m_inv_l, m_l)) != NO_ERROR)
	{
		free_mat(m_inv_l);
		free_mat(m_inv_u);
		free_mat(m_l);

		return stat;
	}
	
	free_mat(m_l);
	mat_t *m_inv = NULL;

	if ((stat = mat_mult(&m_inv, m_inv_u, m_inv_l)) != NO_ERROR)
	{
		free_mat(m_inv_l);
		free_mat(m_inv_u);
		free_mat(m_inv);

		return stat;
	}
	
	free_mat(m_inv_l);
	free_mat(m_inv_u);

	if (m_inv_out)
	{
		*m_inv_out = m_inv;
	}

	return NO_ERROR;
}

mat_op_stat_t det_2_2_mat(double *det, mat_t *m_src)
{
	if (m_src->row != m_src->col && m_src->row != 2)
	{
		return NOT_SQUARE;
	}

	if (!det)
	{
		return NULL_IMPROPER;
	}

	*det = (m_src->elem)[0][0]*(m_src->elem)[1][1] - (m_src->elem)[1][0]*(m_src->elem)[0][1];
	return NO_ERROR;
}

static int zero_count_row(mat_t *m_src, int row)
{
	int zeroes = 0;
	mat_t *row_vec = get_v_row(m_src, row);

	for (int i = 0; i < row_vec->col; i++)
	{
		zeroes = ((row_vec->elem)[0][i] == 0.0) ? zeroes + 1 : zeroes;
	}

	free(row_vec);
	return zeroes;
}

static int zero_count_col(mat_t *m_src, int col)
{
	int zeroes = 0;
	mat_t *col_vec = get_v_col(m_src, col);

	for (int i = 0; i < col_vec->row; i++)
	{
		zeroes = ((col_vec->elem)[i][0] == 0.0) ? zeroes + 1 : zeroes;
	}

	free(col_vec);
	return zeroes;
}

typedef struct most_zero
{
	int count;
	int idx;

} most_zero_t;

static most_zero_t most_zero_idx(mat_t *m_src, int max_idx, int (*zero_count_func)(mat_t *, int))
{
	most_zero_t m_zero = (most_zero_t){0, 0};

	for (int i = 0; i < max_idx; i++)
	{
		int curr_zero_count = zero_count_func(m_src, i);

		if (curr_zero_count >= m_zero.count)
		{
			m_zero.idx   = i;
			m_zero.count = curr_zero_count;
		}
	}

	return m_zero;
}

mat_op_stat_t det(double *det, mat_t *m_src)
{
	if (m_src->row == m_src->col && m_src->row == 2)
	{

	}

	most_zero_t m_z_col = most_zero_idx(m_src, m_src->col, zero_count_col);
	most_zero_t m_z_row = most_zero_idx(m_src, m_src->row, zero_count_row);

	int target_idx = (m_z_col.count > m_z_row.count) ? m_z_col.idx : m_z_row.idx;

	return NO_ERROR;
}

void free_mat(mat_t *m_src)
{
	if (m_src)
	{
		for (int i = 0; i < m_src->row; i++)
		{
			free(m_src->elem[i]);
		}

		free(m_src->elem);
		free(m_src);
	}
}

void print_mat(mat_t *m)
{
	if (m)
	{
		for (int i = 0; i < m->row; i++)
		{
			for (int j = 0; j < m->col; j++)
			{
				printf("%f ", m->elem[i][j]);
			}

			printf("\n");
		}

		printf("\n");
	}
}