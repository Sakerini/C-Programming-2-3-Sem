#include "delete.h"
#include "find.h"

/**
 * @brief Функция меняет размер матриц для строки
 * 
 * @param ptrs матрица
 * @param n размер матрица
 * @param newn новый размер
 * @return int код ошибки
 */
int rows_resize(int64_t ***ptrs, int *n, int newn)
{
	assert(ptrs != NULL);

	if (*n == newn)
		return OK;
	int64_t **buf = (int64_t **) realloc(*ptrs, newn * sizeof(int64_t*));
	if (buf)
	{
		*ptrs = buf;
		buf = NULL;
		*n = newn;
		return OK;
	}
	return ERR_MEM_ALLOC;
}

/**
 * @brief Фунцкия меняет размер матриц для столбца
 * 
 * @param ptrs матрица
 * @param m размер столбца
 * @param newn новый размер
 * @return int код ошибки
 */

int collumn_resize(int64_t **ptrs, int m, int newn)
{
	assert(ptrs != NULL);

	if (m == newn)
		return OK;
	int64_t *buf = (int64_t *) realloc(*ptrs, newn * sizeof(int64_t));
	if (buf)
	{
		*ptrs = buf;
		buf = NULL;
		m = newn;
		return OK;
	}
	return ERR_MEM_ALLOC;
}

/**
 * @brief Функция делает сдвиг строки указаную позицию внизу до последной
 * 
 * @param ptrs Матрица
 * @param n Размер строки
 * @param m Размер столбци
 * @param posn Позиция строка которая нужно сдвинуть до конца
 */

void move_rows(int64_t **ptrs, int n, int m, int posn)
{
	assert(ptrs != NULL);
	assert(posn >= 0);
	assert(posn < n);

	for (int i = posn; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
			ptrs[i][j] = ptrs [i + 1][j]; //check granic
	}
}

/**
 * @brief Фунцкия сдвигает элемент строке от позиця до конца
 * 
 * @param ptrs Матрица
 * @param n Размер строки
 * @param m Размер столбца
 * @param posm позиция
 */

void move_collumn(int64_t **ptrs, int n, int m, int posm)
{
	assert(ptrs != NULL);
	assert(posm >= 0);
	assert(posm < m);

	for (int i = 0; i < n; i++)
	{
		for (int j = posm; j < m - 1; j++)
		{
			ptrs[i][j] = ptrs[i][j + 1];
		}
	}
}

/**
 * @brief Функция удаляет строка
 * 
 * @param ptrs Матрица
 * @param n Размер строка
 * @param m Размер столбце
 * @param posn позиция которая нужно удалить строка
 * @return int код ошибки 
 */

int delete_row(int64_t ***ptrs, int *n, int m, int posn)
{
	int rc = OK;
	move_rows(*ptrs, *n, m, posn);
	free((*ptrs)[*n - 1]);
	(*ptrs)[*n - 1] = NULL;
	rc = rows_resize(ptrs, n, *n - 1);//NULL str
	return rc;
}

/**
 * @brief Функция удаляет столбец
 * 
 * @param ptrs Матрица
 * @param n Размер строки
 * @param m Размер столбца
 * @param posm позиция которая нужно удалить (стоблец)
 * @return int код ошибки
 */

int delete_collumn(int64_t ***ptrs, int n, int *m, int posm)
{
	int rc = OK;
	move_collumn(*ptrs, n, *m, posm);

	for (int i = 0; i < n; i++)
	{
		rc = collumn_resize(&(*ptrs)[i], *m, *m - 1);
		if (rc != OK)
			return rc;
	}
	*m = *m - 1;
	return rc;
}

/**
 * @brief Функция которая приводит матрица в квадратной форме
 * 
 * @param ptrs Матрица
 * @param n Размер строки
 * @param m Размер столбца
 * @return int код ошибки
 */

int tranform_quadratic(int64_t ***ptrs, int *n, int *m)
{
	assert(ptrs != NULL);
	
	int rc = OK;

	if (*n > *m)
	{
		int posn, posm;
		while (*n != *m)
		{
			find_min(*ptrs, *n, *m, &posn, &posm);
			rc = delete_row(ptrs, n, *m, posn);
			if (rc != OK)
				return ERR_MEM_ALLOC;
		}
	}
	else if (*n < *m)
	{
		int rc = OK;
		int posn, posm;
		while (*m != *n)
		{
			find_min(*ptrs, *n, *m, &posn, &posm);
			rc = delete_collumn(ptrs, *n, m, posm);
			if (rc != OK)
				return ERR_MEM_ALLOC;
		}
	}
	else
	{
		printf("\nINFO: Matrix is quadratic.");
		return rc;
	}
	return rc;
}