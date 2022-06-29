/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:48:40 by sgerace           #+#    #+#             */
/*   Updated: 2022/03/27 12:44:56 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	int		len;

	ch = c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (*(str + len) == ch)
		{
			return ((char *)(str + len));
		}
		len--;
	}
	return (NULL);
}
