#ifndef SQUARE_SOLVER_INPUT_H
#define SQUARE_SOLVER_INPUT_H

#include "Data.h"

/*
* @brief Вызывает функции ввода
*
* @param [in] type_of_input Тип ввода
* @param [out] ptr_a Указатель на коэффициент при x^2
* @param [out] ptr_b Указатель на коэффициент при x
* @param [out] ptr_c Указатель на свободный член
*
* @return true при успешном вызове функций, false в обратном случае
*/
bool get_coefficients(Input type_of_input, double * ptr_a, double * ptr_b, double * ptr_c);

/*
* @brief Считывает коэффициенты уравнения с клавиатуры
*
* @param [out] ptr Указатель на коэффициент
*
* @return true, если коэффициент успешно считан,
*		  false в обратном случае
*/
bool get_number_from_console(double * ptr);


/*
* @brief Запрашивает ввод коэффициентов c клавиатуры
*
* @param [out] ptr_a Указатель на коэффициент при x^2
* @param [out] ptr_b Указатель на коэффициент при x
* @param [out] ptr_c Указатель на свободный член
*
* @return true, если коэффициенты успешно считаны,
*        false в противном случае
*/
bool get_from_console(double * ptr_a, double * ptr_b, double * ptr_c);


/*
* @brief Считывает коэффициенты уравнения из файла
*
* @param [out] ptr Указатель на коэффициент
* @param [out] fp Указатель на файл
*
* @return true, если коэффициент успешно считан,
*		  false в обратном случае
*/
bool get_number_from_file(double * ptr);


/*
* @brief Запрашивает ввод коэффициентов из файла
*
* @param [out] ptr_a Указатель на коэффициент при x^2
* @param [out] ptr_b Указатель на коэффициент при x
* @param [out] ptr_c Указатель на свободный член
* @param [out] fp Указатель на файл
*
* @return true, если коэффициенты успешно считаны,
*        false в противном случае
*/
bool get_from_file(double * ptr_a, double * ptr_b, double * ptr_c);


/*
* @brief Очищает буфер
*/
void clear_buffer(void);


/*
* @brief Получает коэффициенты уравнения из командной строки
*
* @param [in] argc Суммарное количество аргументов командной строки
* @param [out] ptr_a Указатель на коэффициент при x^2
* @param [out] ptr_b Указатель на коэффициент при x
* @param [out] ptr_c Указатель на свободный член
*/
void get_from_command_line(bool * ptr_if_cf_correct, int cnt, const char * argv[], double * ptr_a, double * ptr_b, double * ptr_c);

#endif //SQUARE_SOLVER_INPUT_H


