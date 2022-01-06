/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:50:37 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/04 13:59:44 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
	newstr = NULL;
	if (s1 && s2)
	{
		newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
				* sizeof(char));
		if (!newstr)
			return (NULL);
		while (s1 != NULL && s1[++j] != '\0')
			newstr[++i] = s1[j];
		j = -1;
		while (s2 != NULL && s2[++j] != '\0')
			newstr[++i] = s2[j];
		newstr[++i] = '\0';
		return (newstr);
	}
	return (NULL);
}
