/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:23:58 by dmontoro          #+#    #+#             */
/*   Updated: 2022/08/21 12:00:49 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*ret;
	t_list	*aux;

	if (!lst || !f)
		return (0);
	ret = NULL;
	while (lst != NULL)
	{
		aux = ft_lstnew(f(&lst->content));
		if (aux == NULL)
		{
			ft_lstclear(&ret);
			return (NULL);
		}
		ft_lstadd_back(&ret, aux);
		lst = lst->next;
	}
	return (ret);
}
