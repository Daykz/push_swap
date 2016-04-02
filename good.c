/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 19:45:44 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 16:52:11 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_end(t_list *list, t_listb *listb, t_opt *opt)
{
	t_list *tmp;

	tmp = list;
	if (opt->len <= 3)
	{
		if (check_easy(list, opt) == 1)
			return (1);
	}
	if (listb != NULL)
		return (0);
	while (tmp->next->next)
	{
		if (*(int *)tmp->next->data < *(int *)tmp->data)
			return (0);
		tmp = tmp->next;
	}
	if (*(int *)tmp->next->data < *(int *)tmp->data &&
		*(int *)tmp->next->data > *(int *)tmp->prev->data)
		end(list, listb, opt);
	else
		return (0);
	return (1);
}

int		check_param(char **param, int len)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (len != ++i)
	{
		while (param[len][j] != '\0')
		{
			if ((param[len][j] <= 57 && param[len][j] >= 48) || \
					(param[len][j] == '-' && j == 0))
				j++;
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		if (!same_char(param[len], param[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

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

int		check_good(t_list *list, t_listb *listb)
{
	if (listb != NULL)
		return (0);
	while (list->next)
	{
		if (*(int *)list->next->data < *(int *)list->data)
		{
			return (0);
		}
		list = list->next;
	}
	return (1);
}
