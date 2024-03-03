/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:28:57 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/21 12:15:28 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_cmd
{
	int				idx;
	int				infile_fd;
	int				outfile_fd;
	int				here_doc;
	char			*heredoc_file;
	char			*heredoc;
	char			*cmd;
	char			**cmd_args;
	int				pid;
	int				err;
	struct s_cmd	*next;
}				t_cmd;

// control_fd.c
void	open_files(t_cmd *cmd, char **argv, int argc);
void	open_files_h(t_cmd *cmd, char **argv, int argc);

// parsing.c
void	init(t_cmd *cmd, int argc, char **argv, char **envp);
void	init_arg(t_cmd *start, t_cmd *cmd, int cmd_cnt);
void	find_cmds(t_cmd *cmd, char **envp);
void	check_arg(t_cmd	*cmd, char **argv, int argc);

// utils.c
void	perror_exit(t_cmd *cmd, char *msg);
void	ft_exit(t_cmd *cmd);
void	print_error_exit(t_cmd *cmd, char *msg);
void	wait_all(t_cmd *cmd);

#endif