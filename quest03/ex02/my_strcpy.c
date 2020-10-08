/*
**
** QWASAR.IO -- my_strcpy
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {char*}
**
*/

char* my_strcpy(char* param_1, char* param_2)
{
    unsigned int i;

	i = 0;
	while (param_2[i] != '\0')
	{
		param_1[i] = param_2[i];
		i++;
	}
	param_1[i] = param_2[i];
	return (param_1);
}