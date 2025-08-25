#ifndef SQUARE_SOLVER_TEST_H
#define SQUARE_SOLVER_TEST_H
#include "Data.h"
/*
* @brief Тестирует программу
*
* @return true в случае успешных тестов, false в случае ошибки
*/
bool OneTest(double a, double b, double c, double x1ref, double x2ref, Roots quantity_of_roots_ref);
bool RunTests();
bool get_tests_from_file(double * ptr_a, double * ptr_b, double * ptr_c, double * ptr_x1, double * ptr_x2, Roots * ptr_quantity_of_roots, FILE * fp);

#endif //SQUARE_SOLVER_TEST_H


