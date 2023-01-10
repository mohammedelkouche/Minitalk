/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/10 17:19:16 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int	i;
	
	i = 0;
	// 3 argument  : 1)./client 2)server pid 3) string to sent
	// pid_t getpid(void);
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		while (argv[2][i])
		{
			
		}
		
	}
}
