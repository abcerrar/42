#include "ft_printf.h"

int main(int argc, char **argv)
{
	char c;
	void *ptr;
	int num = 0x1A;

	c = 'a';
	ft_printf("Print char: %c\n", c);
	ft_printf("Print sring: %s\n", "hola");
	ft_printf("Print number: %d\n", num);
	ft_printf("Print unsigned: %u\n", num);
	printf("Print unsigned original: %u\n", num);
	ft_printf("Print %%: %%\n");
	ft_printf("Print hex mayus: %X\n", num);
	ft_printf("Print hex minus: %x\n", num);
	printf("Print Hex original: %x\n", num);
	ft_printf("Print ptr: %p\n", ptr);
	printf("Pr or ptr: %p\n", ptr);

	//tests
	ft_printf("Tests\n");

	printf("%%d: %d\n", num);
	printf("%%i: %i\n", num);
	printf("%%u: %u\n", num);
	printf("%%p: %p\n", ptr);
	printf("%%x: %x\n", num);
	printf("%%X: %X\n", num);
	return (0);
}
