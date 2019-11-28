/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:12:10 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/09 15:07:43 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnumber(long int nb, long int root, int n_p)
{
	int			single;

	if (n_p == 2)
	{
		ft_putchar('-');
	}
	if (root <= 1)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		while (root / 10 != 0)
		{
			single = nb / root;
			ft_putchar(single + 48);
			nb = nb - (single * root);
			if (root / 100 == 0)
				ft_putchar(nb + 48);
			root /= 10;
		}
	}
}

void	ft_putnbr(long nb)
{
	long int	root;
	long int	n_positive;
	int			n_p;

	n_p = 0;
	if (nb < 0)
	{
		n_positive = (long int)nb * -1;
		n_p = 2;
	}
	else
		n_positive = nb;
	root = 1;
	while (n_positive / root != 0)
		root *= 10;
	root /= 10;
	printnumber(n_positive, root, n_p);
}

int		checksig(int sig, int lftorig)
{
	if (sig == -1)
	{
		if (lftorig == 0)
			lftorig = 1;
		else
			lftorig = 0;
	}
	return (lftorig);
}
