#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

void	test_strlen()
{
    printf("\nTesting strlen...\n");
	 const char *test_cases[] = {
        "Hello, World!",      // Regular string
        "",                   // Empty string
        "42",                 // Short string
        "This is a longer string with spaces.", // Long string
        "abc\0def",           // String with embedded null
        NULL                  // Null pointer (special case)
    };

    size_t expected, actual;
    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        const char *test = test_cases[i];

        if (test == NULL)
        {
            printf("Test case %zu: NULL pointer\n", i);
            // Normally undefined behavior for strlen; skip this case for ft_strlen.
            continue;
        }

        actual = ft_strlen(test);
        expected = strlen(test);

        if (actual == expected)
            printf("PASS: ft_strlen(\"%s\") = %zu\n", test, actual);
        else
            printf("FAIL: ft_strlen(\"%s\"): expected %zu, got %zu\n", test, expected, actual);
    }
}

void	test_memset()
{
    printf("\nTesting memset...\n");
	char buffer1[20] = "Hello, World!";
    char buffer2[20] = "Hello, World!";

    // Test case 1: Fill first 5 bytes with '*'
    ft_memset(buffer1, '*', 5);
    memset(buffer2, '*', 5);
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Fill first 5 bytes with '*'.\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);

    // Test case 2: Fill entire buffer with 'A'
    ft_memset(buffer1, 'A', sizeof(buffer1));
    memset(buffer2, 'A', sizeof(buffer2));
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Fill entire buffer with 'A'.\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);

    // Test case 3: Fill 0 bytes (should not modify buffer)
    ft_memset(buffer1, 'B', (0));
    memset(buffer2, 'B', (0));
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Fill 0 bytes (no modification).\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);

    // Test case 4: Fill with a non-ASCII value
    ft_memset(buffer1, 200, 10);
    memset(buffer2, 200, 10);
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Fill with non-ASCII value (200).\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);
}

void	test_bzero()
{
    printf("\nTesting bzero...\n");
    char buffer1[20] = "Hello, World!";
    char buffer2[20] = "Hello, World!";

    // Test case 1: Zero the first 5 bytes
    ft_bzero(buffer1, 5);
    bzero(buffer2, 5);
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Zero the first 5 bytes.\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);

    // Test case 2: Zero the entire buffer
    ft_bzero(buffer1, sizeof(buffer1));
    bzero(buffer2, sizeof(buffer2));
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Zero the entire buffer.\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);

    // Test case 3: Zero 0 bytes (no changes should occur)
    ft_bzero(buffer1, (0));
    bzero(buffer2, (0));
    if (memcmp(buffer1, buffer2, 20) == 0)
        printf("PASS: Zero 0 bytes (no changes).\n");
    else
        printf("FAIL: Expected '%s', got '%s'.\n", buffer2, buffer1);
}

void	test_memcpy()
{
    printf("\nTesting memcpy...\n");
	char src[20] = "Hello, memcpy!";
	char dest[20];
	char std_dest[20];

	// Test case 1: Copy entire string
	ft_memcpy(dest, src, strlen(src) + 1);
	memcpy(std_dest, src, strlen(src) + 1);
	if (strcmp(dest, std_dest) == 0)
		printf("PASS: Copy entire string.\n");
	else
		printf("FAIL: Expected '%s', got '%s'.\n", std_dest, dest);

	// Test case 2: Copy 0 bytes (dest remains unchanged)
	char unchanged_dest[20] = "Unchanged";
	memcpy(dest, unchanged_dest, strlen(unchanged_dest) + 1); // Reset dest
	ft_memcpy(dest, src, 0);
	memcpy(std_dest, src, 0);
	if (strcmp(dest, unchanged_dest) == 0)
		printf("PASS: Copy 0 bytes.\n");
	else
		printf("FAIL: Expected '%s', got '%s'.\n", unchanged_dest, dest);

	// Test case 3: NULL src or dest
	// if (ft_memcpy(NULL, src, 5) == NULL)
	// 	printf("PASS: Handle NULL pointers.\n");
	// else
	// 	printf("FAIL: NULL pointer test.\n");
    // if (ft_memcpy(dest, NULL, 5) == NULL)
    //     printf("PASS: Handle NULL pointers.\n");
}

