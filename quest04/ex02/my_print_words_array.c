/*
**
** QWASAR.IO -- my_print_words_array
**
** @param {string_array*} param_1
**
** @return {void}
**
*/
#include <unistd.h>
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

void	my_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void my_print_words_array(string_array* param_1)
{
    int i;
    int len;
    char **d;

    i = 0;
    len = param_1->size;
    d = param_1->array;

    while (i < len)
    {
        my_putstr(d[i++]);
        my_putstr("\n");
    }
}