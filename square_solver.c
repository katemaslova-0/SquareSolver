// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2);
int calculate_linear_roots(double b, double c, double * ptr_x);
int get_coefficients(double * ptr_a, double * ptr_b, double * ptr_c);
bool check_quadraticity(double a);
void output_roots(double x1, double x2, int quantity_of_roots);
bool is_num_zero(double n);

enum Roots{kNoRoots, kOneRoot, kTwoRoots, kInfinity};


int main(void)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;


	if (get_coefficients(&a, &b, &c) != 0)
	{
		if (check_quadraticity(a) == 1)
		{
			int quantity_of_roots = calculate_quadratic_roots(a, b, c, &x1, &x2);
			output_roots(x1, x2, quantity_of_roots);
		}
			
		else
		{
			int quantity_of_roots = calculate_linear_roots(b, c, &x1);
			output_roots(x1, x2, quantity_of_roots);
		}
	}

	return 0;
}

bool is_num_zero(double n)
{
	if ((- 0.00001 < (n - 0)) && ((n - 0) < 0.00001))
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

int calculate_linear_roots(double b, double c, double * ptr_x)
{
	int quantity_of_roots = 0;

	if (is_num_zero(b) == true && is_num_zero(c) == true)
	{
		quantity_of_roots = kInfinity;
	}
	else if (is_num_zero(b) == true && is_num_zero(c) == false)
			quantity_of_roots = kNoRoots;
	else if (is_num_zero(b) == false)
	{
			*ptr_x = - c / b;
			quantity_of_roots = kOneRoot;
	}
	
	return quantity_of_roots;
}

int get_coefficients(double * ptr_a, double * ptr_b, double * ptr_c)
{
	printf("Введите коэффициент при х^2: ");
	while (scanf("%lf", ptr_a) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		while (getchar() != '\n')
			continue;
	}

	if (getchar() != '\n')
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}

	printf("Введите коэффициент при х: ");
	while (scanf("%lf", ptr_b) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		while (getchar() != '\n')
			continue;
	}

	if (getchar() != '\n')
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}

	printf("Введите свободный член: ");
	while (scanf("%lf", ptr_c) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		while (getchar() != '\n')
			continue;
	}

	if (getchar() != '\n')
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}

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
	
	int quantity_of_roots = 0;
	
	if (discriminant < 0)
		quantity_of_roots = kNoRoots;

	else if (is_num_zero(discriminant) == true)
		quantity_of_roots = kOneRoot;
	else
		quantity_of_roots = kTwoRoots;

	return quantity_of_roots;
}

void output_roots(double x1, double x2, int quantity_of_roots)
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
	}
}



























