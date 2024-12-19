/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:42:08 by yaait-am          #+#    #+#             */
/*   Updated: 2024/12/19 20:18:53 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char c = 0;
	static int numbit = 0;
	(void) context;
	if (sig == SIGUSR1)
		c |= (1 << numbit);
	else if (sig == SIGUSR2)
		c &= ~(1 << numbit);
	numbit++;
	if (numbit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		numbit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("this the pid : %d\nwaiting for signal...\n", getpid());
	while (1)
		pause();
	return(0);
}
