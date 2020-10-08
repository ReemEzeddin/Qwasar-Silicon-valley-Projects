/*
**
** QWASAR.IO -- my_strip
**
** @param {char*} param_1
**
** @return {char*}
**
*/
#include <unistd.h>
#include <stdlib.h>

char* my_strip(char* param_1)
{	int	    i;
	int	    flag;
	int	    x;
    int     j;
    char    *result;

    result = (char *)malloc(200);
	if (!param_1)
	{
        return (NULL);
	}
	i = 0;
	flag = 0;
	x = 0;
    j = 0;
	while (param_1[i] != '\0')
	{
		if (param_1[i] != ' ' && param_1[i] != '\t')
			x++;
		i++;
	}
	i = 0;
	while (param_1[i] != '\0')
	{
		if (param_1[i] != ' ' && param_1[i] != '\t')
		{
			result[j++] = param_1[i];
			x--;
			if ((param_1[i+1] ==  ' ' || param_1[i+1] == '\t') && x != 0)
			   	result[j++] = ' ';
		}
		i++;
	}
	return (result);
}