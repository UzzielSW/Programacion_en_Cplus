#include <stdio.h>

int main()
{
	int array[6] = {0, 1, 2, 3, 4, 5};
	int i, *pi;

	// #1
	for (i = 0; i < 6; i++)
		printf("%3d", array[i]);
	putchar('\n');

	// #2
	for (pi = &array[0]; pi < &array[6]; pi++)
		printf("%3d", *pi);
	putchar('\n');

	// #3
	for (pi = array, i = 0; i < 6; i++)
		printf("%3d", pi[i]);
	putchar('\n');

	// #4
	for (pi = array, i = 0; pi + i < array + 6; pi++, i++)
		printf("%3d", *(pi + i));
	putchar('\n');

	// #5
	for (pi = array + 5, i = 0; pi >= array; pi--)
		printf("%3d", *pi);
	putchar('\n');

	// #6
	for (pi = array + 5; pi >= array; pi--)
		printf("%3d", array[pi - array]);
	putchar('\n');

	return 0;
}
