/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:52:16 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/17 21:35:30 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char	g_bit[8];

// 
// void	handler(int signum)
// {
// 	static int i = 0;
// 	static char	c = 0;

// 	if (signum == SIGUSR1)
// 		c = c * 2 + 1;

// 	else if (signum == SIGUSR2)
// 		c = c * 2;

// 	i++;
// 	if(i == 8)
// 	{
// 		printf("%c\n", c);
// 		i = 0;
// 		c = 0;
// 	}
// }


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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printchar(char	*c)
{
	int	j;
	int	somme;
	int	index;
	int	base;

	somme = 0;
	index = 0;
	base = 2;
	j = strlen(c);
	j--;
	while (c[j])
	{
		if (c[j] == '1')
			somme = somme + ft_power(base, index);
		index++;
		j--;
	}
	ft_putchar(somme);
}

// append bit character in array
void	handler(int signum)
{
	static int	i;

	if (signum == SIGUSR1)
		g_bit[i++] = '1';
	else if (signum == SIGUSR2)
		g_bit[i++] = '0';
	if (i == 8)
	{
		printchar(g_bit);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction		signal;

	signal.sa_handler = handler;
	printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}





