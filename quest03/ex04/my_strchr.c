/*
**
** QWASAR.IO -- my_strchr
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {char*}
**
*/
#include <unistd.h>
char* my_strchr(char* param_1, char param_2)
{
    while (*param_1 != param_2)
		if (!*param_1++)
			return (NULL);
	return param_1;
}