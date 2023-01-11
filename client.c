/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/11 13:42:58 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	message(char *data, pid_t pid)
{
	int	i;

	// loop of each character
	while (*data)
	{
		i = 0;
		while (i < 8)
		{
			if (*data & (128 >> i))
			
		}
		*data++;
	}
	
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	// 3 argument  : 1)./client 2)server pid 3) string to sent
	// pid_t getpid(void);
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		message(argv[2], pid);
	}
}
