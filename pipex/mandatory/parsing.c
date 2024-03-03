/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:23:05 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/07 20:33:44 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	open_file(t_pipe *arg, char *file_name, int in_out);
static	char	**get_paths(char **envp);
static	char	*find_command(char **paths, char **cmd_args);

void	parsing(t_pipe *arg, char **argv, char **envp)
{
	open_file(arg, argv[1], 0);
	open_file(arg, argv[4], 1);
	arg->paths = get_paths(envp);
	arg->cmd1_args = ft_split(argv[2], ' ');
	arg->cmd2_args = ft_split(argv[3], ' ');
	arg->cmd1 = find_command(arg->paths, arg->cmd1_args);
	arg->cmd2 = find_command(arg->paths, arg->cmd2_args);
	if (arg->cmd1 == 0)
	{
		arg->p1_error = 1;
		write(2, "pipex: ", 7);
		if (arg->cmd1_args && arg->cmd1_args[0])
			write(2, arg->cmd1_args[0], ft_strlen(arg->cmd1_args[0]));
		write(2, ": command not found\n", 20);
	}
	if (arg->cmd2 == 0)
	{
		arg->p2_error = 1;
		write(2, "pipex: ", 7);
		if (arg->cmd2_args && arg->cmd2_args[0])
			write(2, arg->cmd2_args[0], ft_strlen(arg->cmd2_args[0]));
		write(2, ": command not found\n", 20);
	}
}

static	void	open_file(t_pipe *arg, char *file_name, int in_out)
{
	if (in_out == 0)
	{
		arg->infile = open(file_name, O_RDONLY);
		if (arg->infile == -1)
		{
			write_error("pipex", file_name);
			arg->p1_error = 1;
		}
	}
	else
	{
		arg->outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (arg->outfile == -1)
		{
			write_error("pipex", file_name);
			arg->p2_error = 1;
		}
	}
}

static char	**get_paths(char **envp)
{
	int		i;
	char	*paths;
	char	**result;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			paths = ft_strdup(envp[i] + 5);
			result = ft_split(paths, ':');
			free(paths);
			return (result);
		}
		i++;
	}
	return (0);
}

static	char	*find_command(char **paths, char **cmd_args)
{
	char	*cmd;
	char	*path_cmd;
	int		i;

	if (cmd_args == 0 || cmd_args[0] == 0 || cmd_args[0][0] == 0)
		return (0);
	if (ft_strrchr(cmd_args[0], '/') != 0 && access(cmd_args[0], X_OK) != -1)
		return (cmd_args[0]);
	if (ft_strrchr(cmd_args[0], '/') != 0 && access(cmd_args[0], X_OK) == -1)
		return (0);
	cmd = ft_strjoin("/", cmd_args[0]);
	i = 0;
	while (paths && paths[i])
	{
		path_cmd = ft_strjoin(paths[i++], cmd);
		if (access(path_cmd, X_OK) != -1)
		{
			free(cmd);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free(cmd);
	return (0);
}
