#include "err.h"
#include "io.h"
#include "find.h"
#include "delete.h"
#include "add.h"
#include "compute.h"

int main(void)
{
    int rc = OK; //КОД ОШИБКИ
    int n, m, p, q; // ПЕРЕМЕННЫЕ ДЛЯ ХРАНЕНИЯ РАЗМЕР ОБА МАТРИЦ
    int64_t **matrix_one = NULL; //УКАЗАТЕЛЬ НА ПЕРВУЮ МАТРИЦУ
    int64_t **matrix_two = NULL; //УКАЗАТЕЛЬ НА ВТОРУЮ МАТРИЦУ
    setbuf(stdout, NULL);

    // Создаем первую матрицу
    rc = matrix_create(&matrix_one, &n, &m);
    if (rc != OK)
        printf("\nINFO: Matrix input failed!!!");
    else
    {   //Создаем вторую матрицу
        rc = matrix_create(&matrix_two, &p, &q);
        if (rc != OK)
            printf("\nINFO: Matrix input failed!!!");
        else
        {   // Приводим первую матрицу в квадратной форме
            rc = tranform_quadratic(&matrix_one, &n, &m);
            if (rc != OK)
                printf("\nINFO: Transformation to quadratic matrix first failed");
            else
            { //  Приводим вторую матрицу в квадратной форме
                rc = tranform_quadratic(&matrix_two, &p, &q);
                if (rc != OK)
                    printf("\nINFO: Transformation to quadratic matrix second failed");
                else
                {
                    if (n > p)
                    {   
                        // Приводим матрицу одного размера с другой матрицу добавлаяя елементы
                        rc = matrix_grow(&matrix_two, &p, &q, n);
                        if (rc != OK)
                            printf("\nINFO: Matrix_two grow failed!");
                        //matrix_two --- ADD
                    }
                    else if (n < p)
                    {   
                        // Приводим матрицу одного размера с другой матрицу добавлаяя елементы
                        rc = matrix_grow(&matrix_one, &n, &m, p);
                        if (rc != OK)
                            printf("\nINFO: Matrix_two grow failed!");
                    }
                    else
                    {
                        printf("\nINFO: Matrixes are one size!!");
                    }

                    if (rc != OK)
                        printf("\nINFO: Matrix grow failed!");
                    else
                    {
                        int ro, gamma; // РО И ГАММА (для степен матриц)
                        rc = in_ro_gamma(&ro, &gamma); // ВВОД РО И ГАММА
                        if (rc != OK)
                            printf("\nINFO: Ro or Gamma input failed!!");
                        else
                        {  //УМНОЖЕНИЕ МАТРИЦ В ФОРМЕ (А^RO  x  B^gamma)
                            computation(&matrix_one, &matrix_two, n, ro, gamma);
                            matrix_print(matrix_two, p, q);
                        }
                    }
                }   
            }
        }
    }
    if (matrix_one != NULL)
        matrix_free(matrix_one, n); //Освобождение памяты для первой матрице
    if (matrix_two != NULL)
        matrix_free(matrix_two, p); //Освобождение памяты для второй матрице
    return rc;
}