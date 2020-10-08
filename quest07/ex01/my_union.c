/*
**
** QWASAR.IO -- my_union
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {char*}
**
*/
#include <unistd.h>
#include <stdlib.h>

char* my_union(char* param_1, char* param_2)
{
    int     i;
    int     j;
    int     x;
    int     k;
    int     flag;
    char    *uni;

    if (!param_1 && !param_2)
        return (NULL);
    
    i = 0;
    j = 0;
    x = 0;
    k = 0;
    flag = 1;
    uni = (char *)malloc(200);
    while (param_1[i] != '\0')
    {
        k = 0;
        flag = 1;
        while (uni[k] != '\0')
        {
            if (uni[k] == param_1[i])
            {
                flag = 0;
                break;
            }
            k++;
        }
        if (flag == 1)
            uni[x++] = param_1[i];
        i++;
    }
    i = 0;
    while(param_2[j] != '\0')
    {
        i = 0;
        flag = 1;
        while (param_1[i] != '\0')
        {
            if (param_2[j] == param_1[i])
            {
                flag = 0;
                break;
            }
            i++;
        }
        if (flag == 1)
        {
            k = 0;
            while (uni[k] != '\0')
            {
                if (uni[k] == param_2[j])
                {
                    flag = 0;
                    break;
                }
                k++;
            }

        }
        if (flag == 1)
            uni[x++] = param_2[j];
        j++;
    }
    return (uni);
}