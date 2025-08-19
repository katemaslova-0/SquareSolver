// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2);
int calculate_linear_roots(double b, double c, double * ptr_x);
int get_coefficients(double * ptr_a, double * ptr_b, double * ptr_c);
int check_quadraticity(double a);
void output_quadratic_roots(double x1, double x2, int quantity_of_roots_sqr);
void output_linear_roots(double x, int quantity_of_roots_lin);
int is_num_zero(double n);


int main(void)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;

	int quantity_of_roots_sqr = 0;
	int quantity_of_roots_lin = 0;

	if (get_coefficients(&a, &b, &c) != 0)
	{
		if (check_quadraticity(a) == 1)
		{
			quantity_of_roots_sqr = calculate_quadratic_roots(a, b, c, &x1, &x2);
			output_quadratic_roots(x1, x2, quantity_of_roots_sqr);
		}
		else
		{
			quantity_of_roots_lin = calculate_linear_roots(b, c, &x1);
			output_linear_roots(x1, quantity_of_roots_lin);
		}
	}

	return 0;
}

int is_num_zero(double n)
{
	if ((- 0.00001 < (n - 0)) && ((n - 0) < 0.00001))
		return 1;
	else
		return 0;
}


int check_quadraticity(double a)
{
	if (coefficient_0_or_not(a) == 0)
		return 1;
	else
		return 0;
}

int calculate_linear_roots(double b, double c, double * ptr_x)
{
	if (is_num_zero(b) == 1 && is_num_zero(c) == 1)
			return 2;
	else if (is_num_zero(b) == 1 && is_num_zero(c) == 0)
			return 0;
	else if (is_num_zero(b) == 0)
	{
			*ptr_x = - c / b;
			return 1;
	}
	else
			return 3;
}

void output_linear_roots(double x, int quantity_of_roots_lin)
{
	if (quantity_of_roots_lin == 2)
		printf("Уравнение имеет бесконечное множество решений\n");
	else if (quantity_of_roots_lin == 0)
		printf("Уравнение не имеет решений\n");
	else if (quantity_of_roots_lin == 1)
		printf("Уравнение имеет одно решение: %lf\n", x);
}


int get_coefficients(double * ptr_a, double * ptr_b, double * ptr_c)
{
	printf("Введите коэффициент при х^2: ");
	if (scanf("%lf", ptr_a) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}
	printf("Введите коэффициент при х: ");
	if (scanf("%lf", ptr_b) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}
	printf("Введите свободный член: ");
	if (scanf("%lf", ptr_c) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}
	else
		return 1;
}


int calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2)
{
	double discriminant = b * b - 4 * a * c;
	double sqr_discr = 0.0;
	if (discriminant >= 0)
		sqr_discr = sqrt(discriminant);
	*ptr_x1 = (- b + sqr_discr) / 2 / a;
	*ptr_x2 = (- b - sqr_discr) / 2 / a;
	
	if (discriminant < 0)
		return 0;
	else if (coefficient_0_or_not(discriminant) == 1)
		return 1;
	else
		return 2;
}

void output_quadratic_roots(double x1, double x2, int quantity_of_roots_sqr)
{
	if (quantity_of_roots_sqr == 0)
	printf("Уравнение не имеет решений\n");
	else if (quantity_of_roots_sqr == 1)
	printf("Уравнение имеет одно решение: %.2f\n", x1);
	else if (quantity_of_roots_sqr == 2)
	printf("Уравнение имеет два решения: %.2f и %.2f\n", x1, x2);
}






















