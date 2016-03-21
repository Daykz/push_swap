/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:23:48 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 16:21:07 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "color.h"

typedef struct		s_listb
{
	void			*data;
	struct s_listb	*next;
	struct s_listb	*prev;
}					t_listb;

typedef struct		s_opt
{
	int				v;
	int				c;
	int				min;
	int				len;
}					t_opt;

int					check_end(t_list *list, t_listb *listb, t_opt *opt);
void				print(t_list *list, t_opt *opt, t_listb *listb);
void				print_list(t_list *list, t_opt *opt);
void				print_listb(t_listb *list, t_opt *opt);
int					check_opt(char *bonus, t_opt *opt);
void				init_opt(t_opt	*opt);
void				putcolor(char *str, char *color);
int					sort_a_b(t_list *list, t_listb *listb, t_opt *opt);
int					check_good_b(t_list *list);
int					check_good_a(t_list *list);
int					push_swap(t_list *list, t_listb *listb, char **param);
int					check_good(t_list *list, t_listb *listb);
int					check_pos_max(t_list *list);
int					check_pos_min(t_list *list);
int					sort(t_list *list, t_listb *listb, t_opt *opt);
int					nbr_low(t_list *list, int nbr, int nbr_prev);
int					nbr_high(t_list *list, int nbr, int nbr_next);
void				swap_a(t_list **list, t_opt *opt);
void				r_r_a(t_list **list);
void				swap_b(t_listb **listb, t_opt *opt);
void				reverse_a(t_list **list, t_opt *opt);
void				reverse_b(t_listb **listb, t_opt *opt);
void				r_reverse_a(t_list **list, t_opt *opt);
void				r_reverse_b(t_listb **listb, t_opt *opt);
void				push_a(t_list **list, t_listb **listb, t_opt *opt);
void				push_b(t_list **list, t_listb **listb, t_opt *opt);
int					check_param(char **param, int len);
void				end(t_list *list, t_listb *listb, t_opt *opt);
int					check_easy(t_list *list, t_opt *opt);

#endif
