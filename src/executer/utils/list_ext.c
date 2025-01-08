/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:28:49 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/31 17:59:38 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

void	*ft_lstpurge(t_list **lst, void (*del)(void*), size_t index)
{
	void	*content;

	if (!lst || !*lst || !del)
		return (NULL);
	content = NULL;
	if ((*lst)->next)
		content = ft_lstpurge(&((*lst)->next), del, index - 1);
	if (index == 0)
	{
		content = (*lst)->content;
		free(*lst);
	}
	else
		ft_lstdelone(*lst, del);
	return (content);
}
