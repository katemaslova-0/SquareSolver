#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double a, b, c; //коэффициенты при x^2, x и свободный член соответственно
	double discriminant;
	char str_a[40];
	char * end;
	printf("Введите коэффициент при x^2: ");
	fgets(str_a, 40, stdin);
	a = strtod(str_a, &end);

	while(*end != '\n')
	{
		printf("Программа завершена. Заново введите коэффициент при x^2: ");
		fgets(str_a, 40, stdin);
		a = strtod(str_a, &end);
	}

	while (*end == '\n')
        {
		if (a==0)
		{
			printf("Уравнение не является квадратным\n");
			printf("Введите коэффициент при x^2: ");
			fgets(str_a, 40, stdin);
			a = strtod(str_a, &end);
		}

		printf("Введите коэффициент при x: ");
		char str_b[40];
		fgets(str_b, 40, stdin);
		b = strtod(str_b, &end);

		if (*end == '\n')
		{
			printf("Введите свободный член: ");
			char str_c[40];
			fgets(str_c, 40, stdin);
			c = strtod(str_c, &end);

			if (*end == '\n')
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

		printf("Программа завершена.Заново введите коэффициент при x^2: ");
		char str_a[40];
		fgets(str_a, 40, stdin);
		a = strtod(str_a, &end);

		while(*end != '\n')
		{
		printf("Программа завершена. Заново введите коэффициент при x^2: ");
		fgets(str_a, 40, stdin);
		a = strtod(str_a, &end);
		}
	}

return 0;
}