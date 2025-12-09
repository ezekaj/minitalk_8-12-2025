/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elzekaj <elzekaj@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-18 15:38:48 by elzekaj           #+#    #+#             */
/*   Updated: 2025-11-18 15:38:48 by elzekaj          ###   ########elzekaj@  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	g_bytes;

void	handle_sig(int signum)
{
	static int	bit_pos = 0;

	if (signum == SIGUSR1)
		g_bytes |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8)
	{
		write(1, &g_bytes, 1);
		bit_pos = 0;
		g_bytes = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_bytes = 0;
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handle_sig;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Failed to set SIGUSR1 handler\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Failed to set SIGUSR2 handler\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
