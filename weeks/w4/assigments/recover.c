#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;


bool check_clas(int argc, char* argv[]);
long file_size(char* file_path);
bool check_jpeg(int block_size, byte buffer[block_size]);


int main(int argc, char* argv[])
{
	// check CLAs
	if (!check_clas(argc, argv)) { return 1; }

	// get file size
	long fs = file_size(argv[1]);

	// open file
	FILE* card = fopen(argv[1], "rb");
	if (card == NULL)
	{
		printf("Error reading %s\n", argv[1]);
		return 1;
	}

	// initialize state
	bool writing = false;

	// initialize image count
	int count = 0;

	// initialize buffer
	int block_size = 512;
	byte buffer[block_size];

	// initialize file
	FILE* current_file = NULL;

	// repeat until end of file
	while (fread(buffer, 1, block_size, card) == block_size)
    {
        // Create JPEGs from the data
		char file_name[8];
		sprintf(file_name, "%03i.jpg", count);

		// if file is jpeg
		if (check_jpeg(block_size, buffer))
		{
			// if not first jpeg, close previous file
			if (count > 0)
			{
				writing = false;
				fclose(current_file);
			}
			count++;

			// open new file and write to it
			current_file = fopen(file_name, "wb");
			if (current_file == NULL)
			{
				printf("Error reading %s\n", file_name);
				return 1;
			}
			writing = true;
			fwrite(buffer, block_size, 1, current_file);
		}
		// if file is not jpeg
		else
		{
			// if currently writing to file, continue writing
			if (writing)
			{
				fwrite(buffer, block_size, 1, current_file);
			}
		}

    }
    fclose(current_file);
	fclose(card);

}

bool check_clas(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./recover FILE\n");
		return false;
	}
	return true;
}

long file_size(char* file_path)
{
	FILE* card = fopen(file_path, "rb");
	if (card == NULL)
	{
		printf("Error reading %s\n", file_path);
		return 1;
	}
	fseek(card, 0L, SEEK_END);
	long size = ftell(card);
	fclose(card);
	return size;

}

bool check_jpeg(int block_size, byte buffer[block_size])
{
	byte init_headers[3] = {0xff, 0xd8, 0xff};
	for (int i = 0; i < sizeof(init_headers); i++)
	{
		if (init_headers[i] != buffer[i]) { return false; }
	}
	if ((buffer[3] &  0xf0) != 0xe0) { return false; }

	return true;
}

