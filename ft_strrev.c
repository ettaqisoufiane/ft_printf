/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:04 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:32:28 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		b;
	int		k;
	char	o;

	i = 0;
	b = 0;
	while (str[i] != '\0')
		i++;
	k = i;
	while (b <= (k - 2) / 2)
	{
		o = str[b];
		str[b] = str[i - 1];
		str[i - 1] = o;
		b++;
		i--;
	}
	str[k] = '\0';
	return (str);
}
