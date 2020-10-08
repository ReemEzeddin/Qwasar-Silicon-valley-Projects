/*
**
** QWASAR.IO -- my_iterative_factorial
**
** @param {int} param_1
**
** @return {int}
**
*/

int my_iterative_factorial(int param_1)
{
    int		factorial;
	int		i;

	if (param_1 == 0)
		return (1);
	else if (param_1 < 0)
		return (0);
	factorial = 1;
	i = 0;
	while (i++ < param_1)
		factorial *= i;
	return (factorial);
}