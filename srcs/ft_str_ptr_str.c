/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ptr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:56:10 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/04 13:57:44 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_str_ptr_str(char **str, const char *to_find)
{
	size_t	k;
	size_t	i;
	size_t	j;

	k = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[k])
	{
		i = 0;
		while (str[k][i])
		{
			j = 0;
			while (to_find[j] && str[k][i + j] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return ((char *)str[k] + j + 1);
				j++;
			}
			i++;
		}
		k++;
	}
	return (0);
}
