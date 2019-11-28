/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restofsomefunctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:12:50 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 19:19:24 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_forc(t_analyst *data, va_list args, const char *str, int i)
{
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		data->rightspaces = ft_atoi(str + i + 1);
	if ((str[i] == '0' && ft_isdigit(str[i + 1])))
		data->leftzeroed = ft_atoi(str + i + 1);
	if (str[i] == '%' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
		data->leftspaces = ft_atoi(str + i + 1);
	if (str[i] == '-' && str[i + 1] == '*')
		data->rightspaces = va_arg(args, int);
	if ((str[i] == '0' && str[i + 1] == '*'))
		data->leftzeroed = va_arg(args, int);
	if (str[i] == '%' && str[i + 1] == '*')
		data->leftspaces = va_arg(args, int);
	if (str[i] == '.' && str[i + 1] == '*')
	{
		data->leftzeroed = va_arg(args, int);
		data->leftzeroed = 0;
	}
}

void		ft_forxminx(t_analyst *data, va_list args, const char *str, int i)
{
	if (str[i] == '-' && str[i + 1] == '*')
	{
		data->rightspaces = va_arg(args, int);
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
	}
	if (str[i] == '%' && str[i + 1] == '*')
	{
		data->leftspaces = va_arg(args, int);
		if (data->leftspaces < 0)
		{
			data->rightspaces = data->leftspaces * -1;
			data->leftspaces = 0;
		}
	}
	if (str[i] == '0' && str[i + 1] == '*')
		data->leftspaces = va_arg(args, int);
	if (str[i] == '.' && str[i + 1] == '*')
	{
		data->leftzeroed = va_arg(args, int);
		if (data->leftzeroed < 0)
			data->leftzeroed = 0;
	}
}

void		ft_convd2(const char *str, t_analyst *data, int i, va_list args)
{
	if (str[i] == '-')
	{
		data->minusflag = 1;
		if (str[i + 1] == '*')
			data->rightspaces = va_arg(args, int);
		else if (ft_isdigit(str[i + 1]))
			data->rightspaces = ft_atoi(str + i);
	}
	ft_somecases(str, data, i, args);
	if (str[i - 1] == '%' && (str[i] == '*' || ft_isdigit(str[i])))
	{
		if (str[i] == '*')
			data->leftspaces = va_arg(args, int);
		else if (ft_isdigit(str[i]))
			data->leftspaces = ft_atoi(str + i);
	}
	if (str[i] == ' ' && str[i - 1] == '%')
		ft_putchar(str[i]);
}

void		ft_createconvd2(va_list args, char **ptr, t_analyst *data, int *c)
{
	if (data->precision == 1)
	{
		*c = va_arg(args, int);
		if (*c == 0 && data->leftzeroed == 0)
			*ptr = ft_strdup("");
		else if (data->leftzeroed > 0)
			*ptr = ft_addzerod(*c, data->leftzeroed);
		else
			*ptr = ft_addzerod(*c, 1);
	}
	if (data->minusflag == 1)
	{
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacesd(va_arg(args, int), data->rightspaces, 0);
		else if (data->precision != 0)
			*ptr = ft_addspacesdchar(*ptr, data->rightspaces, 0);
	}
	ft_createconvd3(args, ptr, data, c);
}
