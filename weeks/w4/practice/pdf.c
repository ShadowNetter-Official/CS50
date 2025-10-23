#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./self <file.pdf>\n");
		return 1;
	}
	FILE* file = fopen(argv[1], "rb");
	if (file == NULL)
	{
		printf("error reading: %s\n", argv[1]);
		return 1;
	}
	BYTE buffer[4];
	BYTE pdf_siganture[4] = {0x25, 0x50, 0x44, 0x46};
	fread(buffer, sizeof(BYTE), 4, file);
	for (int i = 0; i < 4; i++)
	{
		if (buffer[i] != pdf_siganture[i])
		{
			printf("not a pdf\n");
			return 0;
		}
	}
	printf("is a pdf\n");
	fclose(file);
	return 0;
}
