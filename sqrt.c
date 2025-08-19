// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2);
int get_coefficients(double * ptr_a, double * ptr_b, double * ptr_c);
int check_quadraticity(double a, double b, double c);
void output_roots(double x1, double x2, int quantity_of_roots);
int coefficient_0_or_not(double n);


int main(void)
{
	double a, b, c, x1, x2;
	int quantity_of_roots;

	if (get_coefficients(&a, &b, &c) != 0)
	{
		if (check_quadraticity(a, b, c) == 1)
		{
			quantity_of_roots = calculate_roots(a, b, c, &x1, &x2);
			output_roots(x1, x2, quantity_of_roots);
		}
	}

	return 0;
}

int coefficient_0_or_not(double n)
{
	if ((- 0.00001 < (n - 0)) && ((n - 0) < 0.00001))
		return 1;
	else
		return 0;
}


int check_quadraticity(double a, double b, double c)
{
	if (coefficient_0_or_not(a) == 1 && coefficient_0_or_not(b) == 1 && coefficient_0_or_not(c) == 1)
		printf("Уравнение имеет бесконечное множество решений\n");
	else if (coefficient_0_or_not(a) == 1 && coefficient_0_or_not(b) == 1 && coefficient_0_or_not(c) == 0)
		printf("Уравнение не имеет решений\n");
	else if (coefficient_0_or_not(a) == 1 && coefficient_0_or_not(b) == 0)
		printf("Уравнение имеет одно решение: %lf\n", -c/b);

	if (coefficient_0_or_not(a) == 0)
		return 1;
	else
		return 0;
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


int calculate_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2)
{
	double discriminant;
	discriminant = b * b - 4 * a * c;
	double sqr_discr;
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

void output_roots(double x1, double x2, int quantity_of_roots)
{
	if (quantity_of_roots == 0)
	printf("Уравнение не имеет решений\n");
	else if (quantity_of_roots == 1)
	printf("Уравнение имеет одно решение: %.2f\n", x1);
	else if (quantity_of_roots == 2)
	printf("Уравнение имеет два решения: %.2f и %.2f\n", x1, x2);
}

















