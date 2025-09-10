#include <cs50.h>
#include <stdio.h>

int calculate(int owed)
{
	int coins;
	int penny = 1;
	int dime = 10;
	int nickle = 5;
	int quarter = 25;
	while (owed > 0)
	{
		while (owed >= quarter)
		{
			owed = owed - quarter;
			coins++;
		}
		while (owed >= dime)
		{
			owed = owed - dime;
			coins++;
		}
		while (owed >= nickle)
		{
			owed = owed - nickle;
			coins++;
		}
		while (owed >= penny)
		{
			owed = owed - penny;
			coins++;
		}
	}
	return coins;
}

int main()
{
	int owed;
	do
	{
		owed = get_int("Amount owed: ");
	}
	while(owed < 0);
	int coins = calculate(owed);
	printf("%i\n", coins);
}
