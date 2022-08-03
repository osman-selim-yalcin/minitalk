/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:19:43 by osyalcin          #+#    #+#             */
/*   Updated: 2022/07/28 21:20:51 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

int		ft_atoi(const char *str);
void	fonk(pid_t s);
void	ctob(pid_t a, char d);
void	readsig(int signum, siginfo_t *sd, void *k);

#endif