/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:55:26 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/23 15:52:29 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

static int	g_total;

void	total_byte(int nbyte, int sum, int flag)
{
	g_total = g_total + sum;
	nbyte--;
	if (nbyte == 0)
	{
		ft_putxchar(g_total);
		g_total = 0;
		flag = 0;
	}
}

void	check_byte(int sum)
{
	int static	nbyte;
	int static	flag;

	// if (g_total == 0)
	// 	flag = 0;
	if (flag == 0)
	{
		if (sum < 128)
			nbyte = 1;
		else if (sum >= 192 && sum < 224)
			nbyte = 2;
		else if (sum >= 224 && sum < 240)
			nbyte = 3;
		else if (sum >= 240 && sum < 248)
			nbyte = 4;
		flag = 1;
	}
	total_byte(nbyte, sum, flag);
}

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

void	sum_char(char	*c)
{
	int	j;
	int	sum;
	int	index;
	int	base;

	sum = 0;
	index = 0;
	base = 2;
	j = ft_strlen(c);
	j--;
	while (c[j])
	{
		if (c[j] == '1')
			sum = sum + ft_power(base, index);
		index++;
		j--;
	}
	check_byte(sum);
}

void	handlersignal(int signum, siginfo_t *info, void *p)
{
	static int			i;
	size_t				j;
	static pid_t		s_pid;
	static char			g_bit[8];

	(void)p;
	j = -1;
	if (s_pid != info->si_pid)
	{
		while (++j < 8)
			g_bit[j] = 0;
		i = 0;
		g_total = 0;
	}
	if (signum == SIGUSR1)
		g_bit[i++] = '1';
	else if (signum == SIGUSR2)
		g_bit[i++] = '0';
	printf("%c", g_bit[i]);
	if (i == 8)
	{
		sum_char(g_bit);
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
	ft_putxchar('\n');
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
