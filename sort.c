#include <stdio.h>
#define MAX_SIZE 100

int main()
{
    int array[MAX_SIZE];
    int size;
    int i, j, temp;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            // swap
            if(array[i] > array[j])
            {
		temp     = array[i];
		// array[i] = array[j];
                array[j] = array[i];
                array[j] = temp;

            }
        }
    }

    // Print the sorted array
    printf("\nElements of the sorted array: ");
    for(i=0; i<size; i++)
    {
        printf("%d\t", array[i]);
    }

    return 0;
}
