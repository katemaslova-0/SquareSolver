#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

#include "Check.h"
#include "Solve.h"
#include "Data.h"

Roots solve_square(double a, double b, double c, double * ptr_x1, double * ptr_x2)
{
	assert(!isnan(a));
	assert(!isnan(b));
	assert(!isnan(c));
	assert(ptr_x1 != NULL);
	assert(ptr_x2 != NULL);

	Roots quantity_of_roots = kStart;

	if (check_square(a) == true)
		quantity_of_roots = calculate_quadratic_roots(a, b, c, ptr_x1, ptr_x2);

	else
		quantity_of_roots = calculate_linear_roots(b, c, ptr_x1);

	return(quantity_of_roots);
}


Roots calculate_linear_roots(double b, double c, double * ptr_x)
{
	assert(!isnan(b));
	assert(!isnan(c));
	assert(ptr_x != NULL);

	Roots quantity_of_roots = kStart;

	if (is_num_zero(b) == true && is_num_zero(c) == true)
	{
		quantity_of_roots = kInfinity;
	}

	else if (is_num_zero(b) == true && is_num_zero(c) == false)
	{
			quantity_of_roots = kNoRoots;
	}

	else if (is_num_zero(b) == false)
	{
			*ptr_x = - c / b;
			quantity_of_roots = kOneRoot;
	}

	return quantity_of_roots;
}


Roots calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2)
{
	assert(!isnan(a));
	assert(!isnan(b));
	assert(!isnan(c));
	assert(ptr_x1 != NULL);
	assert(ptr_x2 != NULL);

	double discriminant = b * b - 4 * a * c;
	double sqr_discr = 0.0;

	if (discriminant >= 0)
	{
		sqr_discr = sqrt(discriminant);
	}

	Roots quantity_of_roots = kStart;

	if (discriminant < 0)
	{
		quantity_of_roots = kNoRoots;
	}

	else if (is_num_zero(discriminant) == true)
	{
		quantity_of_roots = kOneRoot;
		*ptr_x1 = (- b + sqr_discr) / 2 / a;
	}

	else
	{
		quantity_of_roots = kTwoRoots;
		*ptr_x1 = (- b + sqr_discr) / 2 / a;
		*ptr_x2 = (- b - sqr_discr) / 2 / a;
	}

	return quantity_of_roots;
}
