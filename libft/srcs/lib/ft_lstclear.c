/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:41:37 by sgerace           #+#    #+#             */
/*   Updated: 2022/04/03 17:44:53 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	if (*lst == NULL)
		return ;
	else
	{
		while (*lst != NULL)
		{
			prev = *lst;
			*lst = (*lst)->next;
			del(prev->content);
			free(prev);
		}
	}
}
