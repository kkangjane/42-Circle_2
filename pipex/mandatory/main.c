/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:05:32 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/20 16:03:26 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	child_p1(t_pipe *arg, char **envp);
static	void	child_p2(t_pipe *arg, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_pipe	arg;

	if (argc != 5)
		return (write_error("argument error\n", 0));
	init_arg(&arg);
	parsing(&arg, argv, envp);
	if (pipe(arg.pipe_fd) < 0)
		error_exit("pipe error");
	child_p1(&arg, envp);
	child_p2(&arg, envp);
	waitpid(arg.pid1, 0, 0);
	waitpid(arg.pid2, 0, 0);
	exit(0);
	return (0);
}

static	void	child_p1(t_pipe *arg, char **envp)
{
	dup2(arg->infile, STDIN_FILENO);
	arg->pid1 = fork();
	if (arg->pid1 == -1)
		exit(1);
	if (arg->pid1 == 0)
	{
		close(arg->pipe_fd[0]);
		dup2(arg->pipe_fd[1], STDOUT_FILENO);
		close(arg->pipe_fd[1]);
		if (arg->p1_error)
			exit(1);
		else
			execve(arg->cmd1, arg->cmd1_args, envp);
	}
	else
	{
		close(arg->pipe_fd[1]);
		dup2(arg->pipe_fd[0], STDIN_FILENO);
	}
}

static	void	child_p2(t_pipe *arg, char **envp)
{
	arg->pid2 = fork();
	if (arg->pid2 == -1)
		exit(1);
	if (arg->pid2 == 0)
	{
		close(arg->pipe_fd[1]);
		dup2(arg->outfile, STDOUT_FILENO);
		if (arg->p1_error)
			exit(1);
		else
			execve(arg->cmd2, arg->cmd2_args, envp);
	}
	else
	{
		close(arg->outfile);
		dup2(1, STDOUT_FILENO);
	}
}
