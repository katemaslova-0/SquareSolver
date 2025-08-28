#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

#include "Input.h"

#define ANSI_COLOR_RED    "\033[0;31m"
#define ANSI_COLOR_GREEN  "\033[0;32m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

bool get_coefficients(Input type_of_input, double * ptr_a, double * ptr_b, double * ptr_c)
{
	assert(ptr_a != NULL);
	assert(ptr_b != NULL);
	assert(ptr_c != NULL);

	if (type_of_input == kStdin)
	{
		return get_from_console(ptr_a, ptr_b, ptr_c);
	}
	else if (type_of_input == kFileInput)
	{
		return get_from_file(ptr_a, ptr_b, ptr_c);
	}
	else
		return false;
}


bool get_number_from_console(double * ptr)
{
	assert(ptr != NULL);

	int cnt = 0;
	while ((cnt = scanf("%lf", ptr)) != 1 || getchar() != '\n')
	{
		if (cnt == EOF)
		{
			printf("Программа завершена.\n");
			return false;
		}

		printf("Ошибка. Введите ещё раз: ");
		clear_buffer();
	}
	return true;
}


bool get_number_from_file(double * ptr)
{
	FILE * fp = fopen("testfile.txt", "r");

	assert(fp != NULL);
	assert(ptr != NULL);

	if (fscanf(fp, "%lf", ptr) == 1)
	{
		fclose(fp);
		return true;
	}
	else
	{
		printf("Ошибка считывания файла");
		return false;
	}
}


bool get_from_console(double * ptr_a, double * ptr_b, double * ptr_c)
{
	assert(ptr_a != NULL);
	assert(ptr_b != NULL);
	assert(ptr_c != NULL);

	printf(ANSI_COLOR_RED "Введите коэффициент при х^2: ");
	bool if_a = get_number_from_console(ptr_a);
	if (if_a == false)
	{
		return false;
	}

	printf(ANSI_COLOR_GREEN "Введите коэффициент при x: ");
	bool if_b = get_number_from_console(ptr_b);
	if (if_b == false)
		return false;

	printf(ANSI_COLOR_YELLOW "Введите свободный член: ");
	bool if_c = get_number_from_console(ptr_c);
	if (if_c == false)
		return false;

	return true;
}


bool get_from_file(double * ptr_a, double * ptr_b, double * ptr_c)
{
	assert(ptr_a != NULL);
	assert(ptr_b != NULL);
	assert(ptr_c != NULL);

	return get_number_from_file(ptr_a) == true
		&& get_number_from_file(ptr_b) == true
		&& get_number_from_file(ptr_c) == true;
}


void get_from_command_line(bool * ptr_if_cf_correct, int cnt, const char * argv[], double * ptr_a, double * ptr_b, double * ptr_c)
{
	assert(ptr_if_cf_correct != NULL);
	assert(argv != NULL);
	assert(ptr_a != NULL);
	assert(ptr_b != NULL);
	assert(ptr_c != NULL);

	char * endptrA = NULL;
	char * endptrB = NULL;
	char * endptrC = NULL;

	if ((strtod(argv[cnt + 1], &endptrA) == 0 && *endptrA != '\0')
	|| (strtod(argv[cnt + 2],  &endptrB) == 0 && *endptrB != '\0')
	|| (strtod(argv[cnt + 3], &endptrC) == 0 && *endptrC != '\0'))
	{
		printf("Коэффициенты введены некорректно");
		*ptr_if_cf_correct = false;
	}
	else
	{
		*ptr_a = atof(argv[cnt + 1]);
		*ptr_b = atof(argv[cnt + 2]);
		*ptr_c = atof(argv[cnt + 3]);
	}
}


void clear_buffer(void)
{
	while (getchar() != '\n')
		continue;
}

