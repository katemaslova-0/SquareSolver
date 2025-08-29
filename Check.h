#ifndef SQUARE_SOLVER_CHECK_H
#define SQUARE_SOLVER_CHECK_H

#include "Data.h"

/*
* @brief Проверяет равенство старшего коэффициента уравнения нулю
*
* @param [in] a Старший коэффициент уравнения
*
* @return true, если старший коэффициент не равен нулю
* 		  false, если старший коэффициент равен нулю
*/
bool check_square(double a);


/*
* @brief Проверяет равенство введённого числа нулю
*
* @param [in] n Число, проверяемое на равенство нулю
*
* @return true, если число равно нулю
*		  false, если число не равно нулю
*
*/
bool is_num_zero(double n);


/*
* @brief Проверяет наличие флагов и запускает соответствующие каждому функции
*
* @param [in] argc Количество аргументов командной строки
*
* @param [out] ptr_if_cf_correct Указатель на корректность ввода коэффициентов
* @param [out] argc[] Указатель на аргумент командной строки
* @param [out] ptr_a Указатель на коэффициент при x^2
* @param [out] ptr_b Указатель на коэффициент при x
* @param [out] ptr_c Указатель на свободный член
*
* @return true, если есть флаг для коэффициентов, false в противном случае
*/
bool check_cf(int cnt, bool * ptr_if_cf_correct, const char * argv[], int argc, double * ptr_a, double * ptr_b, double * ptr_c);


void show_arguments(int argc, const char * argv[]);

#endif //SQUARE_SOLVER_CHECK_H

