/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:59:40 by jae-kang          #+#    #+#             */
/*   Updated: 2024/02/20 16:00:57 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	char	**paths;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_args;
	char	**cmd2_args;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		p1_error;
	int		p2_error;
}t_pipe;

// utils.c
int		write_error(char *msg, char *per);
void	init_arg(t_pipe *arg);
void	error_exit(char *per);

// parsing.c
void	parsing(t_pipe *arg, char **argv, char **envp);

#endif