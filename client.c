/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elzekaj <elzekaj@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-18 15:38:52 by elzekaj           #+#    #+#             */
/*   Updated: 2025-11-18 15:38:52 by elzekaj          ###   ########elzekaj@  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t pid, char *msg)
{
	int		bit_mask;
	char	current_char;

	while (*msg)
	{
		current_char = *msg++;
		bit_mask = 0b10000000;
		while (bit_mask)
		{
			if (current_char & bit_mask)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_mask >>= 1;
			usleep (100);
		}
	}
}

int	main(int ac, char **av)
{
	char	*msg;
	int		pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", av[0]);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Error: Invalid pid.\n");
		return (EXIT_FAILURE);
	}
	msg = ft_strdup(av[2]);
	send_msg(pid, msg);
	free(msg);
	return (EXIT_SUCCESS);
}
