#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>

#include "Data.h"
#include "Type.h"
#include "Input.h"
#include "Check.h"

Input choose_type_of_input(void)
{
    printf("Введите 0 для ввода с клавиатуры, 1 - для файлового ввода: ");

    Input type_of_input = kDefaultInput;
    int type_of_input_int = 0;

    do {
        double type_of_input_double = 0.0;
        if (!get_number_from_console(&type_of_input_double))
            return kDefaultInput;

        type_of_input_int = (int)type_of_input_double;

        if (!is_num_zero(type_of_input_int - type_of_input_double))
        {
            printf("Введите целое число");
            continue;
        }

    } while (!convert_int_to_input(type_of_input_int, &type_of_input));

    return type_of_input;
}


bool convert_int_to_input(int type_of_input_int, Input * type_of_input)
{
    assert(!isnan(type_of_input_int));
    assert(type_of_input != NULL);

    switch(type_of_input_int)
    {
        case kStdin: *type_of_input = kStdin;
                break;
        case kFileInput: *type_of_input = kFileInput;
                break;
        default: printf("Incorrect input type ");
                return false;
    }
    return true;
}
