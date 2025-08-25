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

#include "Input.h"
#include "Solve.h"
#include "Output.h"
#include "TestSolveSquare.h"
#include "Data.h"
#include "Type.h"

int main(void)
{
	double a = 0.0, b = 0.0, c = 0.0;
	double x1 = 0.0, x2 = 0.0;

	if (RunTests() == false)
	{
		return -1;
	}

	Input type_of_input = choose_type_of_input();

	if (type_of_input == kDefaultInput)
	{
		return -1;
	}

	if (get_coefficients(type_of_input, &a, &b, &c) == false)
	{
		return -1;
	}

	Roots quantity_of_roots = solve_square(a, b, c, &x1, &x2);
	output_roots(x1, x2, quantity_of_roots);

	return 0;
}



