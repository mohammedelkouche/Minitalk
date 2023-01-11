#include <stdio.h>

int	main(int argc, char **argv)
{
   int		i;
   int		bitshift;
   char	word;

   if (argc != 2)
   	return (1);
   word = argv[1][0];
   bitshift = -1;
   printf("%c[%d]: ", word, word);
   while (++bitshift < 8)
   {
   	if (word & (0x80 >> bitshift))
   		printf("1");
   	else
   		printf("0");
   }
   printf("\n");
   return (0);
}