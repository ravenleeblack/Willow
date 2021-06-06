#include "type.h"
#include "lex.h"
#include "parse.h"
#include <stdio.h>

int open_file()
{
	errno_t error;

	error = fopen_s(&file, "willow.txt", "r");

	return 0;
}

int close_file()
{
	errno_t error;

	if (file)
	{
		error = fclose(file);
	}
	return 0;
}

int main()
{
	open_file();

	parse();
	
	close_file();

	return 0;
}



