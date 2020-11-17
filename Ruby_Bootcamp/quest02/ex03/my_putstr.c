/*
**
** QWASAR.IO -- my_putstr
**
** @param {char*} param_1
**
** @return {void}
**
*/

int my_putchar(char c) {
  return write(1, &c, 1);
}

void my_putstr(char* param_1)
{

	int i;

	i = 0;
	while (param_1[i])
		my_putchar(param_1[i++]);
}