/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:10:43 by osyalcin          #+#    #+#             */
/*   Updated: 2022/07/28 23:40:42 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	readsig(int signum, siginfo_t *sd, void *k)
{
	static char	a = 0;
	static int	i = 0;
	static int	l = 0;

	a |= (signum == SIGUSR1);
	i++;
	(void) k;
	if (i == 8)
	{
		write(1, &a, 1);
		l++;
		if (a == '\0')
		{
			l--;
			ft_printf("\ndata recieved from here %d", sd->si_pid);
			ft_printf("\ntotal word count: %d\n", l);
			if (kill(sd->si_pid, SIGUSR1) == -1)
				ft_printf("error");
		}
		a = 0;
		i = 0;
	}
	a <<= 1;
}

int	main(void)
{
	struct sigaction	sl;

	sl.sa_flags = SA_SIGINFO;
	sl.sa_sigaction = readsig;
	ft_printf("getpid: %d\n", getpid());
	sigaction(SIGUSR1, &sl, 0);
	sigaction(SIGUSR2, &sl, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
