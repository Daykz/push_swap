/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 22:23:14 by dmathe            #+#    #+#             */
/*   Updated: 2015/06/26 22:23:16 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_reverse_a(t_list **list)
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
	ft_putstr("rra ");
}