void	test_memmove()
{
    printf("\nTesting memmove...\n");
	char src1[] = "Hello, World!";
	char dest1[20];

	char src2[] = "OverlapExample";
	char dest2[20];

	// Test case 1: Non-overlapping memory
	ft_memmove(dest1, src1, strlen(src1) + 1);
	if (strcmp(dest1, src1) == 0)
		printf("PASS: Non-overlapping copy.\n");
	else
		printf("FAIL: Expected '%s', got '%s'.\n", src1, dest1);

	// Test case 2: Overlapping memory (dest < src)
	char overlap1[] = "0123456789";
	ft_memmove(overlap1 + 2, overlap1, 5); // Copy "01234" to "23456"
	if (strcmp(overlap1, "01201234") == 0)
		printf("PASS: Overlapping (forward copy).\n");
	else
		printf("FAIL: Overlapping (forward copy), got '%s'.\n", overlap1);

/*	// Test case 3: Overlapping memory (dest > src)
	char overlap2[] = "0123456789";
	ft_memmove(overlap2, overlap2 + 2, 5); // Copy "23456" to "23456"
	if (strncmp(overlap2, "23456", 5) == 0)
		printf("PASS: Overlapping (backward copy).\n");
	else
		printf("FAIL: Overlapping (backward copy), got '%s'.\n", overlap2);
*/
/*	// Test case 4: Null pointers
	if (ft_memmove(NULL, src2, 5) == NULL && ft_memmove(dest2, NULL, 5) == NULL)
		printf("PASS: Handle NULL pointers.\n");
	else
		printf("FAIL: NULL pointer test.\n");
*/
	// Test case 5: Copy 0 bytes
	char no_copy[] = "Unchanged";
	ft_memmove(no_copy + 2, no_copy, 0); // No change expected
	if (strcmp(no_copy, "Unchanged") == 0)
		printf("PASS: Copy 0 bytes.\n");
	else
		printf("FAIL: Copy 0 bytes, got '%s'.\n", no_copy);
}

void	test_strlcpy()
{
    printf("\nTesting strlcpy...\n");
	char dst[20];
	const char *src = "Hello, World!";
	
	// Test case 1: Normal case (destination is large enough)
	size_t len = ft_strlcpy(dst, src, sizeof(dst));
	printf("Test 1: %s (len: %zu)\n", dst, len); // Expected: "Hello, World!" (len: 13)

	// Test case 2: Buffer too small (size smaller than src)
	len = ft_strlcpy(dst, src, 6);
	printf("Test 2: %s (len: %zu)\n", dst, len); // Expected: "Hello" (len: 13)

	// Test case 3: Empty source string
	len = ft_strlcpy(dst, "", sizeof(dst));
	printf("Test 3: %s (len: %zu)\n", dst, len); // Expected: "" (len: 0)

	// Test case 4: Size zero (no copying should happen)
	len = ft_strlcpy(dst, src, 0);
	printf("Test 4: %s (len: %zu)\n", dst, len); // Expected: "" (len: 13)

	// Test case 5: Large source string
	const char *long_src = "A very long string that exceeds buffer size";
	len = ft_strlcpy(dst, long_src, sizeof(dst));
	printf("Test 5: %s (len: %zu)\n", dst, len); // Expected: "A very long" (len: 39)
}

void	test_strlcat()
{
    printf("\nTesting strlcat...\n");
	char dst[20];
    const char *src = "World!";
    
    // Test case 1: Destination buffer large enough
    strcpy(dst, "Hello ");
    size_t len = ft_strlcat(dst, src, sizeof(dst));
    printf("Test 1: %s (len: %zu)\n", dst, len); // Expected: "Hello World!" (len: 13)

    // Test case 2: Destination buffer too small
    strcpy(dst, "Hello ");
    len = ft_strlcat(dst, src, 10);
    printf("Test 2: %s (len: %zu)\n", dst, len); // Expected: "Hello Worl" (len: 13)

    // Test case 3: Source string empty
    strcpy(dst, "Hello ");
    len = ft_strlcat(dst, "", sizeof(dst));
    printf("Test 3: %s (len: %zu)\n", dst, len); // Expected: "Hello " (len: 6)

    // Test case 4: Size zero (no space to concatenate)
    strcpy(dst, "Hello ");
    len = ft_strlcat(dst, src, 0);
    printf("Test 4: %s (len: %zu)\n", dst, len); // Expected: "Hello " (len: 6)

    // Test case 5: Large destination buffer
    strcpy(dst, "Hello ");
    len = ft_strlcat(dst, "Beautiful World!", sizeof(dst));
    printf("Test 5: %s (len: %zu)\n", dst, len); // Expected: "Hello Beautiful" (len: 18)
}

void	test_strchr()
{
    printf("\nTesting strchr...\n");
	const char *str = "Hello, World!";
    
    // Test 1: Find the first occurrence of 'o'
    char *result1 = ft_strchr(str, 'o');
    if (result1)
        printf("Found: %s\n", result1);  // Expected: "o, World!"
    else
        printf("Not found\n");

    // Test 2: Find the first occurrence of 'l'
    char *result2 = ft_strchr(str, 'l');
    if (result2)
        printf("Found: %s\n", result2);  // Expected: "llo, World!"
    else
        printf("Not found\n");

    // Test 3: Find the first occurrence of 'z' (not present)
    char *result3 = ft_strchr(str, 'z');
    if (result3)
        printf("Found: %s\n", result3);
    else
        printf("Not found\n");

    // Test 4: Find the first occurrence of the null terminator
    char *result4 = ft_strchr(str, '\0');
    if (result4)
        printf("Found: (null terminator)\n");  // Expected: "(null terminator)"
    else
        printf("Not found\n");

}

