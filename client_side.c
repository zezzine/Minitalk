/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:51:33 by zezzine           #+#    #+#             */
/*   Updated: 2022/02/07 13:53:00 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t			pid;
	int				bit;
	int				i;

	i = 0;
	if (argc != 3)
		return (ft_putstr("Wrong arguments\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_putstr("Process id not valid\n"), 0);
	while (argv[2][i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((argv[2][i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(800);
			bit++;
		}
		i++;
	}
}
