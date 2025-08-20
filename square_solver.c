// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

enum Roots{kNoRoots, kOneRoot, kTwoRoots, kInfinity, kStart};

Roots calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2);
Roots calculate_linear_roots(double b, double c, double * ptr_x);
void get_coefficient(double * ptr);
bool check_quadraticity(double a);
void output_roots(double x1, double x2, Roots quantity_of_roots);
bool is_num_zero(double n);
void get_function_for_coefficients(double * ptr_a, double * ptr_b, double * ptr_c);


int main(void)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;

	get_function_for_coefficients(&a, &b, &c);

	if (check_quadraticity(a) == true)
	{
		Roots quantity_of_roots = calculate_quadratic_roots(a, b, c, &x1, &x2);
		output_roots(x1, x2, quantity_of_roots);
	}
			
	else
	{
		Roots quantity_of_roots = calculate_linear_roots(b, c, &x1);
		output_roots(x1, x2, quantity_of_roots);
	}

	return 0;
}


bool is_num_zero(double n)
{
	if (fabs(n - 0) < 0.00001)
		return true;

	else
		return false;
}


bool check_quadraticity(double a)
{
	if (is_num_zero(a) == 0)
		return true;

	else
		return false;
}


Roots calculate_linear_roots(double b, double c, double * ptr_x)
{
	Roots quantity_of_roots = kStart;

	if (is_num_zero(b) == true && is_num_zero(c) == true)
		quantity_of_roots = kInfinity;

	else if (is_num_zero(b) == true && is_num_zero(c) == false)
			quantity_of_roots = kNoRoots;

	else if (is_num_zero(b) == false)
	{
			*ptr_x = - c / b;
			quantity_of_roots = kOneRoot;
	}

	return quantity_of_roots;
}


void get_coefficient(double * ptr)
{
	while (scanf("%lf", ptr) != 1 || getchar() != '\n')
	{
		printf("Ошибка. Введите ещё раз: ");
		while (getchar() != '\n')
			continue;
	}
}


Roots calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2)
{
	double discriminant = b * b - 4 * a * c;
	double sqr_discr = 0.0;

	if (discriminant >= 0)
		sqr_discr = sqrt(discriminant);
	
	Roots quantity_of_roots = kStart;
	
	if (discriminant < 0)
		quantity_of_roots = kNoRoots;

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


void output_roots(double x1, double x2, Roots quantity_of_roots)
{
	switch(quantity_of_roots)
	{
		case kNoRoots: printf("Уравнение не имеет решений\n");
			break;
		case kOneRoot: printf("Уравнение имеет одно решение: %.2f\n", x1);
			break;
		case kTwoRoots: printf("Уравнение имеет два решения: %.2f и %.2f\n", x1, x2);
			break;
		case kInfinity: printf("Уравнение имеет бесконечное множество решений\n");
			break;
		case kStart: printf("Ошибка");
			break;
		default: printf("Ошибка");
	}
}


void get_function_for_coefficients(double * ptr_a, double * ptr_b, double * ptr_c)
{
	printf("Введите коэффициент при х^2: ");
	get_coefficient(ptr_a);

	printf("Введите коэффициент при x: ");
	get_coefficient(ptr_b);

	printf("Введите свободный член: ");
	get_coefficient(ptr_c);
}































