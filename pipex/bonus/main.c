/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:59:25 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/21 12:15:49 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	process(t_cmd *start, t_cmd *cmd, char **envp);
static void	child_process(t_cmd *start, t_cmd *cmd, char **envp);
static void	last_child_process(t_cmd *start, t_cmd *cmd, char **envp);

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd)
	{
		perror("pipex: ");
		exit(1);
	}
	check_arg(cmd, argv, argc);
	init(cmd, argc, argv, envp);
	process(cmd, cmd, envp);
	wait_all(cmd);
	ft_exit(cmd);
	return (0);
}

static void	process(t_cmd *start, t_cmd *cmd, char **envp)
{
	dup2(cmd->infile_fd, STDIN_FILENO);
	while (cmd->next)
	{
		child_process(start, cmd, envp);
		cmd = cmd->next;
	}
	last_child_process(start, cmd, envp);
}

void	child_process(t_cmd *start, t_cmd *cmd, char **envp)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		perror_exit(start, 0);
	cmd->pid = fork();
	if (cmd->pid == -1)
		perror_exit(start, 0);
	if (cmd->pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (cmd->err)
			exit(1);
		else if (execve(cmd->cmd, cmd->cmd_args, envp) == -1)
			perror("pipex");
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
	}
}

static void	last_child_process(t_cmd *start, t_cmd *cmd, char **envp)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		perror_exit(start, 0);
	if (cmd->pid == 0)
	{
		dup2(cmd->outfile_fd, STDOUT_FILENO);
		if (cmd->err)
			exit(1);
		else if (execve(cmd->cmd, cmd->cmd_args, envp) == -1)
			perror("pipex: ");
	}
	else
	{
		close(cmd->outfile_fd);
		dup2(1, STDOUT_FILENO);
	}
}
