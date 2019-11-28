/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:18 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/09 15:12:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzerod(int number, int totalzeroed)
{
	int		num;
	int		sig;
	char	*str;
	char	*ptr;

	sig = 0;
	num = number;
	ptr = ft_itoa(num);
	if (ft_strlen(ptr) <= (size_t)totalzeroed)
	{
		if (num < 0)
		{
			sig = -1;
			num *= sig;
		}
		ptr = ft_itoa(num);
		str = ft_calloc(totalzeroed + 1, sizeof(char));
		ft_memset(str, '0', totalzeroed);
		str = ft_strjoin(str + ft_strlen(ptr), ptr);
		if (sig == -1)
			str = ft_strjoin("-", str);
		return (str);
	}
	return (ptr);
}

char			*ft_addspacesd(int number, int totalspaces, int lftorig)
{
	int		num;
	char	*str;
	int		sig;

	num = number;
	sig = 0;
	if (totalspaces < 0)
	{
		sig = -1;
		totalspaces *= sig;
	}
	if (ft_strlen(ft_itoa(num)) < (size_t)totalspaces)
	{
		str = ft_calloc(totalspaces + 1, sizeof(char));
		ft_memset(str, ' ', totalspaces);
		if (lftorig == 1)
			str = ft_strjoin(str + ft_strlen(ft_itoa(num)), ft_itoa(num));
		else if (lftorig == 0)
			str = ft_strjoin(ft_itoa(num), str + ft_strlen(ft_itoa(num)));
		return (str);
	}
	return (ft_itoa(num));
}

char			*ft_addspacesdchar(char *ptr, int totalspaces, int lftorig)
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
		if (lftorig == 1)
			str = ft_strjoin(str + ft_strlen(ptr), ptr);
		else if (lftorig == 0)
			str = ft_strjoin(ptr, str + ft_strlen(ptr));
		return (str);
	}
	else
		return (ptr);
	return (0);
}

static void		createptr(va_list args, char **ptr, t_analyst *data)
{
	int		c;

	if (data->precision != 0 || data->minusflag != 0)
		data->zeroflag = 0;
	ft_createconvd2(args, ptr, data, &c);
	if (data->leftspaces != 0 && !data->zeroflag)
	{
		if (data->precision == 0)
			*ptr = ft_addspacesd(va_arg(args, int),
			data->leftspaces, ft_leftorright(data));
		else if (data->precision != 0)
			*ptr = ft_addspacesdchar(*ptr,
			data->leftspaces, ft_leftorright(data));
	}
}

char			*ft_conversiond(const char *str, va_list args, char c)
{
	t_analyst	data;
	int			i;
	char		*ptr;

	initialvalues(&data);
	i = 0;
	ptr = ft_strdup("");
	while (str[i] != c)
	{
		ft_somecases2(str, &data, i, args);
		ft_convd2(str, &data, i, args);
		i++;
	}
	createptr(args, &ptr, &data);
	if (str[i] == c && *ptr == '\0' && !data.precision && !data.minusflag)
		ptr = ft_itoa(va_arg(args, int));
	ft_putstr(ptr);
	return (ptr);
}
