/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 19:58:24 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/18 12:43:03 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				r_reverse_a(&list);
			else if (min == 1)
				push_b(&list, &listb);
			else if (min <= ((int)list_size(list)) / 2)
				reverse_a(&list);
			else if (min > ((int)list_size(list)) / 2)
				r_reverse_a(&list);
			print_list(list, opt);
			print_listb(listb, opt);
		}
		while (listb)
			push_a(&list, &listb);
	}
	print_list(list, opt);
	return (0);
}

int		sort(t_list *list, t_listb *listb, t_opt *opt)
{
	int	min;
	int	len;

	len = (int)list_size(list);
	while (check_good(list, listb) == 0)
	{
		min = check_pos_min(list);
		if (min == (int)list_size(list))
			r_reverse_a(&list);
		else if (min == 1)
			push_b(&list, &listb);
		else if (min <= ((int)list_size(list)) / 2 && (min != 2))
			reverse_a(&list);
		else if ((min > ((int)list_size(list)) / 2) && (min != 2))
			r_reverse_a(&list);
		else if (*(int *)list < *((int *)list_second(list)))
			swap_a(&list);
		if ((int)(list_size((t_list *)listb)) >= (len / 2))
		{
			sort_a_b(list, listb, opt);
			return (1);
		}
		ft_putchar('\n');
		print_list(list, opt);
		print_listb(listb, opt);
	}
	return (0);
}
