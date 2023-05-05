#include "main.h"
#include <stdio.h>
/**
 * print_binary - converts unsigned into to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{

	unsigned long int n_copy = n, mask = 1;
	int len = 0;

	while (n_copy > 0)
	{
		len++;
		n_copy >>= 1;
	}
	len -= 1;

	if (len > 0) /* create mask based in length  num */
		mask = mask << len;

	while (mask > 0) /* march each rightmost bit to see if 1 or 0 */
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;
	}
}
