/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:34:36 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/27 15:56:27 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 42

typedef struct s_backup
{
	ssize_t	total;
	ssize_t	save;
	char	*buf;
}t_backup;

// get_next_line
char		*get_next_line(int fd);
char		*save(t_backup **backup, ssize_t count, char **temp);
char		*extract(t_backup **backup, ssize_t n, char **temp);

// get_next_line_utils
char		*free_alll(t_backup **b, char **str, char *line, int ex);
t_backup	*update_backup(t_backup **backup);
t_backup	*reset_backup(t_backup **backup);
int			ft_func(char *dest, char *src);
char		*ft_strcpy(char *dest, char *src, int which_backup);

#endif