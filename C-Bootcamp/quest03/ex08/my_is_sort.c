/*
**
** QWASAR.IO -- my_is_sort
**
** @param {integer_array*} param_1
**
** @return {bool}
**
*/
#include <stdbool.h>
#include <stdio.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

bool my_is_sort(integer_array* param_1)
{
    int x;
    int i;
    
    if (!param_1->array || param_1->size == 0)
        return (true);
    i = 0;
    x = 0;
    while (x == 0 && i < param_1->size)
    {
        x = param_1->array[i + 1] - param_1->array[i];
        i++;
    }
    i = 0;
    if (x > 0)
        while (i < param_1->size)
        {
            if ((param_1->array[i + 1] < param_1->array[i]) && (i+ 1 < param_1->size))
                return (false);
            i++;
        }
    if (x < 0)
        while (i < param_1->size)
        {
            if ((param_1->array[i + 1] > param_1->array[i]) && (i + 1 < param_1->size))
                return (false);
            i++;
        }
    return (true);
}