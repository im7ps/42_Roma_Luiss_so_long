/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:42:02 by sgerace           #+#    #+#             */
/*   Updated: 2022/04/03 14:49:17 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = (t_list *) malloc (sizeof(t_list));
	if (nodo == NULL)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}
