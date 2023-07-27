#include "main.h"

/******** TOOL TO PRINT UNSIGNED NUMBERS **********/
/**
 * print_unsigned - Prints an unsigned number
 * @types: a list of arg type A
 * @buffer: print buffer
 * @flags: available and active flags
 * @width: size of output 
 * @precision: specifier handler for precision 
 * @size: specifier handler for size
 * Return: amount of printed characters
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

/** TOOL FOR PRINTING UNSIGNED NUMBERS IN OCTAL **/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: a list of arg type A
 * @buffer: print buffer
 * @flags: available and active flags
 * @width: size of output 
 * @precision: specifier handler for precision 
 * @size: specifier handler for size
 * Return: amount of printed characters
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

/** TOOL FOR PRINTING UNSIGNED NUMBERS IN HEXADECIMAL **/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: a list of arg type A
 * @buffer: print buffer
 * @flags: available and active flags
 * @width: size of output 
 * @precision: specifier handler for precision 
 * @size: specifier handler for size
 * Return: amount of printed characters
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** TOOL FOR PRINTING UNSIGNED NUMBER IN UPPER HEXADECIMAL **/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: a list of arg type A
 * @buffer: print buffer
 * @flags: available and active flags
 * @width: size of output 
 * @precision: specifier handler for precision 
 * @size: specifier handler for size
 * Return: amount of printed characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/****** TOOL FOR PRINTING HEXADECIMALS IN LOWER OR UPPER ******/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: a list if arg type A
 * @map_to: mapping lists
 * @buffer: buffer print array
 * @flags: available and flags
 * @flag_ch: available and active flags
 * @width: output size
 * @precision: specifier handler for precisions
 * @size: specifier handler for sizes
 * Return: Amount of characters printed
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
