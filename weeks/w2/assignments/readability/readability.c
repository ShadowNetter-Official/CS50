#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// pseudo code

	// formula
	//
	// (grade level) = 0588 * L - 0.296 * S - 15.8
	//
	// L = letters/words * 100
	// S = sentences/words * 100
	//
	// sentence = startswith(upercase), endswith('.', '?', '!')
	//
	// grade level = whole number
	// if grade level < 1 then output below grade 1
	// else if grade level > 16 then output grade 16+
	// else output grade level
	//
	// 1. get text input
	// 2. check for every sentence
	// 3. check for every word
	// 4. calculate L and S
	// 5. calculate grade level and round to nearest whole number
	// 6. check conditions mentioned above
	// 7. output grade level


int sentences(string text);
int words(string text);
int letters(string text);
void compute_grade(int sentence_count, int word_count, int letter_count);

int main (void)
{
	// get input
	string text = get_string("Text: ");
	// do respective computing
	int sentence_count = sentences(text);
	int word_count = words(text);
	int letter_count = letters(text);
	compute_grade(sentence_count, word_count, letter_count);
}

int sentences(string text)
{
	int sentence_count = 0;
	char end_of_sentence[] = {'?', '.', '!'};

	// for every letter in text
	for (int letter = 0, length = strlen(text); letter < length; letter++)
	{
		// for every character in end_of_sentence, check if current character is that character
		// if so, add to sentence_count
		for (int character = 0, count = sizeof(end_of_sentence); character < count; character++ )
		{
			if (text[letter] == end_of_sentence[character])
			{
				sentence_count++;
			}
		}
	}
	return sentence_count;
}

int words(string text)
{
	int word_count = 0;

	// for ever letter in text, if char is space and if the next char is not a space, add 1 to word count
	for (int letter = 0, length = strlen(text); letter < length; letter++)
	{
		if (text[letter] == ' ' && text[letter + 1] != ' ')
		{
			word_count++;
		}
	}
	return (word_count + 1);
}

void compute_grade(int sentence_count, int word_count, int letter_count)
{
	float L = (float) letter_count / word_count * 100;
	float S = (float) sentence_count / word_count * 100;
	float grade = 0.0588 * L - 0.296 * S - 15.8;
	if (grade < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (grade > 16)
	{
		printf("Grade 16+\n");
	} 
	else
	{
		int rounded_grade = round(grade);
		printf("Grade %i\n", rounded_grade);
	}
}

int letters(string text)
{
	int letter_count = 0;
	for (int chars = 0, length = strlen(text); chars < length; chars++)
	{
		if (isalpha(text[chars]))
		{
			letter_count++;
		}
	}
	return letter_count;
}
