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
//////
#include <stdio.h>
//////


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
	int last_min;

	if (check_good_b((t_list *)listb) == 1)
	{
		while (check_good_a(list) == 0)
		{
			min = check_pos_min(list);
			last_min = check_pos_last_min(list);
			printf("last_min = %d, min = %d\n", last_min, min);
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
		opt->last_min = check_pos_last_min(list);
		printf("last_min = %d, min = %d\n", opt->last_min, opt->min);
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
		if ((int)(list_size((t_list *)listb)) >= (opt->len / 2))
		{
			sort_a_b(list, listb, opt);
			return (1);
		}
		print(list, opt, listb);
	}
	return (0);
}
