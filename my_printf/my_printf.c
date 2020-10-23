
//**************************    INCLUDES    **************************

#include <stdarg.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>
#include <stdio.h>

//*************************      TOOLS      **************************

int     my_putchar(char c)
{
  return (write(1, &c, 1));
}

int		my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     my_putstr(char *str)
{
    int i;
    int result;

    result = 0;
    if (str)
        for (i = 0; str[i]; i++)
            result += my_putchar(str[i]);
    else
        my_putstr("(null)");
    return (result);
}

char	*my_strrev(char *str)
{
	int	len;
	int	i;
	char	tmp;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int     int_len(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}

//******************************    HANDLERS    ***************************

int     u_handler(uint32_t nb)
{
    uint32_t d;
    int result;

    result = 0;
    if ((int)nb == -1)
        result += my_putstr("4294967295");
    else
    {
        d = 1;
        while ((d * 10) < nb)
        d *= 10;
        while (d)
            {
                result += my_putchar((char)((int)'0' + (int)(nb / d)));
                nb -= ((nb / d) * d);
                d /= 10;
            }
    }
    return (result);
}

void    p_handler(long nbr, char *base)
{
	long nb;

	if (nbr > 0) {
		nb = nbr;
		nbr /= 16;
		p_handler(nbr, base);
		my_putchar(base[nb % 16]);
	}
}

int     x_handler(unsigned int nb, char *base)
{
    unsigned int    beg;
    unsigned int    end;
    char            *str;
    int             i;

    i = 0;
    str = (char *)malloc(100);
    do
    {
        end = nb % 16;
        beg = (nb - end) / 16;
        nb = beg;
        str[i++] = base[end];
    } while (beg);
    return(my_putstr(my_strrev(str)));
}

int	    o_handler(int nbr)
{
    char	*base;
    int     result;
    int	    div;
    int     ret;

    base = "01234567";
    div = 1;
    ret = 0;
    while ((nbr / div) >= 8)
    div = div * 8;
    while (div > 0)
    {
        result = (nbr / div) % 8;
        ret += my_putchar(base[result]);
        div = div / 8;
    }
    return (ret);
}

int     d_handler(int nb)
{
	int arr[999];
	int i = 0;
	int len = int_len(nb);
    int ret;

    ret = len;
	if (nb < 0) {
		ret += my_putchar('-');
		nb = nb *-1;
	}
	for (i = 0; i < len; i++) {
		arr[i] = nb % 10;
		nb /= 10;
	}
	for (int b = i - 1; b > -1; b--)
		my_putchar(arr[b] + '0');
	return (ret);
}

int     my_printf(char *format, ...)
{
    va_list args;
    int     i;
    int     result;

    va_start(args, format);
    i = 0;
    result = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 's')
                result += my_putstr(va_arg(args, char *));
            else if (format[i + 1] == 'd')
                result += d_handler(va_arg(args, int));
            else if (format[i + 1] == 'c')
                result += my_putchar((char)va_arg(args, int));
            else if (format[i + 1] == 'x' || format[i + 1] == 'X')
            {
                if (format[i + 1] == 'x')
                   result += x_handler(va_arg(args, unsigned int), "0123456789abcdef");
                else
                   result += x_handler(va_arg(args, unsigned int), "0123456789ABCDEF");
            }
            else if (format[i + 1] == 'p')
            {
                result += my_putstr("0x");
                p_handler(va_arg(args, long), "0123456789abcdef");
                result += 12;
            }
            else if (format[i + 1] == 'o')
                result += o_handler(va_arg(args, unsigned int));
            else if (format[i + 1] == 'u')
                result += u_handler(va_arg(args, unsigned int));
            else
                result += my_putchar(format[i + 1]);
            i++;
        }
        else
            result += my_putchar(format[i]);
        i++;
    }
va_end(args);
return (result);
}