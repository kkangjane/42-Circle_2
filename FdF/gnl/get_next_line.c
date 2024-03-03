/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:39:26 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/27 15:51:32 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*get_next_line(int fd)
{
	static t_backup		*bu;
	char				*line;
	char				*temp;
	ssize_t				n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = (char *) malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_alll(&bu, &temp, 0, 1));
	n = read(fd, temp, BUFFER_SIZE);
	while (n >= 0)
	{
		if (!reset_backup(&bu))
			break ;
		if ((!n && !(bu->save)) || !(save(&bu, n, &temp)))
			break ;
		if (ft_func(0, bu->buf) || (!(ft_func(0, bu->buf)) && n < BUFFER_SIZE))
		{
			line = extract(&bu, n, &temp);
			return (line);
		}
		n = read(fd, temp, BUFFER_SIZE);
	}
	return (free_alll(&bu, &temp, 0, 0));
}

char	*save(t_backup **backup, ssize_t n, char **temp)
{
	char	*new;
	ssize_t	i;

	if (n == 0)
		return ("1");
	(*temp)[n] = '\0';
	(*backup)->save += n;
	new = 0;
	if ((*backup)->save > (*backup)->total)
	{
		new = (char *) malloc(((*backup)->total) * 2 + 1);
		if (new == 0)
			return (0);
		i = -1;
		while (((*backup)->buf)[++i])
			new[i] = ((*backup)->buf)[i];
		new[i] = '\0';
		free((*backup)->buf);
		(*backup)->buf = new;
		(*backup)->total *= 2;
	}
	ft_func((*backup)->buf, *temp);
	return ("1");
}

char	*extract(t_backup **backup, ssize_t n, char **temp)
{
	char	*line;
	ssize_t	i;

	i = 0;
	while (((*backup)->buf)[i] != '\0' && ((*backup)->buf)[i] != '\n')
		i++;
	if (((*backup)->buf)[i] == '\n')
		i++;
	line = (char *) malloc(i + 1);
	if (line == 0)
		return (free_alll(backup, temp, 0, 1));
	line = ft_strcpy(line, (*backup)->buf, 1);
	if (update_backup(backup) == 0)
	{
		free(line);
		return (free_alll(backup, temp, 0, 1));
	}
	if (!(ft_func(0, line)) || (n < BUFFER_SIZE && !(((*backup)->save))))
		return (free_alll(backup, temp, line, 0));
	free(*temp);
	return (line);
}
