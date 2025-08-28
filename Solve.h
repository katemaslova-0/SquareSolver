#ifndef SQUARE_SOLVER_SOLVE_H
#define SQUARE_SOLVER_SOLVE_H

#include "Data.h"

/*
* @brief Считает корни в случае, если уравнение является квадратным
*
* @param [in] a Коэффициент при x^2
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @param [out] ptr_x1 Указатель на первый корень
* @param [out] ptr_x2 Указатель на второй корень
*
* @return Количество корней
*/
Roots calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2);


/*
* @brief Считает корни уравнения в линейном случае
*
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @param [out] ptr_x Указатель на корень уравнения
*
* @return Количество корней
*/
Roots calculate_linear_roots(double b, double c, double * ptr_x);


/*
* @brief Вызывает функции подсчёта(в зависимости от значения старшего коэффициента)
*
* @param [in] a Коэффициент при x^2
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @param [out] ptr_x1 Указатель на первый корень
* @param [out] ptr_x2 Указатель на второй корень
*
* @return Количество корней
*/
Roots solve_square(double a, double b, double c, double * ptr_x1, double * ptr_x2);

#endif //SQUARE_SOLVER_SOLVE_H
