/*
**
** QWASAR.IO -- rcapitalize
**
** @param {char*} param_1
**
** @return {char*}
**
*/
#include <unistd.h>

char* rcapitalize(char* param_1)
{
    int	    i;
    char    *result;

	i = 0;
    result = (char *)malloc(200);
	if (!param_1)
        return (param_1);
	while (param_1[i] != '\0')
	{
		if (param_1[i + 1] == ' ' || param_1[i + 1] == '\t' || param_1[i + 1] == '\0')
		{
			if (param_1[i] >= 'a' && param_1[i] <= 'z')
			{
				param_1[i] = param_1[i] - 32;
			}
		}
		else if (param_1[i] >= 'A' && param_1[i] <= 'Z')
			param_1[i] = param_1[i] + 32;
		i++;
	}
	return (param_1);
}