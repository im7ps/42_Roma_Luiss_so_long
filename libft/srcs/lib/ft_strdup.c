/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:54 by sgerace           #+#    #+#             */
/*   Updated: 2022/03/27 17:49:42 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	dim;
	char	*stack;

	dim = ft_strlen(s1) + 1;
	stack = malloc(dim);
	if (s1 == NULL)
		return (NULL);
	else
		ft_memcpy(stack, s1, dim);
	return (stack);
}
