/*
**
** QWASAR.IO -- my_print_reverse_alphabet
**
**
** @return {void}
**
*/
#include <unistd.h>
void my_putchar(char c) {
  write(1, &c, 1);
}
void my_print_reverse_alphabet()
{
    char    c;

    c = 'z';
    while (c >= 'a')
    {
        my_putchar(c);
        c--;
    }
    write(1, "\n", 1);

}