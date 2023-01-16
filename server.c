/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:52:16 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/16 21:34:25 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// append bit in array (string) whith strncat
void	handler(int signum)
{
	static char	c;
	char		bit[9];

	if (signum == SIGUSR1)
		write(1, "1", 1);
	else if (signum == SIGUSR2)
		write(1, "0", 1);
}

int	main(void)
{
	struct sigaction		signal;

	signal.sa_handler = handler;
	// signal.
	printf("%d\n", getpid());
	while (1)
	{
		// printf("hellow \n");
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
		// printf("world!\n");
	}
}

// test

// void	handler_sigusr1(int signum)
// {
//    printf("signal %d received.\n", signum);
// }

// int	main(void)
// {
//    pid_t	pid;

//    pid = getpid();
//    printf("PID: %d\n", pid);
//    signal(SIGUSR1, handler_sigusr1);
//    printf("is this lign execute ! \n");
//    while (1)
//    {
//       printf("hellow world! \n");
//    	pause();
//    }
// }