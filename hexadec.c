/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:01:34 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:26:03 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_equelinhex(long long i, int c)
{
	if (i <= 9)
		return (i + 48);
	if (i == 10)
		return ('a' - c);
	if (i == 11)
		return ('b' - c);
	if (i == 12)
		return ('c' - c);
	if (i == 13)
		return ('d' - c);
	if (i == 14)
		return ('e' - c);
	if (i == 15)
		return ('f' - c);
	return (-1);
}

char	*ft_convhexadecimaladd(long long i, int b)
{
	char			*ptr;
	size_t			number;
	int				c;

	number = (size_t)i;
	if (i < 0)
		number = (unsigned int)i;
	c = 0;
	c = ft_hexdec2(number, c);
	number = (size_t)i;
	if (i < 0)
		number = (unsigned int)i;
	ptr = (char*)malloc((c) * sizeof(char));
	c = 0;
	while (number)
	{
		ptr[c++] = get_equelinhex(number % 16, b);
		number = number / 16;
	}
	if (i == 0)
		ptr[c++] = 48;
	ptr[c] = '\0';
	ptr = ft_strrev(ptr);
	return (ptr);
}

char	get_equelinhexu(unsigned long i, int c)
{
	if (i <= 9)
		return (i + 48);
	if (i == 10)
		return ('a' - c);
	if (i == 11)
		return ('b' - c);
	if (i == 12)
		return ('c' - c);
	if (i == 13)
		return ('d' - c);
	if (i == 14)
		return ('e' - c);
	if (i == 15)
		return ('f' - c);
	return (48);
}

char	*ft_convhexadecimaladdu(unsigned long i, int b)
{
	char			*ptr;
	unsigned long	number;
	int				c;

	number = (unsigned long)i;
	c = 0;
	while (number)
	{
		number = number / 16;
		c++;
	}
	number = (unsigned long)i;
	ptr = (char*)ft_calloc((c + 1), sizeof(char));
	c = 0;
	while (number)
	{
		ptr[c++] = get_equelinhexu(number % 16, b);
		number = number / 16;
	}
	if (i == 0)
		ptr[c++] = 48;
	ptr = ft_strrev(ptr);
	return (ptr);
}

int		ft_checkpointandzero(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '0')
			return (1);
		i++;
	}
	return (0);
}
