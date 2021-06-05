#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size);
void print_addr(void *addr);
void print_hex(void *addr, unsigned int size, unsigned int count);
void print_str(void *addr, unsigned int size, unsigned int count);

void *ft_print_memory(void *addr, unsigned int size)
{
	unsigned int index;

	index = 0;
	while (*(char *)(addr + index) != '\0' && index < size)
	{
		print_addr(addr + index);
		print_hex(addr + index, size, index);
		print_str(addr + index, size, index);
		write(1, "\n", 1);
		index += 16;
	}
	return (addr);
}

void print_addr(void *addr)
{
	char arr[16];
	char *hex;
	long long ad;
	int index;

	hex = "0123456789abcdef";
	ad = (long long)addr;
	index = 15;
	while (index >= 0)
	{
		arr[index] = hex[ad % 16];
		ad /= 16;
		index--;
	}
	index = 0;
	while (index < 16)
	{
		write(1, &arr[index], 1);
		index++;
	}
	write(1, ": ", 2);
}

void print_hex(void *addr, unsigned int size, unsigned int count)
{
	char *hex;
	unsigned int index;
	unsigned char a;

	hex = "0123456789abcdef";
	index = 0;
	a = *(unsigned char *)(addr + index);
	while (index < 16 && count + index < size)
	{
		write(1, &hex[a / 16], 1);
		write(1, &hex[a % 16], 1);
		if (index % 2)
			write(1, " ", 1);
		index++;
		a = *(char *)(addr + index);
	}
	while (index < 16)
	{
		write(1, "  ", 2);
		if (index % 2)
			write(1, " ", 1);
		index++;
	}
}

void print_str(void *addr, unsigned int size, unsigned int count)
{
	unsigned int index;
	char ch;

	index = 0;
	ch = *(char *)(addr + index);
	while (index < 16 && index + count < size)
	{
		if (ch >= 32 && ch <= 126)
			write(1, &ch, 1);
		else
			write(1, ".", 1);
		index++;
		ch = *(char *)(addr + index);
	}
}
