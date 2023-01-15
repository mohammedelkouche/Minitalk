/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:52:16 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/15 21:04:35 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handler(int signum)
{
	static char	c;
	static int	bit;

	// if (signum == SIGUSR1)

}

int	main(void)
{
	pid_t					pid;
	struct sigaction		signal;

	pid = getpid();
	signal.sa_handler = &handler;
	while (1)
		pause();
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