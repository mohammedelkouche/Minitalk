/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:42:58 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/19 21:17:40 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_bit[8];

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

void	printchar(char	*c)
{
	int	j;
	int	somme;
	int	index;
	int	base;

	somme = 0;
	index = 0;
	base = 2;
	j = ft_strlen(c);
	j--;
	while (c[j])
	{
		if (c[j] == '1')
			somme = somme + ft_power(base, index);
		index++;
		j--;
	}
	write(1, &somme, 1);
}
// append bit character in array

void	handlersignal(int signum, siginfo_t *info)
{
	static int			i;
	size_t				j;
	static pid_t		s_pid;

	j = 0;
	if (s_pid != info->si_pid)
	{
		while (j < 8)
		{
			g_bit[j] = 0;
			j++;
		}
		i = 0;
	}
	if (signum == SIGUSR1)
		g_bit[i++] = '1';
	else if (signum == SIGUSR2)
		g_bit[i++] = '0';
	if (i == 8)
	{
		printchar(g_bit);
		i = 0;
	}
	s_pid = info->si_pid;
}

int	main(int argc, char **argv)
{
	struct sigaction		action;

	(void)argc;
	(void)argv;
	action.sa_handler = (void *)handlersignal;
	ft_putnb(getpid());
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
}
