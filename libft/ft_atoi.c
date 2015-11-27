/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:42:43 by dmathe            #+#    #+#             */
/*   Updated: 2015/11/27 18:43:21 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_min(char *str)
{
	char	*str_min;

	str_min = ft_itoa(INT_MIN);
	if (ft_strlen(str) == ft_strlen(str_min))
	{
		if (ft_strcmp(str, str_min) > 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}			
	}
	else if (ft_strlen(str) > ft_strlen(str_min))
		{
			write(2, "Error\n", 6);
			exit(0);	
		}
	return (0);
}

int 	check_str(char *str)
{
	char	*str_max;
	int 	i;

	i = 0;
	str_max = ft_itoa(INT_MAX);
	if (str[i] == '-')
		check_min(str);
	else if (ft_strlen(str) == ft_strlen(str_max))
	{
		if (ft_strcmp(str, str_max) > 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}			
	}
	else if (ft_strlen(str) > ft_strlen(str_max))
		{
			write(2, "Error\n", 6);
			exit(0);	
		}
	return (1);
}

int		ft_atoi(char *str)
{
	unsigned int	digit;
	int				positive;
	int				value;

	value = 0;
	digit = 0;
	check_str(str);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	positive = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 19)
		return (positive == 1 ? -1 : 0);
	while (ft_isdigit(*str) && *str != '\0')
	{
		digit = (int)(*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	return (value * positive);
}
