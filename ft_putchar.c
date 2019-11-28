/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:15:59 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/10 00:33:09 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ptrcreateu2(t_analyst *data, char **ptr, va_list args)
{
	if (data->minusflag == 1)
	{
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacesu(va_arg(args, int), data->rightspaces, 0);
		else if (data->precision != 0)
			*ptr = ft_addspacesuchar(*ptr, data->rightspaces, 0);
	}
	if (data->zeroflag == 1 && !data->minusflag && !data->precision)
		*ptr = ft_addzerou(va_arg(args, int), data->leftzeroed);
	if (data->leftspaces != 0 && !data->zeroflag)
	{
		if (data->precision == 0)
			*ptr = ft_addspacesu(va_arg(args, int),
			data->leftspaces, ft_leftorright(data));
		else if (data->precision != 0)
			*ptr = ft_addspacesdchar(*ptr,
			data->leftspaces, ft_leftorright(data));
	}
}

void	createptrforc(va_list args, char **ptr, t_analyst *data, int *c)
{
	if (data->minusflag == 1)
	{
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacesc(va_arg(args, int), data->rightspaces, 0);
		else if (data->precision != 0)
			*ptr = ft_addspacescchar(*ptr, data->rightspaces, 0);
	}
	if (data->zeroflag == 1 && !data->minusflag && !data->precision)
	{
		*c = va_arg(args, int);
		if (data->leftzeroed == 0)
			*ptr = chartostr(*c);
		else if (data->leftzeroed > 0)
		{
			*ptr = ft_addzeroc(*c, data->leftzeroed);
			if (*c < 0)
				*ptr = ft_addzeroc(*c, data->leftzeroed - 1);
		}
	}
}

void	ft_printchar(const char *str)
{
	int		c;

	c = -1;
	while (*str != '\0')
	{
		c = *str;
		if (c == -109)
			ft_putchar(0);
		else
			ft_putchar(*str);
		str++;
	}
}
