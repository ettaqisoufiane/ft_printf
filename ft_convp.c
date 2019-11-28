/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:24 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/09 15:57:41 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzerop(char *ptr, int totalzeroed)
{
	char		*num;
	char		*str;

	num = ptr;
	if (*(ptr + 1) != 'x')
	{
		if (*ptr == '0')
			ptr = ft_strdup("0x0");
		else
			ptr = ft_strjoin("0x", ptr);
	}
	if (totalzeroed > (int)ft_strlen(ptr))
	{
		str = ft_calloc(totalzeroed + 1, sizeof(char));
		ft_memset(str, '0', totalzeroed);
		str = ft_strjoin(str + ft_strlen(num), num);
		str = ft_strjoin("0x", str);
		return (str);
	}
	return (ptr);
}

char			*ft_addspacespchar(char *ptr, int totalspaces, int lftorig)
{
	char	*str;

	if (*(ptr + 1) != 'x')
	{
		if (*ptr == '0')
			ptr = ft_strdup("0x0");
		else
			ptr = ft_strjoin("0x", ptr);
	}
	if (totalspaces > (int)ft_strlen(ptr))
	{
		str = ft_calloc(totalspaces + 1, sizeof(char));
		ft_memset(str, ' ', totalspaces);
		if (lftorig == 1)
			str = ft_strjoin(str + ft_strlen(ptr), ptr);
		else if (lftorig == 0)
			str = ft_strjoin(ptr, str + ft_strlen(ptr));
		return (str);
	}
	return (ptr);
}

static void		createptr(va_list args, char **ptr, t_analyst *data)
{
	if (data->precision != 0 || data->minusflag != 0)
		data->zeroflag = 0;
	if (data->minusflag == 1)
	{
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacespchar(ft_convhexadecimaladd(
				va_arg(args, long long), 0), data->rightspaces, 0);
		else if (data->precision != 0)
			*ptr = ft_addspacespchar(*ptr, data->rightspaces, 0);
	}
	if (data->zeroflag == 1 && !data->minusflag && !data->precision)
		*ptr = ft_addzerop(ft_convhexadecimaladd(
			va_arg(args, long long), 0), data->leftzeroed - 2);
	if (data->leftspaces != 0 && !data->zeroflag)
	{
		if (data->leftspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacespchar(ft_convhexadecimaladd(
				va_arg(args, long long), 0), data->leftspaces, 1);
		else if (data->precision != 0)
			*ptr = ft_addspacespchar(*ptr, data->leftspaces, 1);
	}
}

char			*ft_createnewstring(char *ptr, int total)
{
	char	*str;

	str = (char*)ft_calloc(ft_strlen(ptr) + total + 1, sizeof(char));
	ft_memset(str, '0', ft_strlen(ptr) + total);
	return (str);
}

char			*ft_conversionp(const char *str, va_list args, char c)
{
	char			*ptr;
	t_analyst		data;
	int				i;
	unsigned long	v;

	initialvalues(&data);
	i = 0;
	v = 0;
	ptr = ft_strdup("");
	i = ft_convp2(str, args, c, &data);
	createptr(args, &ptr, &data);
	if (str[i] == c && *ptr == '\0')
	{
		v = va_arg(args, unsigned long);
		ptr = ft_convhexadecimaladdu(v, 0);
		if ((*ptr != '0' && *(ptr + 1) != 'x') || v == 0)
		{
			ft_putstr("0x");
			v = 5;
		}
	}
	ft_putstr(ptr);
	if (v == 5)
		return (ft_createnewstring(ptr, 2));
	return (ptr);
}
