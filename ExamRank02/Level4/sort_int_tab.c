/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void	sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/
///////////////////////////////////////////////////////////
/*
// Sort the numbers in an integer array in ascending order

Example:
Input: 5, 3, 8, 4, 2
Output: Sorted array: 2 3 4 5 8

Input: 10, -2, 33, 5, 1, 0
Output: Sorted array: -2 0 1 5 10 33

Input: 100, 50, 25, 75, 0, -50
Output: Sorted array: -50 0 25 50 75 100
*/
//////////////////////////////////////////////////////////

void	sort_int_tab(int *tab, unsigned int size)
{
	int temp;
	int i = 0;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
        else    
            i++;
	}
}

// Main program
#include <stdio.h>
int main()
{
    int array[] = {5, 3, 8, 1, 2, 7, 4, 6};
    unsigned int size = sizeof(array) / sizeof(array[0]);
    unsigned int i = 0;

    printf("Array before sorting:\n");
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    sort_int_tab(array, size);

    i = 0;

    printf("Array after sorting:\n");
    
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    return 0;
}