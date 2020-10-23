/*
**
** QWASAR.IO -- my_strdup
**
** @param {char*} param_1
**
** @return {char*}
**
*/
#include <stdlib.h>

char* my_strdup(char* param_1)
{
    char	*new;
	int		i;

	i = 0;
	while (param_1[i])
		i++;
	new = malloc((sizeof(char) * i) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (param_1[i])
	{
		new[i] = param_1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}