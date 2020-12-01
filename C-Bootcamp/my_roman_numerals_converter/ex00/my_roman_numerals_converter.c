
#include <string.h>
#include <stdlib.h>

char *my_roman_numerals_converter(int num)
{
    char *roman;

    roman = (char*)malloc(50);
    while(num != 0)
    {

        if (num >= 1000)
        {
           roman = strcat(roman ,"M");
           num -= 1000;
        }

        else if (num >= 900)
        {
           roman = strcat(roman, "CM");
           num -= 900;
        }        

        else if (num >= 500)
        {           
           roman = strcat(roman, "D");
           num -= 500;
        }

        else if (num >= 400)
        {
           roman = strcat(roman, "CD");
           num -= 400;
        }

        else if (num >= 100)
        {
           roman = strcat(roman, "C");
           num -= 100;                       
        }

        else if (num >= 90)
        {
           roman = strcat(roman, "XC");
           num -= 90;                                              
        }

        else if (num >= 50)
        {
           roman = strcat(roman, "L");
           num -= 50;                                                                     
        }

        else if (num >= 40)
        {
           roman = strcat(roman, "XL");           
           num -= 40;
        }

        else if (num >= 10)
        {
           roman = strcat(roman, "X");
           num -= 10;           
        }

        else if (num >= 9)
        {
           roman = strcat(roman, "IX");
           num -= 9;                         
        }

        else if (num >= 5)
        {
           roman = strcat(roman, "V");
           num -= 5;                                     
        }

        else if (num >= 4)
        {
           roman = strcat(roman, "IV");
           num -= 4;                                                            
        }

        else if (num >= 1)
        {
           roman = strcat(roman, "I");
           num -= 1;                                                                                   
        }

    }

    return (roman);
}