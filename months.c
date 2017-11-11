#include <stdio.h>
int main(int argc, char *argv[])

{
 int i;
 char *month[12] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
 };

 for(i = 0; i < 14; i++)
 {
  printf("month[%d] = %s\n", i, month[i]);
 }

 return 0;
}
