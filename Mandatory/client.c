/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/27 15:23:31 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handelerror(void)
{
	write(1, "error\n", 6);
	exit(1);
}

// loop of each bit
void	bitchar(char c, pid_t pid, int interval)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (128 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(interval);
	}
}

// loop of each character
void	message(char *data, pid_t pid)
{
	size_t	size;
	int		interval;

	size = ft_strlen(data);
	if (size > 6000)
		interval = 1400;
	else
		interval = 600;
	while (*data)
	{
		bitchar(*data, pid, interval);
		data++;
	}
	bitchar('\0', pid, interval);
}

// 3 argument  : 1)./client 2)server pid 3) string to sent
int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		handelerror();
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		handelerror();
	message(argv[2], pid);
}
