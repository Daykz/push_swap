/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 23:08:53 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 16:53:15 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_list *list, t_opt *opt, t_listb *listb)
{
	print_list(list, opt);
	print_listb(listb, opt);
}

void	print_list(t_list *list, t_opt *opt)
{
	if (list)
	{
		if (opt->v == 1)
		{
			ft_putchar('\n');
			if (opt->c == 1)
				putcolor("Pile A = {", RED);
			else
				ft_putstr("Pile A = {");
			while (list)
			{
				ft_putnbr(*((int *)list->data));
				ft_putchar(' ');
				list = list->next;
			}
			if (opt->c == 1)
				putcolor("}\n", RED);
			else
				ft_putstr("}\n");
		}
	}
}

void	print_listb(t_listb *list, t_opt *opt)
{
	if (list)
	{
		if (opt->v == 1)
		{
			ft_putchar('\n');
			if (opt->c == 1)
				putcolor("Pile B = {", BLUE);
			else
				ft_putstr("Pile B = {");
			while (list)
			{
				ft_putnbr(*((int *)list->data));
				ft_putchar(' ');
				list = list->next;
			}
			if (opt->c == 1)
				putcolor("}\n", BLUE);
			else
				ft_putstr("}\n");
		}
	}
}
