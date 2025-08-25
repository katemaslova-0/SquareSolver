#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

#include "Check.h"


bool is_num_zero(double n)
{
	assert(!isnan(n));

	return (fabs(n) < 0.00001);
}


bool check_square(double a)
{
	assert(!isnan(a));

	if (is_num_zero(a) == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
