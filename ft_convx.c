/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:30 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:26:56 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*analydata(char *ptr, va_list args,
					t_analyst data, const char *str)
{
	if (data.leftzeroed != 0)
		ptr = ft_addzerox(ft_convhexadecimaladd(va_arg(args, int), 32),
			data.leftzeroed);
	if (data.leftspaces != 0 && data.leftzeroed == 0)
		ptr = ft_addspacesxchar(ft_convhexadecimaladd(va_arg(args, int), 32),
			data.leftspaces, 1);
	if (data.leftzeroed != 0 && data.leftspaces != 0)
		ptr = ft_addspacesxchar(ptr, data.leftspaces, 1);
	if (data.leftzeroed != 0 && data.rightspaces != 0)
		ptr = ft_addspacesxchar(ptr, data.rightspaces, 0);
	if (data.rightspaces != 0 && data.leftzeroed == 0)
		ptr = ft_addspacesxchar(ft_convhexadecimaladd(va_arg(args, int), 32),
			data.rightspaces, 0);
	if (str[1] == 'd' || (data.rightspaces == 0 &&
		data.leftzeroed == 0 && data.leftspaces == 0))
	{
		ptr = ft_convhexadecimaladd(va_arg(args, int), 32);
		if (*ptr == '0' && str[1] == '.')
			ptr = ft_strdup("");
	}
	ft_putstr(ptr);
	return (ptr);
}

char			*ft_conversionbigx(const char *str, va_list args, char c)
{
	t_analyst	data;
	int			i;
	char		*ptr;

	initialvalues(&data);
	i = 0;
	ptr = NULL;
	while (str[i] != c)
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			data.rightspaces = ft_atoi(str + i + 1);
		if ((str[i] == '.' && ft_isdigit(str[i + 1])) ||
			(str[i] == '0' && ft_isdigit(str[i + 1])))
			data.leftzeroed = ft_atoi(str + i + 1);
		if (str[i] == '%' && ft_isdigit(str[i + 1]))
			data.leftspaces = ft_atoi(str + i + 1);
		ft_forxminx(&data, args, str, i);
		i++;
	}
	return (analydata(ptr, args, data, str));
}
