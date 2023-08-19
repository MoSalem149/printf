#include "main.h"

/************************* PRINT CHAR *************************/

/**
  * print_char - Print a single character
  *
  * This function prints a single character to the specified output buffer,
  * taking into account various formatting options and specifications.
  *
  * @types: A list containing the argument
  * @buffer: Buffer array used for handling the print operation
  * @flags: Active flags used in calculation
  * @width: Width specification for formatting
  * @precision: Precision specification for formatting
  * @size: Size specifier for formatting
  *
  * Return: The number of characters printed.
  */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
  * print_string - Print a string
  *
  * This function prints a string to the specified output buffer,
  * considering various formatting options and specifications.
  *
  * @types: A list of arguments
  * @buffer: Buffer array used for handling the print operation
  * @flags: Active flags used in calculation
  * @width: Width obtained
  * @precision: Precision specification for formatting
  * @size: Size specifier for formatting
  *
  * Return: The number of characters printed.
  */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
  * print_percent - Print a percent sign
  *
  * This func prints a percent sign to the specified o buffer,
  * taking into acc vari formatting options and specifications.
  *
  * @types: A list of arguments
  * @buffer: Buffer array used for handling the print operation
  * @flags: Active flags used in calculation
  * @width: Width obtained
  * @precision: Precision specification for formatting
  * @size: Size specifier for formatting
  *
  * Return: The number of characters printed.
  */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
  * print_int - Print an integer
  *
  * This func prints an int to the specified o buffer,
  * considering various formatting options and specifications.
  *
  * @types: A list of arguments
  * @buffer: Buffer array used for handling the print operation
  * @flags: Active flags used in calculation
  * @width: Width obtained
  * @precision: Precision specification for formatting
  * @size: Size specifier for formatting
  *
  * Return: The number of characters printed.
  */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
  * print_binary - Print an unsigned binary number
  *
  * This funct prints an unsigned binary num to the specified o buffer,
  * considering vari formatting options and specifications.
  *
  * @types: List of arguments
  * @buffer: Buffer array used for handling the print operation
  * @flags: Active flags used in calculation
  * @width: Width obtained
  * @precision: Precision specification for formatting
  * @size: Size specifier for formatting
  *
  * Return: The number of characters printed.
   */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

