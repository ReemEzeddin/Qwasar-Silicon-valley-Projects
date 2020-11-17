/*
**
** QWASAR.IO -- my_string_index
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {int}
**
*/

int my_string_index(char* param_1, char param_2)
{
    int i;

    i = 0;
    while (*param_1 != '\0')
    {
        if (*param_1 == param_2)
            return (i);
        param_1++;
        i++;
    }
    return (-1);
}