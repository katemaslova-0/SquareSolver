// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calc(double a, double b, double c,  double * ptr_x, double * ptr_x1, double * ptr_x2);
int get_number(double * ptr);
int check(double a, double b, double c);
void output(double * ptr_x, double * ptr_x1, double * ptr_x2, int quantity_of_roots);


int main(void)
{
	double a, b, c, x, x1, x2;
	int quantity_of_roots;
	double * ptr_a;
	double * ptr_b;
	double * ptr_c;
	double * ptr_x;
	double * ptr_x1;
	double * ptr_x2;
	
	ptr_a = &a;
	ptr_b = &b;
	ptr_c = &c;
	ptr_x = &x;
	ptr_x1 = &x1;
	ptr_x2 = &x2;

	
	printf("Введите коэффициент при x^2: ");
	if (get_number(ptr_a) != 0)
	{
		printf("Введите коэффициент при x: ");
		if (get_number(ptr_b) != 0)
		{
			printf("Введите свободный член: ");
			if (get_number(ptr_c) != 0)
			{
				if (check(a, b, c) == 1)
				{
					quantity_of_roots = calc(a, b, c, ptr_x, ptr_x1, ptr_x2);
					output(ptr_x, ptr_x1, ptr_x2, quantity_of_roots);
				}
			}
		}
	}
	return 0;
}


int check(double a, double b, double c)
{
	if (a == 0.0 && b == 0.0 && c == 0.0)
		printf("Уравнение не имеет бесконечное множество решений\n");
	else if (a == 0.0 && b == 0.0 && c != 0.0)
		printf("Уравнение не имеет решений\n");
	else if (a == 0.0 && b != 0.0)
		printf("Уравнение имеет одно решение: %lf\n", -c/b);

	if (a != 0.0)
		return 1;
}


int get_number(double * ptr)
{
	if (scanf("%lf", ptr) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		return 0;
	}
	else
		return 1;
}


int calc(double a, double b, double c, double * ptr_x, double * ptr_x1, double * ptr_x2)
{
	double discriminant;
	discriminant = b * b - 4 * a * c;
	double sqr_discr;
	sqr_discr = sqrt(*ptr_discr);
	*ptr_x = (- b) / 2 /a;
	*ptr_x1 = (- b + sqr_discr) / 2 / a;
	*ptr_x2 = (- b - sqr_discr) / 2 / a;
	
	if (discriminant < 0)
		return 0;
	else if (discriminant == 0)
		return 1;
	else
		return 2;
}

void output(double * ptr_x, double * ptr_x1, double * ptr_x2, int quantity_of_roots)
{
	if (quantity_of_roots == 0)
	printf("Уравнение не имеет решений\n");
	else if (quantity_of_roots == 1)
	printf("Уравнение имеет одно решение: %.2f\n", *ptr_x);
	else if (quantity_of_roots == 2)
	printf("Уравнение имеет два решения: %.2f и %.2f\n", *ptr_x1, *ptr_x2);
}












