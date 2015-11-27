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

void	r_reverse_a(t_list **list, t_opt *opt)
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
	if (opt->c == 1)
		putcolor("rra ", BOLD_GREEN);
	else
		ft_putstr("rra ");
}
