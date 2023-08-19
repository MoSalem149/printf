#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
* print_unsigned - Prints an unsigned number.
* @types: List of arguments containing the unsigned number.
* @buffer: Buffer array to handle printing.
* @flags: Flag configuration.
* @width: Width of the field.
* @precision: Precision specification.
* @size: Size specifier.
* This fun prints an unsi number based on the provided args.
* Return: The number of characters printed.
*/
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation.
 * @types: List of arguments containing the unsigned number.
 * @buffer: Buffer array to handle printing.
 * @flags: Flag configuration.
 * @width: Width of the field.
 * @precision: Precision specification.
 * @size: Size specifier.
 * This fun prints an unsi number in octal notation based on the provided args.
 * Return: The number of characters printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation.
 * @types: List of arguments containing the unsigned number.
 * @buffer: Buffer array to handle printing.
 * @flags: Flag configuration.
 * @width: Width of the field.
 * @precision: Precision specification.
 * @size: Size specifier.
 * This fun prints an unsi number in hexa notation based on the provided args.
 * Return: The number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation.
 * @types: List of arguments containing the unsigned number.
 * @buffer: Buffer array to handle printing.
 * @flags: Flag configuration.
 * @width: Width of the field.
 * @precision: Precision specification.
 * @size: Size specifier.
 * The fun print an unsi num in upper hexa notation based on the provided args.
 * Return: The number of characters printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexa number in lower or upper case.
 * @types: List of arguments containing the unsigned number.
 * @map_to: Array of values to map the number to (lower or upper case).
 * @buffer: Buffer array to handle printing.
 * @flags: Flag configuration.
 * @flag_ch: Flag to determine lower or upper case.
 * @width: Width of the field.
 * @precision: Precision specification.
 * @size: Size specifier.
 * This fun prints an unsi number in hexa notation (lower or upper case)
 * based on the provided arguments and mapping.
 * Return: The number of characters printed.
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
