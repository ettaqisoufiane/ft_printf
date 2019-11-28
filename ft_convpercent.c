/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convpercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:54:51 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 18:47:00 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzeropercent(char *ptr, int totalzeroed)
{
	char	*str;

	ptr = ft_strdup("%");
	if (totalzeroed <= 0)
		return (ptr);
	str = (char*)ft_calloc(totalzeroed + 1, sizeof(char));
	ft_memset(str, '0', totalzeroed);
	str = ft_strjoin(str, ptr);
	return (str);
}

char			*ft_addspacespercent(char *ptr, int totalspaces, int lftorig)
{
	char	*str;
	int		sig;

	sig = 0;
	ptr = ft_strdup("%");
	if (totalspaces < 0)
	{
		sig = -1;
		totalspaces *= sig;
	}
	str = (char*)ft_calloc(totalspaces + 1, sizeof(char));
	ft_memset(str, ' ', totalspaces);
	if (sig == -1)
	{
		if (lftorig == 0)
			lftorig = 1;
		else
			lftorig = 0;
	}
	if (lftorig == 1)
		str = ft_strjoin(str + ft_strlen(ptr), ptr);
	else if (lftorig == 0)
		str = ft_strjoin(ptr, str + ft_strlen(ptr));
	return (str);
}

static void		createptr(char **ptr, t_analyst *data)
{
	if (data->precision == 1)
		*ptr = ft_strdup("%");
	if (data->minusflag == 1)
	{
		if (data->rightspaces < 0)
			data->rightspaces *= -1;
		if (data->precision == 0)
			*ptr = ft_addspacespercent("%", data->rightspaces, 0);
		else if (data->precision != 0)
			*ptr = ft_addspacespercent(*ptr, data->rightspaces, 0);
	}
	if (data->zeroflag == 1 && !data->minusflag && !data->precision)
		*ptr = ft_addzeropercent("%", data->leftzeroed - 1);
	if (data->leftspaces != 0 && !data->zeroflag)
	{
		if (data->precision == 0)
			*ptr = ft_addspacespercent("%", data->leftspaces, 1);
		else if (data->precision != 0)
			*ptr = ft_addspacespercent(*ptr, data->leftspaces, 1);
	}
}

char			*ft_conversionpercent(const char *str, va_list args, char c)
{
	t_analyst	data;
	int			i;
	char		*ptr;

	initialvalues(&data);
	i = 0;
	ptr = ft_strdup("");
	while (str[++i] != c)
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
	}
	createptr(&ptr, &data);
	if (str[i] == c && *ptr == '\0')
		ptr = ft_strdup("%");
	ft_putstr(ptr);
	return (ptr);
}
