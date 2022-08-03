/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:31:01 by osyalcin          #+#    #+#             */
/*   Updated: 2022/07/28 21:20:54 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

int		ft_atoi(const char *str);
void	fonk(pid_t s);
void	ctob(pid_t a, char d);
void	mreadsig(int signum);

#endif