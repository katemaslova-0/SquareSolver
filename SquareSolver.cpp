// SquareSolver
/* @brief Решает квадратные уравнения
*
* @details Эта программа решает квадратные уравнения
* при помощи дискриминанта. Если старший коэффициент
* равен 0, программа также решает линейный случай. При
* некорректном вводе коэффициента программа запрашивает
* его повторно. При вводе EOF программа завершается.
*
* @param [in] a Коэффициент при x^2
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @return Количество корней и корни квадратного уравнения
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

enum Roots{kNoRoots, kOneRoot, kTwoRoots, kInfinity, kStart};

Roots calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2);
Roots calculate_linear_roots(double b, double c, double * ptr_x);
bool get_coefficient(double * ptr);
bool check_square(double a);
void output_roots(double x1, double x2, Roots quantity_of_roots);
bool is_num_zero(double n);
bool get_function_for_coefficients(double * ptr_a, double * ptr_b, double * ptr_c);


int main(void)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;

	if (get_function_for_coefficients(&a, &b, &c) == true)
	{
		assert(a != NAN);
		assert(b != NAN);
		assert(c != NAN);

		if (check_square(a) == true)
		{
			Roots quantity_of_roots = calculate_quadratic_roots(a, b, c, &x1, &x2);
			output_roots(x1, x2, quantity_of_roots);
		}

		else
		{
			Roots quantity_of_roots = calculate_linear_roots(b, c, &x1);
			output_roots(x1, x2, quantity_of_roots);
		}
	}
	return 0;
}

/*
* @brief Проверяет равенство введённого числа нулю
*
* @param [in] n Число, проверяемое на равенство нулю
*
* @return true, если число равно нулю
*		  false, если число не равно нулю
*
*/

bool is_num_zero(double n)
{
	assert(n != NAN);
	return (fabs(n) < 0.00001);
}

/*
* @brief Проверяет равенство старшего коэффициента уравнения нулю
*
* @param [in] a Старший коэффициент уравнения
*
* @return true, если старший коэффициент не равен нулю
* 		  false, если старший коэффициент равен нулю
*/

bool check_square(double a)
{
	assert(a != NAN);
	if (is_num_zero(a) == false)
		return true;

	else
		return false;
}

/*
* @brief Считает корни уравнения в линейном случае
*
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @param [out] ptr_x Указатель на корень уравнения
*
* @return Количество корней
*/

Roots calculate_linear_roots(double b, double c, double * ptr_x)
{
	assert(b != NAN);
	assert(c != NAN);
	assert(ptr_x != NULL);

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

/*
* @brief Считывает коэффициенты уравнения
*
* @param [out] ptr Указатель на коэффициент
*
* @return true, если коэффициент успешно считан,
*		  false в обратном случае
*/

bool get_coefficient(double * ptr)
{
	assert(ptr != NULL);
	int cnt = 0;
	while ((cnt = scanf("%lf", ptr)) != 1 || getchar() != '\n')
	{
		if (cnt == EOF)
		{
			printf("Программа завершена.\n");
			return false;
			break;
		}
		printf("Ошибка. Введите ещё раз: ");
		while (getchar() != '\n')
			continue;
	}
	return true;
}

/*
* @brief Считает корни в случае, если уравнение является квадратным
*
* @param [in] a Коэффициент при x^2
* @param [in] b Коэффициент при x
* @param [in] c Свободный член
*
* @param [out] ptr_x1 Указатель на первый корень
* @param [out] ptr_x2 Указатель на второй корень
*
* @return Количество корней
*/

Roots calculate_quadratic_roots(double a, double b, double c, double * ptr_x1, double * ptr_x2)
{
	assert(ptr_x1 != NULL);
	assert(ptr_x2 != NULL);

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

/*
* @brief Выводит корни уравнения
*
* @param [in] x1 Первый корень уравнения
* @param [in] x2 Второй корень уравнения
* @param [in] quantity_of_roots Количество корней
*
*/

void output_roots(double x1, double x2, Roots quantity_of_roots)
{
	assert(x1 != NAN);
	assert(x2 != NAN);
	assert(quantity_of_roots != NAN);

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

/*
* @brief Запрашивает ввод коэффициентов
*
* @param [out] ptr_a Указатель на коэффициент при x^2
* @param [out] ptr_b Указатель на коэффициент при x
* @param [out] ptr_c Указатель на свободный член
*
* @return true, если коэффициенты успешно считаны,
*        false в противном случае
*/

bool get_function_for_coefficients(double * ptr_a, double * ptr_b, double * ptr_c)
{
	assert(ptr_a != NULL);
	assert(ptr_b != NULL);
	assert(ptr_c != NULL);

	printf("Введите коэффициент при х^2: ");
	bool if_a = get_coefficient(ptr_a);
	if (if_a == false)
		return false;

	printf("Введите коэффициент при x: ");
	bool if_b = get_coefficient(ptr_b);
	if (if_b == false)
		return false;

	printf("Введите свободный член: ");
	bool if_c = get_coefficient(ptr_c);
	if (if_c == false)
		return false;

	return true;
}
