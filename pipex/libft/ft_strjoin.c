/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:19:35 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/13 13:28:38 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*result;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(len1 + len2 + 1);
	if (result == 0)
		return (0);
	i = ft_strlcpy(result, (const char *)s1, len1 + 1);
	i = ft_strlcat(result, (const char *)s2, len1 + len2 + 1);
	return (result);
}
