/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:00:49 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/20 15:35:55 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	perror_exit(t_cmd *cmd, char *msg)
{
	perror(msg);
	ft_exit(cmd);
}

void	ft_exit(t_cmd *cmd)
{
	if (cmd && cmd->here_doc)
	{
		close(cmd->infile_fd);
		unlink(cmd->heredoc_file);
	}
	exit(0);
}

void	print_error_exit(t_cmd *cmd, char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_exit(cmd);
}

void	wait_all(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->pid)
			waitpid(cmd->pid, 0, 0);
		cmd = cmd->next;
	}
}
