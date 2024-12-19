/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:38:03 by yaait-am          #+#    #+#             */
/*   Updated: 2024/12/19 20:19:03 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_ddd = 0;

void	handle_ack(int sig)
{
	(void) sig;
	g_ddd = 1;
}

void	send_mess(int pid, char c)
{
	int i;
	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ddd == 0)
			pause();
		g_ddd = 0;
		i++;
	}
}

int main(int ac, char **av) {
	if (ac != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	int pid = atoi(av[1]);
	char *s = av[2];
	int i = 0;
	signal(SIGUSR1, handle_ack);
	while (s[i])
	{
		send_mess(pid, s[i]);
		i++;
	}
	send_mess(pid, '\0');
	return(0);
}
