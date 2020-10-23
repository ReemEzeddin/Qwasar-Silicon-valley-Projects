/*
**
** QWASAR.IO -- inter
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {char*}
**
*/
#include <unistd.h>
#include <stdlib.h>

int		is_in(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char* inter(char* param_1, char* param_2)
{
    int		i;
	int		j;
    int     x;
    char    *inter;

	i = 0;
    j = 0;
    x = 0;
    inter = (char *)malloc(200);
	while (param_1[i])
	{
		if (is_in(inter, param_1[i]) == 1)
		{
			j = 0;
			while (param_2[j])
			{
				if (param_2[j] == param_1[i])
				{
					inter[x++] = param_1[i];
					break ;
				}
				j++;
			}
		}
		i++;
	}
    return (inter);
}