/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:10:56 by osyalcin          #+#    #+#             */
/*   Updated: 2022/07/28 21:18:48 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long int	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ret = ret * 10 + ((*str) - '0') * sign;
		if (ret > 2147483647)
			return (-1);
		else if (ret < -2147483648)
			return (0);
		str++;
	}
	return (ret);
}

void	fonk(pid_t s)
{
	(void )s;
	ft_printf("SUCCESS\n");
}

void	ctob(pid_t a, char d)
{
	int	i;

	i = 8;
	while (i != 0)
	{
		if (d >> (i - 1) & 1)
		{
			kill(a, SIGUSR1);
			usleep(150);
		}
		else
		{
			kill(a, SIGUSR2);
			usleep(150);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	k;
	int	l;

	if (argc != 3)
	{
		ft_printf("error\n");
		return (0);
	}
	signal(SIGUSR1, fonk);
	l = 0;
	k = ft_atoi(argv[1]);
	while (argv[2][l] != '\0')
	{
		ctob(k, argv[2][l]);
		l++;
	}
	ctob(k, argv[2][l]);
	return (1);
}
