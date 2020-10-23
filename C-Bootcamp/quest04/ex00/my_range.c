/*
**
** QWASAR.IO -- my_range
**
** @param {int} param_1
** @param {int} param_2
**
** @return {int*}
**
*/
#include <stdlib.h>

int* my_range(int param_1, int param_2)
{
    int    *range;
    int     size;

    size = param_2 - param_1;
    if (size <= 0)
        return (NULL);
    range = (int *)malloc(size * sizeof(int) + 1);
    if (!range)
        return (NULL);
    while (size > 0)
    {
        range[size - 1] = --param_2;
        size--;
    }
    return (range);
}