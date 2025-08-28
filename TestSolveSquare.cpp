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

#define MY_ASSERT(cond, cond2) if (!(cond)) {fprintf(stderr, "\n\n%s\n\n\n------------------------\n\n\nError in file %s in line %d\n\n\n------------------------\n\n", cond2, __FILE__, __LINE__); \
	printf("                  \n"); \
	printf("              /\\       \n"); \
	printf("             /  \\      \n"); \
	printf("            /    \\          \n"); \
	printf("    _______/  /\\  \\______ \n"); \
	printf("    \\    ____/  \\____   /           \n"); \
	printf("     \\   \\         /   /    \n"); \
	printf("     /    /        \\   \\     \n"); \
	printf("    /    /__      __\\   \\      \n"); \
	printf("   /______  \\   /  ______\\              \n"); \
	printf("          \\  \\ /  /                          \n"); \
	printf("           \\     /                           \n"); \
	printf("            \\   /                          \n"); \
	printf("             \\ /                                \n\n \n"); \
	abort(); \
	}

bool OneTest(const TestData * test)
{
    MY_ASSERT(test != NULL, "Ожидается ненулевой указатель\n");

    double x1 = 0, x2 = 0;
    Roots quantity_of_roots = solve_square(test->a, test->b, test->c, &x1, &x2);

    if (!(quantity_of_roots == test->quantity_of_roots_ref && is_num_zero(x1 - test->x1_ref) && is_num_zero(x2 - test->x2_ref)))
    {
        printf("Ошибка при тестировании: a = %lg, b = %lg, c = %lg >> количество корней = %d, x1 = %lg, x2 = %lg", test->a, test->b, test->c, quantity_of_roots, x1, x2);
        printf(" (ожидается количество корней = %d, x1 = %lg, x2 = %lg)", (int)(test->quantity_of_roots_ref), test->x1_ref, test->x2_ref);
        return false;
    }

    return true;
}


bool RunTests()
{
    printf("Тесты запущены\n");
    TestData tests[5] = {
                            {.a = 1, .b = -5, .c = 6, .x1_ref = 3, .x2_ref = 2, .quantity_of_roots_ref = kTwoRoots},
                            {.a = 0, .b = 0, .c = 0, .x1_ref = 0, .x2_ref = 0, .quantity_of_roots_ref = kInfinity},
                            {.a = 0, .b = 0, .c = 6, .x1_ref = 0, .x2_ref = 0, .quantity_of_roots_ref = kNoRoots},
                            {.a = 0, .b = 1, .c = 1, .x1_ref = -1, .x2_ref = 0, .quantity_of_roots_ref = kOneRoot},
                            {.a = 1, .b = 2, .c = 1, .x1_ref = -1, .x2_ref = 0, .quantity_of_roots_ref = kOneRoot}
                        };

    TestData tests_from_file[5] = {};


    int size = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < size; i++)
    {
        if (OneTest(&tests[i]) == false)
            return false;
    }

    FILE * fp = fopen("TestsForSquareSolver.txt", "r");
    assert(fp != NULL);

    for (int i = 0; i < size && (get_tests_from_file(&tests_from_file[i], fp) != false); i++)
    {
        if (OneTest(&tests_from_file[i]) == false)
            return false;
    }
    return true;
}


bool get_tests_from_file(TestData * tests_from_file, FILE * fp)
{
    assert(fp != NULL);
    assert(tests_from_file != NULL);

    if (fscanf(fp, "%lg", &tests_from_file->a) != 1 ||
        fscanf(fp, "%lg", &tests_from_file->b) != 1 ||
        fscanf(fp, "%lg", &tests_from_file->c) != 1 ||
        fscanf(fp, "%lg", &tests_from_file->x1_ref) != 1 ||
        fscanf(fp, "%lg", &tests_from_file->x2_ref) != 1 ||
        fscanf(fp, "%d", &tests_from_file->quantity_of_roots_ref) != 1)
    {
        printf("Ошибка чтения файла\n");
        return false;
    }

    if (fgetc(fp) == EOF)
    {
        return false;
    }

    return true;
}
