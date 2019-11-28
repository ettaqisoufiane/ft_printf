/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restofsomefunctions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:16:04 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:27:55 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convp3(const char *str, va_list args, int i, t_analyst *data)
{
	if (str[i] == '-')
	{
		data->minusflag = 1;
		if (str[i + 1] == '*')
			data->rightspaces = va_arg(args, int);
		else if (ft_isdigit(str[i + 1]))
			data->rightspaces = ft_atoi(str + i);
	}
	if (str[i] == '0' && str[i - 1] == '%' &&
			data->precision == 0 && data->precision == 0)
	{
		data->zeroflag = 1;
		if (str[i + 1] == '*')
			data->leftzeroed = va_arg(args, int);
		else if (ft_isdigit(str[i + 1]))
			data->leftzeroed = ft_atoi(str + i);
	}
}

int		ft_convp2(const char *str, va_list args, char c, t_analyst *data)
{
	int		i;

	i = 0;
	while (str[i] != c)
	{
		ft_convp3(str, args, i, data);
		if (str[i - 1] == '%' && (str[i] == '*' || ft_isdigit(str[i])))
		{
			if (str[i] == '*')
				data->leftspaces = va_arg(args, int);
			else if (ft_isdigit(str[i]))
				data->leftspaces = ft_atoi(str + i);
		}
		if (str[i] == ' ' && str[i - 1] == '%')
			ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_hexdec2(int number, int c)
{
	while (number)
	{
		number = number / 16;
		c++;
	}
	return (c);
}

char	*ft_convs2(va_list args, t_analyst *data, char **ptr)
{
	if (data->zeroflag == 0 && data->minusflag == 0
		&& data->precision == 0 && data->leftspaces == 0)
	{
		*ptr = va_arg(args, char*);
		if (*ptr == NULL)
			*ptr = ft_strdup("(null)");
	}
	ft_putstr(*ptr);
	return (*ptr);
}

void	ft_createptrs(t_analyst *data, char **ptr, va_list args)
{
	int		i;

	i = 0;
	if (data->zeroflag == 1 && !data->minusflag)
	{
		if (data->precision == 0)
			*ptr = ft_addzeros(va_arg(args, char*), data->leftzeroed);
		else if (data->precision != 0)
			*ptr = ft_addzeros(*ptr, data->leftzeroed);
	}
	if (data->leftspaces != 0 && !data->zeroflag)
	{
		i = ft_leftorright(data);
		if (data->precision == 0)
			*ptr = ft_addspacesschar(va_arg(args, char*), data->leftspaces,
			i);
		else if (data->precision != 0)
			*ptr = ft_addspacesschar(*ptr, data->leftspaces,
			i);
	}
}
