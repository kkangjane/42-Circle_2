/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:05:38 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/08 16:39:39 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*heredoc(t_cmd *cmd, char *limiter, char *outfile);
static char	*choose_heredoc_file(char *outfile);
static int	check_limiter(char *str, char *limiter);

void	open_files(t_cmd *cmd, char **argv, int argc)
{
	cmd->infile_fd = open(argv[1], O_RDONLY);
	if (cmd->infile_fd == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		cmd->err = 1;
	}
	while (cmd->next)
		cmd = cmd->next;
	cmd->outfile_fd = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (cmd->outfile_fd == -1)
	{
		ft_putendl_fd("pipex: cannot open outfile", STDERR_FILENO);
		cmd->err = 1;
	}
}

void	open_files_h(t_cmd *cmd, char **argv, int argc)
{
	cmd->heredoc_file = heredoc(cmd, argv[2], argv[argc - 1]);
	cmd->infile_fd = open(cmd->heredoc_file, O_RDONLY);
	if (cmd->infile_fd == -1)
		print_error_exit(cmd, "pipex");
	while (cmd->next)
		cmd = cmd->next;
	cmd->outfile_fd = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (cmd->outfile_fd == -1)
	{
		ft_putendl_fd("cannot open outfile", STDERR_FILENO);
		cmd->err = 1;
	}
}

static char	*heredoc(t_cmd *cmd, char *limiter, char *outfile)
{
	char	*str;
	int		heredoc_fd;
	char	*heredoc_file;

	heredoc_file = choose_heredoc_file(outfile);
	heredoc_fd = open(heredoc_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (heredoc_fd == -1)
		print_error_exit(cmd, "pipex");
	ft_putstr_fd("> ", STDOUT_FILENO);
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (check_limiter(str, limiter))
		{
			free(str);
			close(heredoc_fd);
			return (heredoc_file);
		}
		ft_putstr_fd(str, heredoc_fd);
		free(str);
		ft_putstr_fd("> ", STDOUT_FILENO);
		str = get_next_line(STDIN_FILENO);
	}
	return (0);
}

static char	*choose_heredoc_file(char *outfile)
{
	int		i;
	char	*file_name;

	i = 0;
	while (1)
	{
		file_name = ft_itoa(i++);
		if (access(file_name, F_OK) != 0)
			if (ft_strncmp(outfile, file_name, ft_strlen(outfile)) != 0
				|| ft_strncmp(outfile, file_name, ft_strlen(file_name)) != 0)
				return (file_name);
	}
	free(file_name);
}

static int	check_limiter(char *str, char *limiter)
{
	int	i;

	i = 0;
	if (ft_strlen(str) - 1 != ft_strlen(limiter))
		return (0);
	while (str[i] != '\n' && str[i] != 0)
	{
		if (str[i] != limiter[i])
			return (0);
		i++;
	}
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}
