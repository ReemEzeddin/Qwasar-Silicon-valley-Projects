/*
**
** QWASAR.IO -- my_robot_simulator
**
** @param {char*} param_1
**
** @return {char*}
**
*/

#include <stdlib.h>
#include <stdio.h>

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

char* my_robot_simulator(char* param_1)
{
    int     x;
    int     y;
    char    *result;
    int     size;
    int     i;
    int     r;
    char    *dir;
    int     d;

    r = 0;
    y = 0;
    x = 0;
    i = 0;
    d = 0;
    size = my_strlen(param_1);
    result = (char *)malloc(250);
    dir = (char *)malloc(50);
    if (!param_1)
    {
        result = "{x: 0, y: 0, bearing: 'north'}";
        return (result);
    }
    while (i < size)
    {
        if (param_1[i] == 'A')
        {
            if (d % 2 == 0)
            {
                if (d == 0)
                    y--;
                else
                    y++;
            }
            else if (d == 1)
                x++;
            else
                x--;
        }
        if (param_1[i] == 'L')
            d--;
        if (param_1[i] == 'R')
        {
            r++;
            d++;
        }
        if (r == 4)
            r = 0;
        if (d == 4 || d == -4)
            r = 0;
        i++;
    }
    if (d == 0)
        dir = "'north'";
    if (d == 1 || d == -3)
        dir = "'east'";
    if (d == 2 || d == -2)
        dir = "'south'";
    if (d == 3 || d == -1)
        dir = "'west'";
    i = snprintf(result, 250, "{x: %d, y: %d, bearing: %s}", x, y, dir);
    return (result);
}