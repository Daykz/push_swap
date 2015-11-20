/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 22:45:40 by dmathe            #+#    #+#             */
/*   Updated: 2015/06/22 22:45:42 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_r_a(t_list **list)
{
	t_list	*tmp;
	t_list	*link;

	tmp = *list;
	link = list_end(*list);
	while (tmp)
	{
		list_swap_data(tmp, link);
		tmp = tmp->next;
	}
}

void		push_a(t_list **list, t_listb **listb)
{
	list_add_next(list, link_init(list_end((t_list *)*listb)->data));
	r_r_a(list);
	list_remove((t_list **)listb, list_end((t_list *)*listb));
	ft_putstr("pa ");
}

void		push_b(t_list **list, t_listb **listb)
{
	list_add_next((t_list **)listb, link_init((*list)->data));
	list_remove(list, *list);
	ft_putstr("pb ");
}