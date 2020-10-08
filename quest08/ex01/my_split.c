/*
**
** QWASAR.IO -- my_split
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {string_array*}
**
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
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

int is_in(char *s1, char *s2)
{
    int i;
    int j;
    int index;

    i = 0;
    j = 0;
    index = 0;
    while (i < my_strlen(s1))
    {
        j = 0;
        while (s1[i] != s2[j])
            i++;
        if (i == my_strlen(s1))
            return (-1);
        index = i;
        while (j < my_strlen(s2))
        {
            if (s1[i] != s2[j])
                break;

            j++;
            i++;
        }
        if (j == my_strlen(s2))
            return (index);
        i++;
    }
    return (-1);
}

int	my_countwords(char *s1, char *s2)
{
	int	count;

	count = 0;
	if (!s1)
		return (0);
	while (*s1 != '\0')
	{
		if (is_in(s1, s2) != -1)
        {
			count++;
            s1 = s1 + (is_in(s1, s2) + 1);
            continue;
        }
		s1++;
	}
	return (count);
}

string_array* my_split(char* param_1, char* param_2)
{
    char	**arr;
    char    *para;
	int     count;
	int     index;
	int		i;
    int     j;
    int     len1;
    int     len2;
    string_array    *result;

    len1 = my_strlen(param_1);
    len2 = my_strlen(param_2);
	if (!*param_1)
		return (NULL);
    if ( len1 <= len2)
        return (NULL);
	count = my_countwords(param_1, param_2);
    result =(string_array *)malloc(sizeof(string_array)* (count + 1));
    result->size = count;
    result->array = (char **)malloc((count + 1) * sizeof(char *));
	if (!(arr = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	arr[count] = NULL;
	index = 0;
	i = 0;
    j = 0;
	while (count > i && param_1)
	{
        j = 0;
        index = is_in(param_1, param_2);
        para = param_1;
        param_1 += index + 1;
        arr[i] = (char *)malloc(200);
        while (index > j)
        {
            arr[i][j++] = *para;
            para++;
        }
        i++;
     }
    result->array = arr;
	return (result);
}