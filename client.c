/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/16 10:38:37 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	message(char *data, pid_t pid)
{
	int	i;

	// loop of each character
	while (*data)
	{
		i = 0;
      // loop of each bit
      while (i < 8)
		{
			if (*data & (128 >> i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(500);
		}
		data++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	// 3 argument  : 1)./client 2)server pid 3) string to sent
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		message(argv[2], pid);
	}
}
// test

// int	main(int argc, char *argv[])
// {
//    int	pid;

//    if (argc != 2)
//    {
//    	printf("client: invalid arguments\n");
//    }
//    pid = atoi(argv[1]);
//    kill(pid, SIGUSR1);
//    return (0);
// }