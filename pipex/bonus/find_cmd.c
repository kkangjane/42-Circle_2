/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:23:09 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/08 16:41:44 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	**get_paths(char **envp);
static char	*find_cmd(char **paths, char *cmd);
static void	free_paths(char **paths);

void	find_cmds(t_cmd *cmd, char **envp)
{
	char	*command;
	char	**paths;

	paths = get_paths(envp);
	while (cmd)
	{
		command = find_cmd(paths, cmd->cmd);
		if (command == 0)
		{
			ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
			ft_putendl_fd(cmd->cmd, STDERR_FILENO);
			cmd->err = 1;
		}
		else if (access(command, X_OK) == -1)
		{
			ft_putstr_fd("pipex: permission denied: ", STDERR_FILENO);
			ft_putendl_fd(cmd->cmd, STDERR_FILENO);
			free(command);
			command = 0;
			cmd->err = 1;
		}
		cmd->cmd = command;
		cmd = cmd->next;
	}
	free_paths(paths);
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

static char	*find_cmd(char **paths, char *cmd)
{
	char	*cmdd;
	char	*path_cmd;
	int		i;

	if (cmd == 0 || cmd[0] == 0)
		return (0);
	else if (ft_strrchr(cmd, '/') && access(cmd, F_OK) != -1)
		return (cmd);
	else if (ft_strrchr(cmd, '/') && access(cmd, F_OK) == -1)
		return (0);
	cmdd = ft_strjoin("/", cmd);
	i = -1;
	while (paths && paths[++i])
	{
		path_cmd = ft_strjoin(paths[i], cmdd);
		if (access(path_cmd, F_OK) != -1)
		{
			free(cmdd);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free(cmdd);
	return (0);
}

static void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}
