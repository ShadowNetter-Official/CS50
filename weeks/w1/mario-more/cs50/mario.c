#include <cs50.h>
#include <stdio.h>

void pyramid(int s);
void get_valid_int(void);

int main(void)
{
	get_int();
}

void get_valid_int(void)
{
	int n;
	do
	{
		n = get_int("Height: ");
	}
	while (n < 1);
	pyramid(n);
}

void pyramid(int s)
{
	for (int i = 1; i <= s; i++)
	{
		for (int j = 0; j < s - i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < i; k++)
		{
			printf("#");
		}
		printf("  ");
		for (int l = 0; l < i; l++)
		{
			printf("#");
		}
		printf("\n");
	}
}
