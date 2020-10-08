/*
**
** QWASAR.IO -- is_anagram
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {int}
**
*/
int my_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		count(char *str, char c)
{
	int		i;
    int     count;


	i = 0;
    count = 0;
    if (!str)
        return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int is_anagram(char* param_1, char* param_2)
{
    int     i;
    int     k;
    char    c;

    if (!param_1 && !param_2)
        return(1);
    if (my_strlen(param_1) != my_strlen(param_2))
        return (0);
    i = 0;
    k = 0;
    c = '.';
    while (param_1[i] != '\0')  
    {
        c = param_1[i];
        if (count(param_2 , c) == count(param_1 , c))
        {
            i++;
            continue;
        }
        return (0);
    }
    return (1);
}