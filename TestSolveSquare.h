#ifndef SQUARE_SOLVER_TEST_H
#define SQUARE_SOLVER_TEST_H

#include "Data.h"

struct TestData
{
    double a, b, c;
    double x1_ref, x2_ref;
    int quantity_of_roots_ref;
};


/*
* @brief Тестирует программу
*
* param [out] Константный указатель на структуру, содержащую тесты
*
* @return true в случае успешных тестов, false в случае ошибки
*/
bool OneTest(const TestData * test);


/*
* @brief Запускает тестирование программы
*
* @return true в случае успешного тестирования, false в противном случае
*/
bool RunTests();


/*
* @brief Считывает тестовые значения из файла
*
* @param [out] TestData * test_from_file Указатель на массив структур с тестовыми значениями
* @param [out] FILE * fp Указатель на файл с тестами
*
* @return true в случае успешного считывания значений, false в противном случае
*/
bool get_tests_from_file(TestData * test_from_file, FILE * fp);

#endif //SQUARE_SOLVER_TEST_H


