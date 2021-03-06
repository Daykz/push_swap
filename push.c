/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 22:45:40 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 16:37:17 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 		no_char(char *str)
{
	int 	i;

	i = 1;
	if (!ft_strcmp(str, "-vc"))
		return (1);
	if (!ft_strcmp(str, "-v") || !ft_strcmp(str, "-c"))
		return (1);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void		end(t_list *list, t_listb *listb, t_opt *opt)
{
	r_reverse_a(&list, opt);
	print(list, opt, listb);
	r_reverse_a(&list, opt);
	print(list, opt, listb);
	swap_a(&list, opt);
	print(list, opt, listb);
	reverse_a(&list, opt);
	print(list, opt, listb);
	opt->end = 1;
	reverse_a(&list, opt);
	opt->end = 0;
	print(list, opt, listb);
}

void		r_r_a(t_list **list)
{
	t_list	*tmp;
	t_list	*link;

	tmp = *list;
	link = list_end(*list);
	while (tmp)
	{
		list_swap_data(tmp, link);
		tmp = tmp->next;
	}
}

void		push_a(t_list **list, t_listb **listb, t_opt *opt)
{
	list_add_next(list, link_init(list_end((t_list *)*listb)->data));
	r_r_a(list);
	list_remove((t_list **)listb, list_end((t_list *)*listb));
	if (opt->c == 1)
		putcolor("pa", BOLD_GREEN);
	else
		ft_putstr("pa");
	if (*listb)
		ft_putchar(' ');
}

void		push_b(t_list **list, t_listb **listb, t_opt *opt)
{
	list_add_next((t_list **)listb, link_init((*list)->data));
	list_remove(list, *list);
	if (opt->c == 1)
		putcolor("pb ", BOLD_GREEN);
	else
		ft_putstr("pb ");
}
