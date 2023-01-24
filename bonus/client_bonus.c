/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/24 17:43:34 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handelerror(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void	signalreceived(int signum)
{
	if (signum == SIGUSR1)
		write(1, "message received", 16);
}

// loop of each bit
void	bitchar(char c, pid_t pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (128 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(700);
	}
}

// loop of each character
void	message(char *data, pid_t pid)
{
	while (*data)
	{
		bitchar(*data, pid);
		data++;
	}
	bitchar('\0', pid);
}

// 3 argument  : 1)./client 2)server pid 3) string to sent
int	main(int argc, char **argv)
{
	pid_t	pid;

	signal(SIGUSR1, signalreceived);
	if (argc != 3)
		handelerror();
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		handelerror();
	message(argv[2], pid);
}
