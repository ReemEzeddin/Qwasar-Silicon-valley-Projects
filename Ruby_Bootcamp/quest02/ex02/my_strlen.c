/*
**
** QWASAR.IO -- my_strlen
**
** @param {char*} param_1
**
** @return {int}
**
*/

int my_strlen(char* param_1)
{
    int len;

    len = 0;
    while (*param_1++ != '\0')
        len++;
    return len;
}