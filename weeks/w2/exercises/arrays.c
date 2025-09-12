#include <stdio.h>

const int size = 5;

int main(void)
{
	int array[size];
	array[0] = 1;
	for (int i = 1; i < size; i++)
	{
		array[i] = array[i - 1] * 2;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%i\n", array[i]);
	}
}
