#include <stdio.h>
#include <iostream>

int main() 
{
	for(int i = 0; i < 10; i++)
	{
	  int *FirstArray = new int[10];
	  for(int j = 0; j < 10; j++)
	  {
	      FirstArray[j] = j;
	  }
	  int *SecondArray = new int[10];
	  for(int j = 0; j < 10; j++)
	  {
	      SecondArray[j] = FirstArray[j] + rand() % 10 + 1;
	  }
	  for(int j = 0; j < 10; j++)
	  {
	      printf("%d", SecondArray[j]);
	  }
	  delete [] SecondArray;
	}
	return 0;
}
