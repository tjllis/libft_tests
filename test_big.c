#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>

int	main()
{
	// ft_printf("Testing ft_printf...\n");
	// int y = ft_printf("Hello, char:4 %c\n", 'a');
	// int k = ft_printf("Hello, string: %s\n", "this is a string");
	// int j = ft_printf("Hello, int: %i\n", 3);
	// int a = ft_printf("Hello, decimal. Even more chars: %d\n", -28357);
	// int i = ft_printf("Hello, u_int: %u\n", 4294967295);
	// int *p;
	// int *p2 = &y;
	// int *p3 = (void *)0;
	// int hex = 157587967;
	// //printf("%u\n", 4294967296); // prints 0 instead of the whole string
	// printf("\nChar, num of chars: (expected 15) %d\n", y);
	// printf("String, num of chars: (expected 32) %d\n", k);
	// printf("Int, num of chars: (expected 14) %d\n", j);
	// printf("Decimal, num of chars: (expected 23) %d\n", a);
	// printf("Unsigned int, num of chars: (expected 25) %d\n", i);

	// ft_printf("\nPointers Custom function:\n");
	// ft_printf("Hello, ptr: %p\n", p);
	// ft_printf("Hello, ptr: %p\n", &y);
	// ft_printf("Hello, ptr: %p\n", p2);
	// ft_printf("Hello, ptr: %p\n", &p2);
	// ft_printf("Hello, ptr: %p\n", p3);
	// ft_printf("\nPointers Original function:\n");
	// printf("%p\n", p);
	// printf("%p\n", &y);
	// printf("%p\n", p2);
	// printf("%p\n", &p2);
	// printf("%p\n", p3);
	// ft_printf("\nHex Custom function:\n");
	// ft_printf("Hello, hex: %x\n", hex);
	// ft_printf("Hello, HEX: %X\n", hex);
	// ft_printf("\nHex Original function:\n");
	// printf("Hello, hex: %x\n", hex);
	// printf("Hello, HEX: %X\n", hex);
	
	// ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	// ft_printf(" NULL %s NULL ", NULL);
	// ft_printf("\nEdge cases Original function:\n");
	// int y = printf("If a string == NULL: %s\n", NULL);
	// printf("%d\n", y);
	// printf("An unknown significator (z): %z\n");
	// printf("3 percent signs: %%%\n");
	// ft_printf("\nEdge cases Custom function:\n");
	// ft_printf("If a string == NULL: %s\n", NULL);
	// ft_printf("An unknown significator (z): %z\n");
	// ft_printf("3 percent signs: %%%\n");
	// printf("3 percent signs: %%%\n");

	// ft_printf("\nCUSTOM TEST:\n");
	// printf("\nExpected: %d\n %y", INT_MIN, "HAHA");
	// ft_printf("\nResult: %d\n %y", INT_MIN,"HAHA");

	int g = ft_printf("123 s %d %i %u %u %s %s %s %p %p %p %x %x %X %X & %c %c %c %% %% \n%%\0 asfwsofjgsoihg;w", -1002, 123, 123, -6, NULL, "", "asf", NULL, (size_t)-1, "a", 123, 3333333333333, 2222221, -1000, 0, -200, '\n');
	int b = printf("123 s %d %i %u %u %s %s %s %p %p %p %x %x %X %X & %c %c %c %% %% \n%%\0 asfwsofjgsoihg;w", -1002, 123, 123, -6, NULL, "", "asf", NULL, (size_t)-1, "a", 123, 3333333333333, 2222221, -1000, 0, -200, '\n');
	printf("%d == %d\n", g, b);
	printf("%r");
	//printf("%d\n", n);
	
}
