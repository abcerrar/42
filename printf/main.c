#include "ft_printf.h"
#include <limits.h>

int main(int argc, char **argv)
{

	void *ptr;
	if (argc < 2)
		return 0;
	printf("U mas grande: %u\n", UINT_MAX);
	int n1 = printf("1: %x\n", LONG_MIN + 1);
	int n2 = ft_printf("2: %x\n", LONG_MIN + 1);

	printf("n1: %d\nn2: %d\n", n1, n2);

	n1 = ft_printf("%u\n", -1);
	n2 = printf("%u\n", -1);

	printf("n1: %d\nn2: %d\n", n1, n2);
	/*
	if (argc < 3 || ft_strlen(argv[1]) != 1)
	{
		printf("Error\n");
		return (1);
	}
	//tests
	switch(argv[1][0])
	{
		case 'c':
			printf("Expected: %c\n", argv[2][0]);
			ft_printf("Got: %c\n", argv[2][0]);
			break;
		case 's':
			printf("Expected: %s\n", argv[2]);
			ft_printf("Got: %s\n", argv[2]);
			break;
		case 'p':
			printf("Expected: %p\n", (void *)argv[2]);
			ft_printf("Got: %p\n", (void *)argv[2]);
			break;
		case 'd':
			printf("Expected: %d\n", ft_atoi(argv[2]));
			ft_printf("Got: %d\n", ft_atoi(argv[2]));
			break;
		case 'i':
			printf("Expected: %d\n", ft_atoi(argv[2]));
			ft_printf("Got: %d\n", ft_atoi(argv[2]));
			break;
		case 'u':
			printf("Expected: %u\n", (unsigned int)ft_atoi(argv[2]));
			ft_printf("Got: %u\n", (unsigned int)ft_atoi(argv[2]));
			break;
		case 'x':
			printf("Expected: %x\n", ft_atoi(argv[2]));
			ft_printf("Got: %x\n", ft_atoi(argv[2]));
			break;
	}
	*/

	return (0);
}
