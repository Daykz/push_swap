/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 19:58:24 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 16:56:39 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_easy(t_list *list, t_opt *opt)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 1;
	while (tmp->next)
	{
		if (*(int *)tmp->next->data > *(int *)tmp->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	if (i == 3)
	{
		swap_a(&list, opt);
		print_list(list, opt);
		r_reverse_a(&list, opt);
		print_list(list, opt);
	}
	if (i == 2 && *(int *)list->data > *(int *)list->next->data)
	{
		swap_a(&list, opt);
		print_list(list, opt);
	}
	return (1);
}

int		check_opt(char *bonus, t_opt *opt)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(bonus);
	while (i < len)
	{
		if (bonus[i] == 'v')
			opt->v = 1;
		else if (bonus[i] == 'c')
			opt->c = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

void	putcolor(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(END);
}

int		sort_a_b(t_list *list, t_listb *listb, t_opt *opt)
{
	int	min;

	if (check_good_b((t_list *)listb) == 1)
	{
		while (check_good_a(list) == 0)
		{
			min = check_pos_min(list);
			if (min == (int)list_size(list))
				r_reverse_a(&list, opt);
			else if (min == 1)
				push_b(&list, &listb, opt);
			else if (min <= ((int)list_size(list)) / 2)
				reverse_a(&list, opt);
			else if (min > ((int)list_size(list)) / 2)
				r_reverse_a(&list, opt);
			print(list, opt, listb);
		}
		while (listb)
			push_a(&list, &listb, opt);
	}
	print_list(list, opt);
	return (0);
}

int		sort(t_list *list, t_listb *listb, t_opt *opt)
{
	opt->len = (int)list_size(list);
	while (check_good(list, listb) == 0)
	{
		opt->min = check_pos_min(list);
		if (check_end(list, listb, opt) == 1)
			return (1);
		else if (opt->min == (int)list_size(list))
			r_reverse_a(&list, opt);
		else if (opt->min == 1)
			push_b(&list, &listb, opt);
		else if (opt->min <= ((int)list_size(list)) / 2 && opt->min != 2)
			reverse_a(&list, opt);
		else if (opt->min > ((int)list_size(list)) / 2 && opt->min != 2)
			r_reverse_a(&list, opt);
		else if (*(int *)list < *((int *)list_second(list)))
			swap_a(&list, opt);
		else if (opt->min == 2)
			reverse_a(&list, opt);
		if (sort_bis(list, listb, opt) == 1)
			return (1);
		print(list, opt, listb);
	}
	return (0);
}
