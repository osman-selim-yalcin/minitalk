/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:10:43 by osyalcin          #+#    #+#             */
/*   Updated: 2022/07/28 11:08:56 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mreadsig(int signum)
{
	static char	a = 0;
	static int	i = 0;

	a |= (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &a, 1);
		a = 0;
		i = 0;
	}
	a <<= 1;
}

int	main(void)
{
	ft_printf("getpid: %d\n", getpid());
	signal(SIGUSR1, mreadsig);
	signal(SIGUSR2, mreadsig);
	while (1)
	{
		pause();
	}
	return (0);
}
