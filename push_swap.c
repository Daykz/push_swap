/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:23:27 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 18:22:39 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_opt(t_opt *opt)
{
	opt->v = 0;
	opt->c = 0;
	opt->len = 0;
	opt->min = 0;
	opt->end = 0;
}

int			check_pos_max(t_list *list)
{
	int		value;
	int		i;
	int		j;

	j = 1;
	i = 0;
	value = *(int *)list->data;
	while (list->next)
	{
		j++;
		list = list->next;
		if (*(int *)list->data > value)
		{
			value = *(int *)list->data;
			i = j;
		}
	}
	return ((i == 0) ? 1 : i);
}

int			check_pos_min(t_list *list)
{
	int		value;
	int		i;
	int		j;

	i = 0;
	j = 1;
	value = *(int *)list->data;
	while (list->next)
	{
		j++;
		list = list->next;
		if (*(int *)list->data < value)
		{
			value = *(int *)list->data;
			i = j;
		}
	}
	return ((i == 0) ? 1 : i);
}

int			push_swap(t_list *list, t_listb *listb, char **param)
{
	int		len;
	t_opt	opt;
	int		i;

	i = 1;
	init_opt(&opt);
	while (param[i] && param[i][0] == '-')
	{
		if (!no_char(param[i]))
			return (0);
		if (!ft_strcmp(param[i], "-"))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (ft_isdigits(param[i]) == 1)
			break ;
		check_opt(param[i], &opt);
		i++;
	}
	if (!ft_strcmp(param[1], "-vc") && !param[2])
		return (0);
	len = list_size(list);
	sort(list, listb, &opt);
	return (0);
}

int			main(int ac, char **av)
{
	t_list	*list;
	t_listb	*listb;
	int		i;
	int		*nb;

	i = 1;
	list = NULL;
	listb = NULL;
	if (ac > 1)
	{
		i = main_bis(av);
		while (av[i])
		{
			nb = malloc(sizeof(int));
			(*nb) = ft_atoi(av[i]);
			list_add_next(&list, link_init((void *)nb));
			if (check_param(av, i) == 0)
				return (0);
			i++;
		}
		push_swap(list, listb, av);
	}
	return (0);
}
