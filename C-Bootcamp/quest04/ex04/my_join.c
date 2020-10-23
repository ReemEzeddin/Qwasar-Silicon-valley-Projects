/*
**
** QWASAR.IO -- my_join
**
** @param {string_array*} param_1
** @param {char*} param_2
**
** @return {char*}
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

void    my_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

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
char* my_join(string_array* param_1, char* param_2)
{
    char *result;
    char *retur;
    int i;
    int size;

    size = 0;
    i = 0;
    while (param_1->size > i)
    {
        size += my_strlen(param_1->array[i]);
    if (i != param_1->size - 1)
         size += my_strlen(param_2);
    i++;
    }
    
    result = (char *)malloc(sizeof (char) * (size + 1));
    retur = result;
    i = 0;
    if (!param_1->array[i])
        return (NULL);
    while (param_1->size > i)
    {
        if (param_1->array[i])
        {
            my_strcpy (result, param_1->array[i] );
            result += my_strlen(param_1->array[i]);
        }
        if (param_1->array[i + 1])
        {
              my_strcpy (result, param_2);
              result += my_strlen(param_2);
        }
        i++;
    }
    return (retur);
}