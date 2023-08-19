#include "main.h"

/**
* get_flags - Extracts active formatting flags from the format string
* @format: The formatted string containing the format specifier
* @i: Pointer to the current position in the format string
* Return: A combination of formatting flags
*/
int get_flags(const char *format, int *i)
{
/*Flags: '-', '+', '0', '#', ' '*/
/*Corresponding values: 1, 2, 4, 8, 16*/
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	/*Loop through the format string to find formatting flags*/
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/*Check each character against the defined flag characters*/
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			/*If a match is found, set the corresponding flag bit*/
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
			}

			/*If the character is not a valid flag character, exit the loop*/
			if (FLAGS_CH[j] == 0)
			break;
	}

	/*Update the pointer to the current position in the format string*/
	*i = curr_i - 1;

	/*Return the combined formatting flags*/
	return (flags);
}
