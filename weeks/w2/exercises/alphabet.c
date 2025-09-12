#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
	// get word to check
	if (argc != 2)
	{
		printf("error regarding number of arguments");
		return 1;
	}
	string text = argv[1];
	if (i = 0; i < strlen(text); i++)
	{
		if (!isalpha(text[1]))
		{
			printf("make sure there are only letters");
			return 2;
		}
	}
	// iterate through each element
	for (int i = 1; i < strlen(text); i++)
	{
		// check if alphabetical
		if (text[i] < text[i - 1])
		{
			printf("No\n");
			return 0;
		}
	}
		
	// print yes if alphabetical
	printf("Yes");
}
