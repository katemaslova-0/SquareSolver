#ifndef SQUARE_SOLVER_TYPE_H
#define SQUARE_SOLVER_TYPE_H

#include "Data.h"

/*
* @brief Запрашивает выбор типа ввода
*
* @return Тип ввода
*/
Input choose_type_of_input(void);


/*
* @brief Конвертирует тип int в тип Input
*
* @param [in] type_of_input_int Тип ввода(int)
* @param [out] type_of_input Указатель на тип ввода(Input)
*/
bool convert_int_to_input(int type_of_input_int, Input * type_of_input);

#endif //SQUARE_SOLVER_TYPE_H


