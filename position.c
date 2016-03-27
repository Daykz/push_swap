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

int		main_bis(char **param)
{
	int	i;

	i = 1;
	while (param[i] && param[i][0] == '-')
	{
		if (ft_isdigits(param[i]) == 1)
			break ;
		i++;
	}
	return (i);
}

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

int		sort_bis(t_list *list, t_listb *listb, t_opt *opt)
{
	if ((int)(list_size((t_list *)listb)) >= (opt->len / 2))
	{
		sort_a_b(list, listb, opt);
		return (1);
	}
	return (0);
}

int		ft_isdigits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
