// SquareSolver
/* @brief Решает квадратные уравнения
*
* @details Эта программа решает квадратные уравнения
* при помощи дискриминанта. Если старший коэффициент
* равен 0, программа также решает линейный случай. При
* некорректном вводе коэффициента программа запрашивает
* его повторно. При вводе EOF программа завершается.
*
* @param [in] a Коэффициент при x^2
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @return Количество корней и корни квадратного уравнения
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>
#include <cstring>

#include "Input.h"
#include "Solve.h"
#include "Output.h"
#include "TestSolveSquare.h"
#include "Data.h"
#include "Type.h"
#include "Check.h"

int main(int argc, const char * argv[])
{
	double a = 0.0, b = 0.0, c = 0.0;
	double x1 = 0.0, x2 = 0.0;
	bool if_cf_correct = true;
	bool if_cf = false;
	int tag_count = 0;

	Flags current_flags = {.show_flags = false, .test_flag = false, .cf_flag = false};

	get_flags(&tag_count, argc, argv, &current_flags);

	if (current_flags.show_flags == true)
		show_arguments(argc, argv);

	if (current_flags.test_flag == true)
	{
		if (RunTests() == false)
				return -1;
	}
	else
		printf("Программа запущена без тестов\n");

	if (current_flags.cf_flag == true)
	{
		if ((if_cf = check_cf(tag_count, &if_cf_correct, argv, argc, &a, &b, &c)) == true && if_cf_correct == false)
			return -1;
	}

	if (if_cf == false)
	{
		Input type_of_input = choose_type_of_input();

		if (type_of_input == kDefaultInput)
			return -1;

		if (get_coefficients(type_of_input, &a, &b, &c) == false)
			return -1;
	}

	if (if_cf_correct == true)
	{
		Roots quantity_of_roots = solve_square(a, b, c, &x1, &x2);
		output_roots(x1, x2, quantity_of_roots);
	}

	return 0;
}


