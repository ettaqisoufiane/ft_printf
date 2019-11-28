/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:19:04 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:31:40 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_unsigned(int i)
{
	char	*number;

	number = 0;
	if (i < 0)
		number = ft_itoa(4294967295 + i + 1);
	else
		number = ft_itoa(i);
	return (number);
}
