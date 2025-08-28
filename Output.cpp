#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

#include "Output.h"

#define ANSI_COLOR_BLUE "\033[1;34m"

void output_roots(double x1, double x2, Roots quantity_of_roots)
{
	assert(!isnan(x1));
	assert(!isnan(x2));

	switch(quantity_of_roots)
	{
		case kNoRoots: printf(ANSI_COLOR_BLUE "Уравнение не имеет решений\n");
			break;
		case kOneRoot: printf(ANSI_COLOR_BLUE "Уравнение имеет одно решение: %.2f\n", x1);
			break;
		case kTwoRoots: printf(ANSI_COLOR_BLUE "Уравнение имеет два решения: %.2f и %.2f\n", x1, x2);
			break;
		case kInfinity: printf(ANSI_COLOR_BLUE "Уравнение имеет бесконечное множество решений\n");
			break;
		case kStart: printf("Ошибка: не определилось количество корней");
			break;
		default: printf("Ошибка");
	}
}
