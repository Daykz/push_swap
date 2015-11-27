/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 22:23:22 by dmathe            #+#    #+#             */
/*   Updated: 2015/06/26 22:23:26 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_list **list, t_opt *opt)
{
	list_add_next(list, link_init((*list)->data));
	list_remove(list, *list);
	if (opt->c == 1)
		putcolor("ra ", BOLD_GREEN);
	else
		ft_putstr("ra ");
}
