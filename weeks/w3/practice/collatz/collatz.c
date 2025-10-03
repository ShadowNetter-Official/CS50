// collatz conjecture
// if n is 1, stop
// else
// if n is even, repeat process on n/2 and add 1 to count
// if n is odd, repeat this process on 3n + 1 and add 1 to count
//

#include <stdio.h>

int collatz(int n);

int main(void)
{
	int count = collatz(7);
	printf("%i\n", count);
}

int collatz(int n)
{
	// if n is 1, stop
	if (n == 1)
	{
		return 0;
	}

	// if number is even..., else...
	if (n % 2 == 0)
	{
		return 1 + collatz(n/2);
	}
	else
	{
		return 1 + collatz(3*n+1);
	}
}
