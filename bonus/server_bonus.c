/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:36:52 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/23 22:07:05 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	printchar(char	*c, pid_t s_pid)
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
	if (somme == 0)
		kill(s_pid, SIGUSR1);
	ft_putxchar(somme);
}
// append bit character in array

void	handlersignal(int signum, siginfo_t *info, void *p)
{
	static int			i;
	size_t				j;
	static pid_t		s_pid;
	static char			byte[8];

	(void)p;
	j = -1;
	if (s_pid != info->si_pid)
	{
		while (++j < 8)
			byte[j] = 0;
		i = 0;
		s_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		byte[i++] = '1';
	else if (signum == SIGUSR2)
		byte[i++] = '0';
	if (i == 8)
	{
		printchar(byte, s_pid);
		i = 0;
	}
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
