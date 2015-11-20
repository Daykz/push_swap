/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 19:45:44 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/18 12:35:28 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_good_b(t_list *list)
{
	while (list->next)
	{
		if (*((int *)list->next->data) < *((int *)list->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int		check_good_a(t_list *list)
{
	while (list->next)
	{
		if (*(int *)list->next->data < *(int *)list->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int 	check_good(t_list *list, t_listb *listb)
{
	if (listb != NULL)
		return (0);
	while (list->next)
	{
		if (*(int *)list->next->data < *(int *)list->data)
			return (0);
		list = list->next;
	}
	return (1);
}
