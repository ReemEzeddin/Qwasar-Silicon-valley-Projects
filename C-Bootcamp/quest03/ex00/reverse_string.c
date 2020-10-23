/*
**
** QWASAR.IO -- reverse_string
**
** @param {char*} param_1
**
** @return {char*}
**
*/

char* reverse_string(char* param_1)
{
int		count;
	int		i;
	char	c;

	count = 0;
	while (param_1[count] != '\0')
		count++;
	count = count - 1;
	i = 0;
	while (i < ((count + 1) / 2))
	{
		c = param_1[i];
		param_1[i] = param_1[count - i];
		param_1[count - i] = c;
		i++;
	}
	return (param_1);
}