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
	bool if_flags = false;
	bool if_cf_correct = true;
	bool n = false;

	if ((n = check_flags(&if_cf_correct, if_flags, argv, argc, &a, &b, &c)) == true && if_cf_correct == false)
		return -1;
	if (n == true && if_cf_correct == true)
	{
		Roots quantity_of_roots = solve_square(a, b, c, &x1, &x2);
		output_roots(x1, x2, quantity_of_roots);
	}

	if (n == false)
	{
		Input type_of_input = choose_type_of_input();

		if (type_of_input == kDefaultInput)
			return -1;

		if (get_coefficients(type_of_input, &a, &b, &c) == false)
			return -1;

		Roots quantity_of_roots = solve_square(a, b, c, &x1, &x2);
		output_roots(x1, x2, quantity_of_roots);
	}

	return 0;
}


