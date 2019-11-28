/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:15:06 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/10 00:06:40 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*chartostr(int c)
{
	char	*str;

	str = (char*)ft_calloc(2, sizeof(char));
	if (c == 0)
		c = 147;
	str[0] = c;
	return (str);
}
