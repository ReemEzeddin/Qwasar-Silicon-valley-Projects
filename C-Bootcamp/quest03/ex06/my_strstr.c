/*
**
** QWASAR.IO -- my_strstr
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {char*}
**
*/

char* my_strstr(char* param_1, char* param_2)
{
    int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (param_2[len] != '\0')
		len++;
	if (len == 0)
		return (param_1);
	while (param_1[i])
	{
		while (param_2[pos] == param_1[i + pos])
		{
			if (pos == len - 1)
				return (param_1 + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}