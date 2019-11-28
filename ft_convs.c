/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:08 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/09 15:09:10 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzeros(char *ptr, int totalzeroed)
{
	char	*str;

	if (ptr == 0)
		ptr = ft_strdup("(null)");
	if (totalzeroed > (int)ft_strlen(ptr))
	{
		str = ft_calloc(totalzeroed + 1, sizeof(char));
		ft_memset(str, '0', totalzeroed);
		ptr = ft_strjoin(str + ft_strlen(ptr), ptr);
	}
	return (ptr);
}

char			*ft_toshow_convs(char *ptr, int totalzeroed)
{
	if (ptr == 0)
		ptr = ft_strdup("(null)");
	if (totalzeroed >= 0)
		ptr = ft_substr(ptr, 0, totalzeroed);
	return (ptr);
}

char			*ft_addspacesschar(char *ptr, int totalspaces, int lftorig)
{
	char	*str;
	int		sig;

	sig = 0;
	if (ptr == 0)
		ptr = ft_strdup("(null)");
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

static void		createptr(va_list args, char **ptr,
				t_analyst *data, int totalprint)
{
	if (data->precision != 0 || data->minusflag != 0)
		data->zeroflag = 0;
	if (data->precision == 1)
		*ptr = ft_toshow_convs(va_arg(args, char*), totalprint);
	if (data->minusflag == 1)
	{
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacesschar(va_arg(args, char*), data->rightspaces, 0);
		else if (data->precision != 0)
			*ptr = ft_addspacesschar(*ptr, data->rightspaces, 0);
	}
	ft_createptrs(data, ptr, args);
}

char			*ft_conversions(const char *str, va_list args, char c)
{
	t_analyst	data;
	int			i;
	char		*ptr;
	int			totalprint;

	initialvalues(&data);
	i = 0;
	ptr = ft_strdup("");
	while (str[i] != c)
	{
		if (str[i] == '.')
		{
			data.precision = 1;
			if (str[i + 1] == '*')
				totalprint = va_arg(args, int);
			else
				totalprint = ft_atoi(str + i + 1);
		}
		ft_convd2(str, &data, i, args);
		i++;
	}
	createptr(args, &ptr, &data, totalprint);
	ptr = ft_convs2(args, &data, &ptr);
	return (ptr);
}
