/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:17:04 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 20:33:50 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_leftorright(t_analyst *data)
{
	int		i;

	i = 1;
	if (data->leftspaces < 0)
	{
		data->leftspaces *= -1;
		i = 0;
	}
	return (i);
}

void	ft_createconvd3(va_list args, char **ptr, t_analyst *data, int *c)
{
	if (data->zeroflag == 1 && !data->minusflag && !data->precision)
	{
		*c = va_arg(args, int);
		if (data->leftzeroed == 0)
			*ptr = ft_itoa(*c);
		else if (data->leftzeroed > 0)
		{
			*ptr = ft_addzerod(*c, data->leftzeroed);
			if (*c < 0)
				*ptr = ft_addzerod(*c, data->leftzeroed - 1);
		}
	}
}

void	ft_somecases(const char *str, t_analyst *data, int i, va_list args)
{
	if (str[i] == '0' && str[i - 1] == '%')
	{
		data->zeroflag = 1;
		if (str[i + 1] == '*')
		{
			data->leftzeroed = va_arg(args, int);
			if (data->leftzeroed < 0)
			{
				data->minusflag = 1;
				data->rightspaces = data->leftzeroed;
			}
		}
		else if (ft_isdigit(str[i + 1]))
			data->leftzeroed = ft_atoi(str + i);
	}
}

void	ft_somecases2(const char *str, t_analyst *data, int i, va_list args)
{
	if (str[i] == '.')
	{
		data->precision = 1;
		if (data->leftzeroed > 0)
			data->leftspaces = data->leftzeroed;
		if (str[i + 1] == '*')
			data->leftzeroed = va_arg(args, int);
		else if (ft_isdigit(str[i + 1]))
			data->leftzeroed = ft_atoi(str + i + 1);
	}
}
