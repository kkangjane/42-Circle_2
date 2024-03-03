/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:02:32 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/20 19:23:37 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	put_cmd(t_cmd *cmd, char **cmds);

void	check_arg(t_cmd	*cmd, char **argv, int argc)
{
	cmd->here_doc = 0;
	if (argc < 5)
	{
		ft_putendl_fd("pipex: need more than 5 arguments", STDERR_FILENO);
		exit(1);
	}
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		cmd->here_doc = 1;
	if (argc - 3 - cmd->here_doc < 2)
	{
		ft_putendl_fd("pipex: need more than 5 arguments", STDERR_FILENO);
		exit(1);
	}
}

void	init(t_cmd *cmd, int argc, char **argv, char **envp)
{
	init_arg(cmd, cmd, argc - 3 - cmd->here_doc);
	put_cmd(cmd, &(argv[2 + cmd->here_doc]));
	find_cmds(cmd, envp);
	if (cmd->here_doc == 0)
		open_files(cmd, argv, argc);
	else
		open_files_h(cmd, argv, argc);
}

void	init_arg(t_cmd *start, t_cmd *cmd, int cmd_cnt)
{
	int	i;

	i = 0;
	while (1)
	{
		cmd->idx = i++;
		cmd->infile_fd = -1;
		cmd->outfile_fd = -1;
		cmd->cmd = 0;
		cmd->cmd_args = 0;
		cmd->err = 0;
		if (i == cmd_cnt)
		{
			cmd->next = 0;
			return ;
		}
		cmd->next = (t_cmd *) malloc(sizeof(t_cmd));
		cmd = cmd->next;
		if (!cmd)
			perror_exit(start, "pipex: ");
	}
	cmd->next = 0;
}

static void	put_cmd(t_cmd *cmd, char **cmds)
{
	int	i;

	i = 0;
	while (cmd)
	{
		cmd->cmd_args = ft_split(cmds[i++], ' ');
		if (cmd->cmd_args == 0)
			cmd->err = 1;
		else
			cmd->cmd = cmd->cmd_args[0];
		cmd = cmd->next;
	}
}