void	test_strrchr()
{
    printf("\nTesting strrchr...\n");
	const char *str = "Hello, World!";

    // Test: Find last occurrence of 'o'
    printf("Test 1: %s\n", ft_strrchr(str, 'o'));  // Expected: "o, World!"

    // Test: Find last occurrence of 'l'
    printf("Test 2: %s\n", ft_strrchr(str, 'l'));  // Expected: "l, World!"

    // Test: Find last occurrence of 'z' (not present)
    printf("Test 3: %s\n", ft_strrchr(str, 'z'));  // Expected: NULL

    // Test: Find null terminator
    printf("Test 4: %s\n", ft_strrchr(str, '\0'));  // Expected: the string itself
}

void	test_strncmp()
{
    printf("\nTesting strncmp...\n");
	char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    char str3[] = "Hello, there!";
    char str4[] = "Hello";

    // Comparing two identical strings
    printf("Result: %d\n", ft_strncmp(str1, str2, 5));  // Expected: 0 (equal up to 5 characters)

    // Comparing two different strings
    printf("Result: %d\n", ft_strncmp(str1, str3, 5));  // Expected: 0 (equal up to 5 characters)
    printf("Result: %d\n", ft_strncmp(str1, str3, 7));  // Expected: positive value (after 'World')

    // Comparing a shorter string
    printf("Result: %d\n", ft_strncmp(str1, str4, 10)); // Expected: positive value ('W' > '\0')

    // Comparing with zero length
    printf("Result: %d\n", ft_strncmp(str1, str2, 0));  // Expected: 0 (no comparison, equal by definition)
}

void	test_memchr()
{
    printf("\nTesting memchr...\n");
	char str[] = "Hello, World!";
    char *result;

    // Search for the character 'o' in the first 10 bytes of str
    result = ft_memchr(str, 'o', 10);
    if (result)
        printf("Found 'o' at position: %ld\n", result - str);  // Output the position of 'o'
    else
        printf("'o' not found\n");

    // Search for a character that is not present
    result = ft_memchr(str, 'z', 10);
    if (result)
        printf("Found 'z' at position: %ld\n", result - str);
    else
        printf("'z' not found\n");
}

void	test_memcmp()
{
    printf("\nTesting memcmp...\n");
	const char *str1 = "Hello";
    const char *str2 = "Hello";
    const char *str3 = "HellX";
    
    // Compare the first 5 bytes (comparing "Hello" with "Hello")
    int result = ft_memcmp(str1, str2, 5);
    if (result == 0)
        printf("str1 and str2 are equal\n");
    else
        printf("str1 and str2 are different\n");

    // Compare the first 5 bytes (comparing "Hello" with "HellX")
    result = ft_memcmp(str1, str3, 5);
    if (result == 0)
        printf("str1 and str3 are equal\n");
    else
        printf("str1 and str3 are different\n");
}

void	test_strnstr()
{
    printf("\nTesting strnstr...\n");
	const char *big = "Hello, world!";
    const char *little = "world";
    const char *result;

    result = ft_strnstr(big, little, 12);  // Search for "world" in the first 12 characters of "big"
    if (result)
        printf("Found: %s\n", result);  // Expected: "world!"
    else
        printf("Not found\n");

    result = ft_strnstr(big, little, 5);  // Search for "world" in the first 5 characters of "big"
    if (result)
        printf("Found: %s\n", result);  // Expected: "Not found"
    else
    
	    printf("Not found\n");
}

void	test_calloc()
{
    printf("\nTesting calloc...\n");
	size_t nmemb = 5;
    size_t size = sizeof(int);
    int *arr = ft_calloc(nmemb, size);  // Allocate memory for an array of 5 integers

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return ;
    }

    // Print the array values (all should be initialized to 0)
    for (size_t i = 0; i < nmemb; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    free(arr);
    void *i = ft_calloc(SIZE_MAX, SIZE_MAX);
	void *i1 = ft_calloc(-5, -5);
	void *i2 = ft_calloc(5, 0);
	printf("result of ft_calloc(SIZE_MAX, SIZE_MAX): %ls\n", (unsigned int *)i);
	printf("result of ft_calloc(-5, -5): %ls\n", (unsigned int *)i1);
	printf("result of ft_calloc(5, 0): %ls\n", (unsigned int *)i2);
	free(i);
	free(i1);
	free(i2);
}

void	test_strdup()
{
    printf("\nTesting strdup...\n");
	const char *s1 = "Hello, World!";
    char *s2 = ft_strdup(s1);

    if (s2 == NULL)
    {
       printf("Memory allocation failed\n");
        return ;
    }

    printf("Original string: %s\n", s1);
    printf("Duplicated string: %s\n", s2);

    free(s2);
}

int main(void)
{
    printf("Patr 1:\n");
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_strchr();
    test_strrchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
    test_calloc();
    test_strdup();
    return (0);
}
