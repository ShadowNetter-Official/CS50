#include <stdio.h>

bool valid_triangle(float x, float y ,float z);

int main(void)
{
	bool t = valid_triangle(2.0, 2.0, 6.0);
	if (t) 
	{
		printf("the triangle is valid\n");
	} 
	else 
	{
		printf("the triangle is not valid\n");
	}
}

bool valid_triangle(float x, float y, float z)
{
	// check if inputs are above 0
	if (x <= 0 || y <= 0 || z <= 0)
	{
		return false;
	}
	// check if sum of two numbers is greater than 
	// the other number
	if (x + y <= z ||  y + z <= x || z + x <= y)
	{
		return true;
	}
	return false;
	
}
