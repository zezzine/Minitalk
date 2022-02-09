/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:00:48 by zezzine           #+#    #+#             */
/*   Updated: 2022/02/07 13:52:51 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sig)
{
	static int			size;
	static char			to_print;

	to_print += ((sig % 2) << size);
	size++;
	if (size == 8)
	{
		ft_putchar(to_print);
		if (!to_print)
			ft_putchar('\n');
		to_print = 0;
		size = 0;
	}
}

int	main(void)
{
	pid_t		pid;
	int			b;

	b = 0;
	pid = getpid();
	ft_putstr("My Process ID is\n");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
