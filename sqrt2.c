// решение квадратных уравнений

#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c; //коэффициенты при x^2, x и свободный член соответственно
	double discriminant;
	
	printf("Введите коэффициент при x^2: ");

	while (scanf("%lf", &a) == 1)
       	{

		if (a==0)
		{
			printf("Уравнение не является квадратным\n");
			printf("Введите коэффициент при x^2: ");
			continue;
		}

		printf("Введите коэффициент при x: ");

		if (scanf("%lf", &b) == 1)
		{
			printf("Введите свободный член: ");

			if (scanf("%lf", &c) == 1)
			{
				discriminant = b*b - 4 * a * c;

				if (discriminant < 0)
				printf("Уравнение не имеет решений\n");
				if (discriminant == 0)
				printf("Уравнение имеет одно решение: %.2f\n", (-b)/2/a);
				if (discriminant > 0)
				printf("Уравнение имеет два решения: %.2f и %.2f\n", ((-b)+sqrt(discriminant))/2/a, (-b-sqrt(discriminant))/2/a);
				
			}

		}

		printf("Введите коэффициент при x^2: ");
	}
	
return 0;
}