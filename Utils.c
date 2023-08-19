#include "main.h"

/**
* is_printable - Check if a character is printable
*
* This function checks if a character is printable.
*
* @c: Character to be evaluated
*
* Return: 1 if 'c' is printable, 0 otherwise.
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
* append_hexa_code - Append ASCII as hexadecimal to buffer
*
* This function appends an ASCII code represented in hexadecimal to a buffer.
*
* @buffer: Char array
* @i: Starting index for appending
* @ascii_code: ASCII code to append
*
* Return: Always 3.
*/

int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}

/**
* is_digit - Check if a character is a digit
*
* This function checks if a character is a digit.
*
* @c: Character to be evaluated
*
* Return: 1 if 'c' is a digit, 0 otherwise.
*/

int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
* convert_size_number - Convert a number to the specified size
*
* This function converts a number to the specified data size.
*
* @num: Number to be converted
* @size: Data size indicator
*
* Return: Converted value of 'num'
*/

long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
* convert_size_unsgnd - Convert a number to the specified size
*
* This function converts a number to the indicated data size.
*
* @num: Number to be converted
* @size: Data size indicator
*
* Return: Converted value of 'num'
*/

long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);

return ((unsigned int)num);
}
