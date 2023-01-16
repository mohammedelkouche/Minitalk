#include <stdio.h>
#include <string.h>

int	ft_power(int base, int index)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (index > i)
	{
		res = res * base;
		i++;
	}
	return (res);
}

int	main(void)
{
	int	j;
	int	somme;
	int	index;
	int	base;

	somme = 0;
	index = 0;
	base = 2;
	char t[9] = "01100001";
	j = strlen(t);
	j--;
	while (t[j])
	{
		if (t[j] == '1')
		{
			somme = somme + ft_power(base, index);
			printf("%d\n", somme);
		}
		index++;
		j--;
	}
	printf("\n%d\n", somme);
	putchar(somme);
}

// int	main(int argc, char **argv)
// {

   // int		i;
   // int		bitshift;
   // char	word;

   // if (argc != 2)
   // 	return (1);
   // word = argv[1][0];
   // bitshift = -1;
   // printf("%c[%d]: ", word, word);
   // while (++bitshift < 8)
   // {
   // 	if (word & (0x80 >> bitshift))
   // 		printf("1");
   // 	else
   // 		printf("0");
   // }
   // printf("\n");
   // return (0);
// 
