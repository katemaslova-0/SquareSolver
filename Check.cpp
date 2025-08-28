#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>
#include <cstring>

#include "Check.h"
#include "Input.h"
#include "TestSolveSquare.h"

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


bool check_flags(bool * ptr_if_cf_correct, bool if_flags, const char * argv[], int argc, double * ptr_a, double * ptr_b, double * ptr_c)
{
	int cnt_argc = argc;
	int cnt = 0;

	for (cnt = 0; cnt_argc > 0; cnt++, cnt_argc--)
	{
		if (strcmp(argv[cnt], "--test") == 0)
		{
			if (RunTests() == false)
				return false;
			if_flags = true;
		}
	}

	cnt_argc = argc;

	if (if_flags == false)
		printf("Программа запущена без тестов\n");

	for (cnt = 0; cnt_argc > 0; cnt++, cnt_argc--)
	{
		if (strcmp(argv[cnt], "--cf") == 0 && (argc - cnt) >= 4)
		{
			get_from_command_line(ptr_if_cf_correct, cnt, argv, ptr_a, ptr_b, ptr_c);

			if_flags = true;
			return if_flags;
		}
		else if (strcmp(argv[cnt], "--cf") == 0 && (argc - cnt) < 4)
		{
			printf("Коэффициенты введены некорректно");
			if_flags = true;
			*ptr_if_cf_correct = false;
			return if_flags;
		}
	}
	if_flags = false;
	return if_flags;
}
