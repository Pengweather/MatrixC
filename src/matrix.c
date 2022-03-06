/*
 * matrix.c
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#include "matrix.h"
#include <stdlib.h>

struct mat
{
	mat_status_t status;
	double **elem;
	size_t row;
	size_t col;
};

mat_t *init(size_t row, size_t col)
{
	mat_t *m = (mat_t *) malloc(sizeof(mat_t));
	
	if (!m)	
		return m;

	m->row = row;
	m->col = col;

	m->elem = (double **) calloc(m->row, sizeof(double *));
	m->status = (!m->elem) ? MAT_MEM_STRUCT_ALLOC_FAIL : NO_MAT_ERROR;

	if (m->status != NO_MAT_ERROR) 
		return m;

	for (int i = 0; i < m->row; i++)
	{
		m->elem[i] = (double *) calloc(m->col, sizeof(double));
		m->status = (!m->elem[i]) ? MAT_MEM_ROW_ALLOC_FAIL : m->status;
	}

	return m;
}

mat_t *eye_mat(size_t n)
{
	mat_t *m = init(n, n);

	if (!m || m->status != NO_MAT_ERROR)
	{
		free_mat(m);
		return NULL;
	}

	for (int i = 0; i < n; i++)
	{
		m->elem[i][i] = 1;
	}

	return m;
}

mat_t *get_v_col(mat_t *m, size_t col)
{
	if (!m || 
		m->status != NO_MAT_ERROR ||
		col >= m->col)	
		return NULL;

	mat_t *m_col = init(m->row, 1);
	
	if (!m_col || m_col->status != NO_MAT_ERROR)	
		return m_col;

	for (int i = 0; i < m->row; i++)
	{
		m_col->elem[i][0] = m->elem[i][col];
	}
	
	return m_col;
}

mat_t *get_v_row(mat_t *m, size_t row)
{
	if (!m || 
		m->status != NO_MAT_ERROR ||
		row >= m->row)	
		return NULL;

	mat_t *m_row = init(1, m->col);
		
	if (!m_row || m_row->status != NO_MAT_ERROR)
	{
		return m_row;
	}

	for (int i = 0; i < m->col; i++)
	{
		m_row->elem[0][i] = m->elem[row][i];
	}

	return m_row;
}

mat_t *mat_transpose(mat_t *m)
{
	if (!m || m->status != NO_MAT_ERROR)	
		return NULL;

	mat_t *m_transpose = init(m->col, m->row);
		
	if (!m_transpose || m_transpose->status != NO_MAT_ERROR)	
		return NULL;

	for (int i = 0; i < m->col; i++)
	{
		for (int j = 0; j < m->row; j++)
		{
			m_transpose->elem[i][j] = m->elem[j][i];
		}
	}

	return m_transpose;
}

mat_t *mat_mult(mat_t *m_A, mat_t *m_B)
{
	if (!m_A || !m_B || 
		m_A->status != NO_MAT_ERROR || 
		m_B->status != NO_MAT_ERROR || 
		m_A->col != m_B->row)
		return NULL;

	mat_t *m_result = init(m_A->row, m_B->col);

	if (!m_result || m_result->status != NO_MAT_ERROR)	
		return NULL;

	for (int i = 0; i < m_result->row; i++)
	{
		for (int j = 0; j < m_result->col; j++)
		{
			m_result->elem[i][j] = 0;

			for (int k = 0; k < m_B->row; k++)
			{
				m_result->elem[i][j] += m_A->elem[i][k]*m_B->elem[k][j];
			}
		}
	}

	return m_result;
}

int lu_fact(mat_t **m_l, mat_t **m_u, mat_t *m)
{
	if (!m)
		return -1;

	*m_l = init(m->row, m->row);
	*m_u = init(m->row, m->col);

	if (!*m_l || !*m_u ||
		(*m_l)->status != NO_MAT_ERROR || 
		(*m_u)->status != NO_MAT_ERROR)
		return -1;

	for (int i = 0; i < m->col; i++)
	{
		(*m_u)->elem[0][i] = m->elem[0][i];
		(*m_l)->elem[i][i] = 1;
		(*m_l)->elem[i][0] = m->elem[i][0]/m->elem[0][0];

		for (int j = 1; j < i; j++)
		{
			(*m_l)->elem[i][j] = m->elem[i][j];

			for (int k = 0; k < j; k++)
			{
				(*m_l)->elem[i][j] -= (*m_l)->elem[i][k]*(*m_u)->elem[k][j];
			}

			(*m_l)->elem[i][j] = (*m_l)->elem[i][j]/(*m_u)->elem[j][j];
		}

		for (int j = i; j < m->col; j++)
		{
			(*m_u)->elem[i][j] = m->elem[i][j];

			for (int k = 0; k < i; k++)
			{
				(*m_u)->elem[i][j] -= (*m_l)->elem[i][k]*(*m_u)->elem[k][j];
			}
		}
	}

	return 0;
}

int gauss_jordan_elim(mat_t **m)
{
	if (!m || !*m || 
		(*m)->status != NO_MAT_ERROR)
		return -1;

	size_t piv_pos = 0;

	for (int i = 0; i < (*m)->col && piv_pos < (*m)->row; i++)
	{
		mat_t *rr_mat = eye_mat((*m)->row);

		for (int j = piv_pos + 1; j < (*m)->row; j++)
		{
			if ((*m)->elem[j][i] && !(*m)->elem[piv_pos][i])
				row_subst(*m, i, j);
		}

		for (int j = piv_pos + 1; j < (*m)->row; j++)
		{
			if ((*m)->elem[j][i] && (*m)->elem[piv_pos][i])
				rr_mat->elem[j][piv_pos] =-1*((*m)->elem[j][i])/((*m)->elem[piv_pos][i]);
		}
	
		// If there is not a viable pivot point, save the row and move onto the next column.

		mat_t *tmp_mat = mat_mult(rr_mat, *m);
		piv_pos += ((*m)->elem[piv_pos][i] != 0);

		free_mat(*m);
		free_mat(rr_mat);

		*m = tmp_mat;
	}

	return 0;
}

int row_subst(mat_t *m, size_t row_1, size_t row_2)
{
	if (!m || m->status != NO_MAT_ERROR)
		return -1;

	// Faster just to swap the rows through pointers than through an elementary matrix, 
	// which requires matrix multiplication, at which point the computational cost will increase.

	mat_t *vec_1 = get_v_row(m, row_1), *vec_2 = get_v_row(m, row_2);

	if (vec_1 && vec_2)
	{
		for (int i = 0; i < m->col; i++)
		{
			m->elem[row_1][i] = vec_2->elem[0][i];
			m->elem[row_2][i] = vec_1->elem[0][i];
		}
	}

	free_mat(vec_1);
	free_mat(vec_2);

	return 0;
}

mat_t *inv_u(mat_t *m_u)
{
	if (!m_u || 
		m_u->status != NO_MAT_ERROR || 
		m_u->row != m_u->col)
		return NULL;

	mat_t *m_u_inv = init(m_u->col, m_u->col);
	
	if (!m_u_inv || m_u_inv->status != NO_MAT_ERROR)	
	{
		free_mat(m_u_inv);
		return NULL;
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
	return m_u_inv;
}

mat_t *inv_l(mat_t *m_l)
{
	if (!m_l || 
		m_l->status != NO_MAT_ERROR || 
		m_l->row != m_l->col)
		return NULL;

	mat_t *m_l_inv = init(m_l->col, m_l->col);
	
	if (!m_l_inv || m_l_inv->status != NO_MAT_ERROR)
	{
		free_mat(m_l_inv);	
		return NULL;
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

	return m_l_inv;
}

mat_t *inv(mat_t *m_src)
{
	if (m_src->row != m_src->col)
		return NULL;

	mat_t *m_l = NULL, *m_u = NULL;
	lu_fact(&m_l, &m_u, m_src);

	print_mat(m_l);
	printf("\n");
	print_mat(m_u);
	printf("\n");

	mat_t *m_inv_u = inv_u(m_u), *m_inv_l = inv_l(m_l);
	free_mat(m_u);
	free_mat(m_l);

	mat_t *m_inv = mat_mult(m_inv_u, m_inv_l);
	free_mat(m_inv_u);
	free_mat(m_inv_l);

	return m_inv;
}

int set_elem(mat_t *m, size_t i, size_t j, double val)
{
	if (!m || 
		m->status != NO_MAT_ERROR ||
		m->row <= i || m->col <= j)
		return -1;

	m->elem[i][j] = val;
	return 0; 
}

int check_mat_ref(mat_t *m)
{
	if (!m || m->status != NO_MAT_ERROR)
		return -1;

	for (int i = 0; i < m->row; i++)
	{
		int j = 0;
		
		for (j = 0; j < m->col; j++)
		{
			if (m->elem[i][j])
				break;
		}

		if (j >= i)
		{
			for (int k = i + 1; k < m->row; k++)
			{
				if (m->elem[k][j])
					return 0;
			}
		}
	}

	return 1;
}

int zero_count_row(mat_t *m, size_t row)
{
	if (!m ||
		m->status != NO_MAT_ERROR ||
		row >= m->row) 
		return -1;

	int zeroes = 0;

	for (int i = 0; i < m->col; i++)
	{
		zeroes += (m->elem)[row][i] == 0.0;
	}

	return zeroes;
}

int zero_count_col(mat_t *m, size_t col)
{
	if (!m ||
		m->status != NO_MAT_ERROR ||
		col >= m->col) 
		return -1;

	int zeroes = 0;

	for (int i = 0; i < m->row; i++)
	{
		zeroes += (m->elem)[i][col] == 0.0;
	}

	return zeroes;
}

void free_mat(mat_t *m)
{
	if (!m)
		return;

	for (int i = 0; i < m->row; i++)
	{
		if (m->elem + i)
			free(m->elem[i]);
	}

	free(m->elem);
	free(m);
}

void print_mat(mat_t *m)
{
	if (!m) 
		return;

	for (int i = 0; i < m->row; i++)
	{
		for (int j = 0; j < m->col; j++)
		{
			printf("%f ", m->elem[i][j]);
		}

		printf("\n");
	}
}