// решение квадратных уравнений

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calc(double a, double b, double c, double discriminant);
double get_numbers(double n);
void check(double a);

int main(void)
{
	double a, b, c; //коэффициенты при x^2, x и свободный член соответственно
	double discriminant;
	
	printf("Введите коэффициент при x^2: ");
	a = get_numbers(a);

	check(a);

	printf("Введите коэффициент при x: ");
	b = get_numbers(b);

	printf("Введите свободный член: ");
	c = get_numbers(c);
	
	calc(a, b, c, discriminant);
	
	
return 0;
}

void check(double a)
{
	if (a==0)
	{
		printf("Уравнение не является квадратным\n");
		exit(1);
	}
}

double get_numbers(double n)
{
	if (scanf("%lf", &n) != 1)
	{
		printf("Ошибка. Попробуйте ещё раз.");
		exit(1);
	}
	return(n);
}

void calc(double a, double b, double c, double discriminant)
{
discriminant = b*b - 4 * a * c;
if (discriminant < 0)
printf("Уравнение не имеет решений\n");
if (discriminant == 0)
printf("Уравнение имеет одно решение: %.2f\n", (-b)/2/a);
if (discriminant > 0)
printf("Уравнение имеет два решения: %.2f и %.2f\n", ((-b)+sqrt(discriminant))/2/a, (-b-sqrt(discriminant))/2/a);	
}