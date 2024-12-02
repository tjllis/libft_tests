#include "libft.h"
#include <stdio.h>

static void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

static void del(void *content)
{
	free(content);
}

static void print_content(void *content)
{
    if (content)
        printf("%s\n", (char *)content);
}

static void *to_uppercase(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32; // Convert to uppercase
    }
    return (void *)str;
}

static void print_list_char(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void test_lstnew()
{
	printf("Testing ft_lstnew...\n");
	char *str = "Hello, I'm a string";
	t_list *node = ft_lstnew(str);
	printf("Test 1: a string with a content\n");
	printf("Original string: %s\n", str);
	printf("Copied to node: %s\n", (char *)node->content);
	// ft_lstclear(&node, del);
	free(node);
	printf("Test 2: a string with a NULL content\n");
	char *str1;
	t_list *node1 = ft_lstnew(str1);
	printf("Original string: %s\n", str1);// (null)
	printf("\n");
	printf("Copied to node: %s\n", (char *)node1->content);// (null)
	printf("\n");
	free(node1);
}

void test_lstadd_front()
{
	printf("\nTesting ft_lstadd_front...\n");
	// Test Case 1: Add a node to an empty list
	t_list *list = NULL;
	int val1 = 42;
	t_list *node1 = ft_lstnew(&val1);
	ft_lstadd_front(&list, node1);

	printf("Test 1: After adding a node to empty list: ");
	print_list(list); // Expected: 42 -> NULL

	// Test Case 2: Add another node to the front
	int val2 = 56;
	t_list *node2 = ft_lstnew(&val2);
	ft_lstadd_front(&list, node2);

	printf("Test 2: After adding another node to the front: ");
	print_list(list); // Expected: 56 -> 42 -> NULL

	// Test Case 3: Add more nodes to the front
	int val3 = 99;
	t_list *node3 = ft_lstnew(&val3);
	ft_lstadd_front(&list, node3);

	printf("Test 3: After adding a third node to the front: ");
	print_list(list); // Expected: 99 -> 56 -> 42 -> NULL

	// Free the list to prevent memory leak
	free(node1);
	free(node2);
	free(node3);
}

void test_lstadd_back()
{
	printf("\nTesting ft_lstadd_back...\n");
	// Test Case 1: Adding to an empty list
	t_list *list1 = NULL;
	int val1 = 42;
	t_list *node1 = ft_lstnew(&val1);

	ft_lstadd_back(&list1, node1);
	printf("Test 1: List after adding to empty list: ");
	print_list(list1); // Expected: 42 -> NULL

	// Test Case 2: Adding a node to a list with one node
	int val2 = 56;
	t_list *node2 = ft_lstnew(&val2);
	ft_lstadd_back(&list1, node2);
	printf("Test 2: List after adding another node: ");
	print_list(list1); // Expected: 42 -> 56 -> NULL

	// Test Case 3: Adding a node to a list with multiple nodes
	int val3 = 99;
	t_list *node3 = ft_lstnew(&val3);
	ft_lstadd_back(&list1, node3);
	printf("Test 3: List after adding a third node: ");
	print_list(list1); // Expected: 42 -> 56 -> 99 -> NULL

	// Free the list to prevent memory leak
	free(node1);
	free(node2);
	free(node3);
}

void test_lstsize()
{
	printf("\nTesting ft_lstsize...\n");
	// Test Case 1: Empty list
	t_list *list1 = NULL;
	printf("Test 1: Size of empty list: %d\n", ft_lstsize(list1)); // Expected: 0

	// Test Case 2: List with 1 node
	int val1 = 42;
	t_list *node1 = ft_lstnew(&val1);
	printf("Test 2: Size of list with 1 node: %d\n", ft_lstsize(node1)); // Expected: 1

	// Test Case 3: List with 3 nodes
	int val2 = 56;
	t_list *node2 = ft_lstnew(&val2);
	node1->next = node2; // Link node1 to node2

	int val3 = 99;
	t_list *node3 = ft_lstnew(&val3);
	node2->next = node3; // Link node2 to node3

	printf("Test 3: Size of list with 3 nodes: %d\n", ft_lstsize(node1)); // Expected: 3

	// Free the list to prevent memory leak
	free(node1);
	free(node2);
	free(node3);
}

void test_lstlast()
{
	printf("\nTesting ft_lstlast...\n");
	// Test Case 1: Empty list
	t_list *list1 = NULL;
	t_list *last1 = ft_lstlast(list1);
	if (last1)
		printf("Test 1: Last node content: %d\n", *(int *)last1->content);
	else
		printf("Test 1: Empty list, last node is NULL.\n"); // Expected: NULL

	// Test Case 2: List with 1 node
	int val1 = 42;
	t_list *node1 = ft_lstnew(&val1);
	t_list *last2 = ft_lstlast(node1);
	printf("Test 2: Last node content: %d\n", *(int *)last2->content); // Expected: 42

	// Test Case 3: List with 3 nodes
	int val2 = 56;
	t_list *node2 = ft_lstnew(&val2);
	node1->next = node2; // Link node1 to node2

	int val3 = 99;
	t_list *node3 = ft_lstnew(&val3);
	node2->next = node3; // Link node2 to node3

	t_list *last3 = ft_lstlast(node1);
	printf("Test 3: Last node content: %d\n", *(int *)last3->content); // Expected: 99

	// Free the list to prevent memory leak
	free(node1);
	free(node2);
	free(node3);
}

void test_lstdelone()
{
	t_list	*temp;
     printf("\nTesting ft_lstdelone...\n");

    // Step 1: Create a list with three nodes
    t_list *list = ft_lstnew(malloc(sizeof(int)));
    *(int *)list->content = 42;
    

    list->next = ft_lstnew(malloc(sizeof(int)));
    *(int *)list->next->content = 56;

    list->next->next = ft_lstnew(malloc(sizeof(int)));
    *(int *)list->next->next->content = 99;

    // Print initial list
    printf("Initial list: ");
    print_list(list);

    // // Step 2: Delete the second node (56)
     t_list *second_node = list->next;
     temp = list->next->next; // Save a pointer to the second node
    ft_lstdelone(second_node, del);   // Ensure `del` frees content
    list->next = temp;   // Fix the list after deletion
    printf("After deleting second node: ");
    print_list(list); // Expected: 42 -> 99 -> NULL

    // Step 3: Delete the last node (99)
    t_list *last_node = list->next;
    ft_lstdelone(last_node, del);     // Ensure `del` frees content
    list->next = NULL;                // Fix the list after deletion
    printf("After deleting last node: ");
    print_list(list); // Expected: 42 -> NULL

    // Step 4: Delete the first node (42)
    t_list *first_node = list;
    ft_lstdelone(first_node, del);    // Ensure `del` frees content
    list = NULL;                      // Fix the list after deletion
    printf("After deleting first node: ");
    print_list(list); // Expected: NULL
}

void test_lstclear()
{
	printf("\nTesting ft_lstclear...\n");
    //Create a list with three nodes
    t_list *list = ft_lstnew(malloc(sizeof(int)));
    *(int *)list->content = 42;
    list->next = ft_lstnew(malloc(sizeof(int)));
    *(int *)list->next->content = 56;
    list->next->next = ft_lstnew(malloc(sizeof(int)));
    *(int *)list->next->next->content = 99;

    printf("Test 1: List before clearing: ");
    print_list(list);  // Expected: 42 -> 56 -> 99 -> NULL

    // Clear the list
    ft_lstclear(&list, del);
    printf("Test 2: List after clearing: ");
    print_list(list);  // Expected: NULL
}

void test_lstiter()
{
    // Create a few nodes with sample content
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    // Link the nodes together
    node1->next = node2;
    node2->next = node3;

    // Call ft_lstiter with the list and the print_content function
    printf("\n Testing ft_lstiter with print_content...\n");
    ft_lstiter(node1, print_content);
	free(node3);
	free(node2);
	free(node1);
}

void test_lstmap()
{
	printf("\nTesting ft_lstmap...\n");
    // Create some sample content and nodes
    char *str1 = ft_strdup("hello");
    char *str2 = ft_strdup("world");
    char *str3 = ft_strdup("test");

    t_list *node1 = ft_lstnew(str1);
    t_list *node2 = ft_lstnew(str2);
    t_list *node3 = ft_lstnew(str3);

    // Link the nodes together
    node1->next = node2;
    node2->next = node3;

    // Print the original list
    printf("Original list:\n");
    print_list_char(node1);

    // Apply the ft_lstmap function with the to_uppercase function and del_content for cleanup
    t_list *new_list = ft_lstmap(node1, to_uppercase, del);

    // Print the new list
    printf("\nTransformed list (uppercase):\n");
    print_list_char(new_list);

    // Clean up the new list
	free(node3);
	free(node2);
	free(node1);
    ft_lstclear(&new_list, del);
}

int main(void)
{
	test_lstnew();
	test_lstadd_back();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();
	return (0);
}
