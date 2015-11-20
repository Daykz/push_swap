/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 22:42:55 by dmathe            #+#    #+#             */
/*   Updated: 2015/06/22 22:42:57 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_b(t_listb **listb)
{
	t_listb *tmp;

	tmp = *listb;
	list_swap_data((t_list *)*listb, list_second((t_list *)*listb));
	ft_putstr("sb ");
}

void		swap_a(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	list_swap_data(*list, list_second(*list));
	ft_putstr("sa ");
}