/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convxmin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:17:06 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/09 15:08:41 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzerox(char *ptr, int totalzeroed)
{
	char		*num;
	char		*str;

	num = ptr;
	if (totalzeroed > (int)ft_strlen(num))
	{
		str = ft_calloc(totalzeroed + 1, sizeof(char));
		ft_memset(str, '0', totalzeroed);
		str = ft_strjoin(str + ft_strlen(num), num);
		return (str);
	}
	return (ptr);
}

char			*ft_addspacesxchar(char *ptr, int totalspaces, int lftorig)
{
	char	*str;
	int		sig;

	sig = 0;
	if (totalspaces < 0)
	{
		sig = -1;
		totalspaces *= sig;
	}
	if (totalspaces > (int)ft_strlen(ptr))
	{
		str = ft_calloc(totalspaces + 1, sizeof(char));
		ft_memset(str, ' ', totalspaces);
		lftorig = checksig(sig, lftorig);
		if (lftorig == 1)
			str = ft_strjoin(str + ft_strlen(ptr), ptr);
		else if (lftorig == 0)
			str = ft_strjoin(ptr, str + ft_strlen(ptr));
		return (str);
	}
	return (ptr);
}

static char		*analydata(char *ptr, va_list args,
					t_analyst data, const char *str)
{
	if (data.leftzeroed != 0)
		ptr = ft_addzerox(ft_convhexadecimaladd(va_arg(args, int), 0),
			data.leftzeroed);
	if (data.leftspaces != 0 && data.leftzeroed == 0)
		ptr = ft_addspacesxchar(ft_convhexadecimaladd(va_arg(args, int), 0),
			data.leftspaces, 1);
	if (data.leftzeroed != 0 && data.leftspaces != 0)
		ptr = ft_addspacesxchar(ptr, data.leftspaces, 1);
	if (data.leftzeroed != 0 && data.rightspaces != 0)
		ptr = ft_addspacesxchar(ptr, data.rightspaces, 0);
	if (data.rightspaces != 0 && data.leftzeroed == 0)
		ptr = ft_addspacesxchar(ft_convhexadecimaladd(va_arg(args, int), 0),
		data.rightspaces, 0);
	if (str[1] == 'd' || (data.rightspaces == 0 &&
		data.leftzeroed == 0 && data.leftspaces == 0))
	{
		ptr = ft_convhexadecimaladd(va_arg(args, int), 0);
		if (*ptr == '0' && str[1] == '.')
			ptr = ft_strdup("");
	}
	ft_putstr(ptr);
	return (ptr);
}

char			*ft_conversionx(const char *str, va_list args,
				char c)
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
