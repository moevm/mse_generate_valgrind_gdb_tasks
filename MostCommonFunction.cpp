#include <stdio.h>
#include <iostream>

int First[10];
int Second[10];
int Third[10];
	
int creatingnumber()
{
    int n = rand() % 100 + 1;
    return n;
}

int sumnumbers(int n1)
{
    int n2 = creatingnumber();
    int sum = n1 + n2;
    return sum;
}

void sumarrays()
{
    for (int j = 0; j < 10; j++)
	  {
	      Third[j] = First[j] + Second[j];
	  }
}
int main() 
{
	for (int i = 0; i < 10; i++)
	{
	    First[i] = creatingnumber();
	    Second[i] = creatingnumber();
	}
	for (int i = 0; i < 10; i++)
	{
	  Second[i] = sumnumbers(First[i]);   
	}
	sumarrays();
	for(int i = 0; i < 10; i++)
	  {
	      printf("%d", Third[i]);
	  }
	return 0;
}