/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:59:22 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/20 16:00:47 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	write_error(char *msg, char *per)
{
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		if (per)
			write(2, ": ", 2);
	}
	if (per)
		perror(per);
	return (0);
}

void	init_arg(t_pipe *arg)
{
	arg->cmd1 = 0;
	arg->cmd2 = 0;
	arg->paths = 0;
	arg->cmd1_args = 0;
	arg->cmd2_args = 0;
	arg->p1_error = 0;
	arg->p2_error = 0;
}

void	error_exit(char *per)
{
	perror(per);
	exit(1);
}
