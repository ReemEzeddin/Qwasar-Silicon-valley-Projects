/*
**
** QWASAR.IO -- my_atoi
**
** @param {char*} param_1
**
** @return {int}
**
*/

int my_atoi(char* param_1)
{
    int		i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!param_1[i])
		return (0);
	while (param_1[i] == '\t' || param_1[i] == '\v' || param_1[i] == '\n' || \
		param_1[i] == '\r' || param_1[i] == '\f' || param_1[i] == ' ')
		i += 1;
	if (param_1[i] == '-' || param_1[i] == '+')
		if (param_1[i++] == '-')
			sign = -1;
	while (param_1[i] >= '0' && param_1[i] <= '9')
		nbr = (nbr * 10) + (param_1[i++] - '0');
	return (nbr * sign);
}