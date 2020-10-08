/*
**
** QWASAR.IO -- hidenp
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {int}
**
*/
int is_in(char *s, char x, int i)
{
    if (!s || !x)
        return (-1);
    while (s[i] != '\0')
    {
        if (s[i] == x)
            return (i);
        i++;
    }
    return (-1);
}

int hidenp(char* param_1, char* param_2)
{
    int     i;
    int     j;
    int     x;

    i = 0;
    j = 0;
    x = 0;
    if (!param_1)
        return (1);
    if (!param_2)
        return (0);
    while (param_1[i] != '\0')
    {
        x = is_in(param_2, param_1[i], j);
        if (x == -1)
            return (0);
        j = x;
        i++;
    }
    return (1);
}