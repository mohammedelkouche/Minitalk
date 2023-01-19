/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/19 21:44:11 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnb(int nb)
{
	if (nb > 9)
	{
		ft_putnb(nb / 10);
		ft_putnb(nb % 10);
	}
	else if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putxchar('-');
			ft_putxchar ('2');
			ft_putnb(147483648);
		}
		else
		{
			ft_putxchar ('-');
			nb = -nb ;
			ft_putnb(nb);
		}
	}
	else
		ft_putxchar(nb + '0');
}

void	ft_putxchar(char c)
{
	write(1, &c, 1);
}
