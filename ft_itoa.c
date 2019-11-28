/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:45:16 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:31:24 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void	filltheplaces(long int number, long n, char *ptr, long int han)
{
	int		i;

	i = 0;
	if (n < 0)
		ptr[i++] = '-';
	if (n == 0)
		ptr[i++] = 48;
	while (han)
	{
		ptr[i++] = (number / han) + 48;
		number = number - ((number / han) * han);
		han /= 10;
	}
	ptr[i] = '\0';
}

char		*ft_itoa(long n)
{
	long int	i;
	long int	number;
	int			c;
	char		*ptr;

	c = 0;
	i = 1;
	if (n < 0)
		number = -n;
	else
		number = n;
	if (n == -2147483648)
		number = 2147483648;
	while (number / i)
	{
		i *= 10;
		c++;
	}
	if (!(ptr = (char*)malloc(sizeof(char) * (c + 2))))
		return (0);
	filltheplaces(number, n, ptr, i / 10);
	return (ptr);
}
