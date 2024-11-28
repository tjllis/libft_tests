int	main(void)
{	char *big = "Table top is black";
	char *sub = ft_substr(big, 5, 10);
	printf("%s\n", sub);
	
	char	str[] = "lorem ipsum dolor sit amet"; //26
	char *substr = ft_substr(str, 0, 10);
	char *strsub = ft_substr(str, 7, 10);
	char *test = ft_substr("hola", 0, 0);
	printf("%s\n", substr);
	printf("%s\n", strsub);
	printf("%s\n", test);
	free(sub);
	free(substr);
	free(strsub);
	char *str = "01234";
 	size_t size = 10;
 	char *ret = ft_substr(str, 10, size);
 	printf("%s\n", ret);
 	if (!ft_strncmp(ret, "", 1))
 		printf("Success\n");
 	else
 		printf("Fail\n");
 	free(ret);
	return (0);
}*/
