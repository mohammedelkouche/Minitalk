/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/23 23:15:58 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// void signalreceived(int signum)
// {
// 	if (signum ==  SIGUSR1)
// 		write(1, "message", 7);
// }

void	message(char *data, pid_t pid)
{
	int	i;

	// loop of each character
	while (*data)
	{
		i = -1;
		// loop of each bit
		while (++i < 8)
		{
			if (*data & (128 >> i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(700);
		}
		data++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	// 3 argument  : 1)./client 2)server pid 3) string to sent
	// signal(SIGUSR1, &signalreceived);
	if(argc != 3)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	message(argv[2], pid);
}
