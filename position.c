/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 20:05:15 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 16:22:55 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		nbr_low(t_list *list, int nbr, int nbr_prev)
{
	int	n;

	n = *(int *)list->data;
	while (list)
	{
		if (n < nbr && n > nbr_prev)
			return (0);
		list = list->next;
	}
	return (1);
}

int		nbr_high(t_list *list, int nbr, int nbr_next)
{
	int	n;

	n = *(int *)list->data;
	while (list)
	{
		if (n > nbr && n < nbr_next)
			return (0);
		list = list->next;
	}
	return (1);
}
