/*
**
** QWASAR.IO -- my_count_on_it
**
** @param {string_array*} param_1
**
** @return {integer_array*}
**
*/
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

int	my_strlen(char *s)
{
	int	size;

	size = 0;
	while (*s++ != '\0')
	{
		size++;
	}
	return (size);
}

integer_array* my_count_on_it(string_array* param_1)
{
    integer_array *result;
    int i;

    result = malloc(sizeof(integer_array)* (param_1->size + 1));
    result->size = param_1->size;
    result->array = malloc(sizeof(int) * (param_1->size + 1));
    i = 0;
    while (i < result->size)
    {
        result->array[i] = my_strlen(param_1->array[i]);
        i++;
    }
    return (result);

}