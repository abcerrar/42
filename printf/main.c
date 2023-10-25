//#include "libftprintf.a"
//#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"




int main()
{
	char c;
	
	c = 'a';
	ft_printf("Print char: %c\n", c);
	ft_printf("Print sring: %s\n", "hola");
	ft_printf("Print number: %d\n", 7894);
	ft_printf("Print unsigned: %u\n", -42);
	ft_printf("Print %%: %%\n");
	ft_printf("Print hex mayus: %X\n", 424);
	ft_printf("Print hex minus: %x\n", 424);
	printf("%x\n", 424);
	

	//tests
	int num = -2;
	void *ptr;
	ft_printf("Tests\n");

	printf("%%d: %d\n", num);
	printf("%%i: %i\n", num);
	printf("%%u: %u\n", num);
	printf("%%p: %p\n", ptr);
	printf("%%x: %x\n", num);
	printf("%%X: %X\n", num);
	return (0);
}
