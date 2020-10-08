/*
**
** QWASAR.IO -- my_iterative_pow
**
** @param {int} param_1
** @param {int} param_2
**
** @return {int}
**
*/

int my_iterative_pow(int param_1, int param_2)
{
    	int result;

	result = 1;
	if (param_2 < 0)
		return (0);
	while (param_2--)
		result *= param_1;
	return (result);
}