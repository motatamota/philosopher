/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:36:31 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 07:36:31 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*next;

	if (!del || !lst)
		return ;
	now = *lst;
	while (now)
	{
		next = now->next;
		ft_lstdelone(now, del);
		now = next;
	}
	*lst = 0;
}
