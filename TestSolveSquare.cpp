#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

#include "Solve.h"
#include "TestSolveSquare.h"
#include "Data.h"
#include "Type.h"
#include "Check.h"
#include "Input.h"

struct TestData
{
    double a, b, c;
    double x1, x2;
    int quantity_of_roots;
};

bool OneTest(double a, double b, double c, double x1ref, double x2ref, Roots quantity_of_roots_ref)
{
    assert(!isnan(a));
	assert(!isnan(b));
	assert(!isnan(c));
    assert(!isnan(x1ref));
	assert(!isnan(x2ref));

    double x1 = 0, x2 = 0;
    Roots quantity_of_roots = solve_square(a, b, c, &x1, &x2);

    if (!(quantity_of_roots == quantity_of_roots_ref && is_num_zero(x1 - x1ref) && is_num_zero(x2 - x2ref)))
    {
        printf("Ошибка при тестировании: a = %lg, b = %lg, c = %lg >> количество корней = %d, x1 = %lg, x2 = %lg", a, b, c, (int)quantity_of_roots, x1, x2);
        printf(" (ожидается количество корней = %d, x1 = %lg, x2 = %lg)", quantity_of_roots_ref, x1ref, x2ref);
        return false;
    }

    return true;
}


bool RunTests()
{
    double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;
    Roots quantity_of_roots = kStart;

    FILE * fp = fopen("TestsForSquareSolver.txt", "r");
    assert(fp != NULL);

    while (get_tests_from_file(&a, &b, &c, &x1, &x2, &quantity_of_roots, fp) != false)
    {
        if (OneTest(a, b, c, x1, x2, quantity_of_roots) == false)
            return false;
    }
    return true;
}


bool get_tests_from_file(double * ptr_a, double * ptr_b, double * ptr_c,
                         double * ptr_x1, double * ptr_x2,
                         Roots * ptr_quantity_of_roots, FILE * fp)
{
    assert(ptr_a != NULL);
	assert(ptr_b != NULL);
	assert(ptr_c != NULL);
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(fp != NULL);

    if (fscanf(fp, "%lg", ptr_a) != 1 ||
        fscanf(fp, "%lg", ptr_b) != 1 ||
        fscanf(fp, "%lg", ptr_c) != 1 ||
        fscanf(fp, "%lg", ptr_x1) != 1 ||
        fscanf(fp, "%lg", ptr_x2) != 1 ||
        fscanf(fp, "%d", (int *)ptr_quantity_of_roots) != 1)
    {
        printf("Ошибка чтения файла");
        return false;
    }

    if (fgetc(fp) == EOF)
    {
        return false;
    }
    return true;
}
