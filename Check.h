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

bool check_flags(bool * ptr_if_cf_correct, bool if_flags, const char * argv[], int argc, double * ptr_a, double * ptr_b, double * ptr_c);


#endif //SQUARE_SOLVER_CHECK_H

