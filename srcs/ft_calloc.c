/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:51:53 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/03 16:56:47 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	memsize;
	void			*membloc;
	char			*amembloc;
	unsigned int	i;

	i = 0;
	memsize = count * size;
	membloc = (void *)malloc(memsize);
	if (!membloc)
		return (0);
	amembloc = membloc;
	while (i < memsize)
	{
		amembloc[i] = 0;
		i++;
	}
	return (membloc);
}
