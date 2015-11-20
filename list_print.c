/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 23:08:53 by dmathe            #+#    #+#             */
/*   Updated: 2015/07/29 03:00:56 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				putcolor("}", RED);
			else
				ft_putchar('}');
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
				putcolor("}", BLUE);
			else
				ft_putchar('}');
			ft_putchar('\n');
		}
	}
}