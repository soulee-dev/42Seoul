#include <stdio.h>
#include <unistd.h>

void	receive_bit(int bit)
{
	static int	bit_count;
	static char	c;

	if (bit == 0)
	{
		c |= 0;
		if (bit_count < 7)
			c <<= 1;
	}
	else if (bit == 1)
	{
		c |= 1;
		if (bit_count < 7)
			c <<= 1;
	}
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main()
{
	// a
	receive_bit(0);
	receive_bit(1);
	receive_bit(1);
	receive_bit(0);
	receive_bit(0);
	receive_bit(0);
	receive_bit(0);
	receive_bit(1);

	// b
	receive_bit(0);
	receive_bit(1);
	receive_bit(1);
	receive_bit(0);
	receive_bit(0);
	receive_bit(0);
	receive_bit(1);
	receive_bit(0);
}