/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:23:55 by dmontoro          #+#    #+#             */
/*   Updated: 2023/07/12 09:02:53 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*ret;

	ret = (t_list *) malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = *(int *)content;
	ret->next = NULL;
	ret->prior = NULL;
	return (ret);
}
