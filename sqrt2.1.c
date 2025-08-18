// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc(double a, double b, double c, double discriminant, double * ptr_x, double * ptr_x1, double * ptr_x2);
double get_numbers(void);
int check(double a, double b, double c);
double * ptr_x;
double * ptr_x1;
double * ptr_x2;

int main(void)
{
	double a, b, c; //коэффициенты при x^2, x и свободный член соответственно
	double discriminant;
	
	printf("Введите коэффициент при x^2: ");
	a = get_numbers();
	
	printf("Введите коэффициент при x: ");
	b = get_numbers();

	printf("Введите свободный член: ");
	c = get_numbers();

	if (check(a, b, c) == 1)
		calc(a, b, c, discriminant);
	
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
	else
		return 0;
}


double get_numbers(void)
{
	double n;
	if (scanf("%lf", &n) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
	}
	else
		return(n);
}


void calc(double a, double b, double c, double discriminant, double * ptr_x, double * ptr_x1, double * ptr_x2)
{
	discriminant = b * b - 4 * a * c;
	double sqr_d = sqrt(discriminant);
	*ptr_x = (- b) / 2 /a;
	*ptr_x1 = (- b + sqr_d) / 2 / a;
	*ptr_x2 = (- b - sqr_d) / 2 / a;
}

void output(double * ptr_x, double * ptr_x1, double * ptr_x2)
{
	if (discriminant < 0)
	printf("Уравнение не имеет решений\n");
	if (discriminant == 0)
	printf("Уравнение имеет одно решение: %.2f\n", *ptr_x);
	if (discriminant > 0)
	printf("Уравнение имеет два решения: %.2f и %.2f\n", *ptr_x1, *ptr_x2);
}



