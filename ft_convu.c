/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:35 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/09 15:09:28 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzerou(int number, int totalzeroed)
{
	int		num;
	int		sig;
	char	*str;

	sig = 0;
	num = number;
	if (totalzeroed > (int)ft_strlen(ft_putnbr_unsigned(num)))
	{
		str = ft_calloc(totalzeroed + 1, sizeof(char));
		ft_memset(str, '0', totalzeroed);
		str = ft_strjoin(str + ft_strlen(ft_putnbr_unsigned(num)),
		ft_putnbr_unsigned(num));
		return (str);
	}
	return (ft_putnbr_unsigned(num));
}

char			*ft_addspacesu(int number, int totalspaces, int lftorig)
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
	if (totalspaces > (int)ft_strlen(ft_putnbr_unsigned(num)))
	{
		str = ft_calloc(totalspaces + 1, sizeof(char));
		ft_memset(str, ' ', totalspaces);
		lftorig = checksig(sig, lftorig);
		if (lftorig == 1)
			str = ft_strjoin(str + ft_strlen(ft_putnbr_unsigned(num)),
			ft_putnbr_unsigned(num));
		else if (lftorig == 0)
			str = ft_strjoin(ft_putnbr_unsigned(num), str +
			ft_strlen(ft_putnbr_unsigned(num)));
		return (str);
	}
	return (ft_putnbr_unsigned(num));
}

char			*ft_addspacesuchar(char *ptr, int totalspaces, int lftorig)
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

static void		createptr(va_list args, char **ptr, t_analyst *data)
{
	int		c;

	c = 0;
	if (data->precision != 0 || data->minusflag != 0)
		data->zeroflag = 0;
	if (data->precision == 1)
	{
		c = va_arg(args, int);
		if (c == 0 && data->leftzeroed == 0)
			*ptr = ft_strdup("");
		else if (data->leftzeroed > 0)
			*ptr = ft_addzerou(c, data->leftzeroed);
		else
			*ptr = ft_addzerou(c, 1);
	}
	ptrcreateu2(data, ptr, args);
}

char			*ft_conversionu(const char *str, va_list args, char c)
{
	t_analyst	data;
	int			i;
	char		*ptr;

	initialvalues(&data);
	i = 0;
	ptr = ft_strdup("");
	while (str[i] != c)
	{
		if (str[i] == '.')
		{
			data.precision = 1;
			if (str[i + 1] == '*')
				data.leftzeroed = va_arg(args, int);
			else if (ft_isdigit(str[i + 1]))
				data.leftzeroed = ft_atoi(str + i + 1);
		}
		ft_convd2(str, &data, i, args);
		i++;
	}
	createptr(args, &ptr, &data);
	if (str[i] == c && *ptr == '\0')
		ptr = ft_putnbr_unsigned(va_arg(args, int));
	ft_putstr(ptr);
	return (ptr);
}
