#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	test_isalpha()
{
    printf("Testing isalpha...\n");
	int test_cases[] = {
        'a', 'z', 'A', 'Z',    // Alphabetic
        'b', 'Y',              // Random alphabetic
        '0', '9', '@', '[',    // Non-alphabetic symbols
        ' ', '\n', '\t',       // Whitespace
        -1, 128,               // Out-of-range values
        0                      // Null character
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_cases; i++)
    {
        int c = test_cases[i];
        int ft_result = ft_isalpha(c);
        int std_result = isalpha(c);

        if (ft_result == std_result)
            printf("PASS: ft_isalpha(%d) = %d\n", c, ft_result);
        else
            printf("FAIL: ft_isalpha(%d): expected %d, got %d\n", c, std_result, ft_result);
    }
}

void	test_isdigit()
{
    printf("\nTesting isdigit...\n");
	 int test_cases[] = {
        '0', '1', '5', '9',    // Digits
        'a', 'z', 'A', 'Z',    // Alphabetic
        '@', '!', '-', '=',    // Symbols
        ' ', '\n', '\t',       // Whitespace
        -1, 128,               // Out-of-range values
        0                      // Null character
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_cases; i++)
    {
        int c = test_cases[i];
        int ft_result = ft_isdigit(c);
        int std_result = isdigit(c);

        if (ft_result == std_result)
            printf("PASS: ft_isdigit(%d) = %d\n", c, ft_result);
        else
            printf("FAIL: ft_isdigit(%d): expected %d, got %d\n", c, std_result, ft_result);
    }
}

void	test_isalnum()
{
    printf("\nTesting isalnum...\n");
	int test_cases[] = {
        'a', 'z', 'A', 'Z',    // Alphabetic
        '0', '9', '5',         // Digits
        '@', '!', '-', '=',    // Symbols
        ' ', '\n', '\t',       // Whitespace
        -1, 128,               // Out-of-range values
        0                      // Null character
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_cases; i++)
    {
        int c = test_cases[i];
        int ft_result = ft_isalnum(c);
        int std_result = isalnum(c);

        // Adjust expected result for custom return value (8 for true, 0 for false)
        int expected_result = std_result ? 8 : 0;

        if (ft_result == expected_result)
            printf("PASS: ft_isalnum(%d) = %d\n", c, ft_result);
        else
            printf("FAIL: ft_isalnum(%d): expected %d, got %d\n", c, expected_result, ft_result);
    }
}

void	test_isascii()
{
    printf("\nTesting isascii...\n");
	 int test_cases[] = {
        0, 127,         // Boundary values
        65, 90,         // ASCII uppercase letters
        97, 122,        // ASCII lowercase letters
        32, 126,        // Printable ASCII characters
        -1, -128,       // Negative non-ASCII
        128, 255, 1000  // Out-of-range positive
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_cases; i++)
    {
        int c = test_cases[i];
        int ft_result = ft_isascii(c);
        int std_result = isascii(c);

        if (ft_result == std_result)
            printf("PASS: ft_isascii(%d) = %d\n", c, ft_result);
        else
            printf("FAIL: ft_isascii(%d): expected %d, got %d\n", c, std_result, ft_result);
    }
}

void	test_isprint()
{
    printf("\nTesting isprint...\n");
	int test_cases[] = {
        32, 126,        // Boundary printable values
        48, 57,         // Digits
        65, 90,         // Uppercase letters
        97, 122,        // Lowercase letters
        33, 64,         // Printable symbols
        0, 31,          // Non-printable control characters
        127, 128, 255   // Out-of-range values
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_cases; i++)
    {
        int c = test_cases[i];
        int ft_result = ft_isprint(c);
        int std_result = isprint(c);

        if (ft_result == std_result)
            printf("PASS: ft_isprint(%d) = %d\n", c, ft_result);
        else
            printf("FAIL: ft_isprint(%d): expected %d, got %d\n", c, std_result, ft_result);
    }
}

void	test_tolower()
{
    printf("\nTesting tolower...\n");
    printf("Test 1: %c -> %c\n", 'A', ft_tolower('A'));  // Expected: 'A' -> 'a'
    printf("Test 2: %c -> %c\n", 'Z', ft_tolower('Z'));  // Expected: 'Z' -> 'z'
    printf("Test 3: %c -> %c\n", 'a', ft_tolower('a'));  // Expected: 'a' -> 'a'
    printf("Test 4: %c -> %c\n", 'z', ft_tolower('z'));  // Expected: 'z' -> 'z'
    printf("Test 5: %c -> %c\n", '1', ft_tolower('1'));  // Expected: '1' -> '1'
    printf("Test 6: %c -> %c\n", '@', ft_tolower('@'));  // Expected: '@' -> '@'
}

void	test_toupper()
{
    printf("\nTesting toupper...\n");
	printf("Test 1: %c -> %c\n", 'a', ft_toupper('a'));  // Expected: 'a' -> 'A'
    printf("Test 2: %c -> %c\n", 'z', ft_toupper('z'));  // Expected: 'z' -> 'Z'
    printf("Test 3: %c -> %c\n", 'A', ft_toupper('A'));  // Expected: 'A' -> 'A'
    printf("Test 4: %c -> %c\n", 'Z', ft_toupper('Z'));  // Expected: 'Z' -> 'Z'
    printf("Test 5: %c -> %c\n", '1', ft_toupper('1'));  // Expected: '1' -> '1'
    printf("Test 6: %c -> %c\n", '@', ft_toupper('@'));  // Expected: '@' -> '@'
}

int main(void)
{
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_tolower();
    test_toupper();
    return (0);
}
