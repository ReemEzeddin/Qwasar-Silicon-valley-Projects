/*
**
** QWASAR.IO -- my_strrchr
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {char*}
**
*/
#include <unistd.h>
char* my_strrchr(char* param_1, char param_2)
{
char	*last;

	last = NULL;
	while (*param_1)
	{
		if (*param_1 == param_2)
			last = param_1;
		param_1++;
	}
	if (*param_1 == param_2)
		return (param_1);
	return (last);
}