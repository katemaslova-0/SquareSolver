// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc(double a, double b, double c,  double * ptr_x, double * ptr_x1, double * ptr_x2, double * ptr_discr, double * ptr_sqr_discr);
int get_number(double * ptr);
int check(double a, double b, double c);
void output(double * ptr_x, double * ptr_x1, double * ptr_x2, double *ptr_discr);


int main(void)
{
	double a, b, c, x, x1, x2, discriminant, sqr_discr;
	double * ptr_a;
	double * ptr_b;
	double * ptr_c;
	double * ptr_x;
	double * ptr_x1;
	double * ptr_x2;
	double * ptr_discr;
	double *ptr_sqr_discr;
	
	ptr_a = &a;
	ptr_b = &b;
	ptr_c = &c;
	ptr_x = &x;
	ptr_x1 = &x1;
	ptr_x2 = &x2;
	ptr_discr = &discriminant;
	ptr_sqr_discr = &sqr_discr;

	
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
					calc(a, b, c, ptr_x, ptr_x1, ptr_x2, ptr_discr, ptr_sqr_discr);
					output(ptr_x, ptr_x1, ptr_x2, ptr_discr);
				}
			}
		}
	}
	return 0;
}


int check(double a, double b, double c)
{
	if (a == 0 && b == 0 && c == 0)
		printf("Уравнение не имеет бесконечное множество решений\n");
	else if (a == 0 && b == 0 && c != 0)
		printf("Уравнение не имеет решений\n");
	else if (a == 0 && b != 0)
		printf("Уравнение имеет одно решение: %lf\n", -c/b);

	if (a != 0)
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


void calc(double a, double b, double c, double * ptr_x, double * ptr_x1, double * ptr_x2, double * ptr_discr, double * ptr_sqr_discr)
{
	*ptr_discr = b * b - 4 * a * c;
	*ptr_sqr_discr = sqrt(*ptr_discr);
	*ptr_x = (- b) / 2 /a;
	*ptr_x1 = (- b + *ptr_sqr_discr) / 2 / a;
	*ptr_x2 = (- b - *ptr_sqr_discr) / 2 / a;
}

void output(double * ptr_x, double * ptr_x1, double * ptr_x2, double * ptr_discr)
{
	if (*ptr_discr < 0)
	printf("Уравнение не имеет решений\n");
	if (*ptr_discr == 0)
	printf("Уравнение имеет одно решение: %.2f\n", *ptr_x);
	if (*ptr_discr > 0)
	printf("Уравнение имеет два решения: %.2f и %.2f\n", *ptr_x1, *ptr_x2);
}











