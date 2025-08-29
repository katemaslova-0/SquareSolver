#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <cassert>
#include <cstring>

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

bool get_flags(int * ptr_tag_count, int argc, const char * argv[], Flags * current_flags)
{
    assert(ptr_tag_count != NULL);
    assert(argv != NULL);
    assert(current_flags != NULL);
    assert(!isnan(argc));

	int cnt_argc = argc;
	int cnt = 0;

	for (cnt = 0; cnt_argc > 0; cnt++, cnt_argc--)
	{
		if (strcmp(argv[cnt], "--help") == 0)
			current_flags->show_flags = true;
		if (strcmp(argv[cnt], "--test") == 0)
			current_flags->test_flag = true;
		if (strcmp(argv[cnt], "--cf") == 0)
        {
			current_flags->cf_flag = true;
            *ptr_tag_count = cnt;
        }
	}

    if (current_flags->show_flags == false
     && current_flags->test_flag  == false
     && current_flags->cf_flag    == false)
        return false;
    else
        return true;
}
