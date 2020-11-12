#include <stdio.h>

int main() {
  int   my_age;
  char  my_comma;
  char  *my_name;
  my_age = 34;
  my_name = "Luke";
  my_comma = ',';

  printf("Hello %s%c I'm %d years old.\n", my_name, my_comma, my_age);
  return 0;
}