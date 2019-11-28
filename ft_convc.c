/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:13 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/10 00:32:52 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_addzeroc(int c, int totalzeroed)
{
	char	*str;
	char	*ptr;

	ptr = chartostr(c);
	if (ft_strlen(ptr) < (size_t)totalzeroed)
	{
		str = ft_calloc(totalzeroed + 1, sizeof(char));
		ft_memset(str, '0', totalzeroed);
		str = ft_strjoin(str + ft_strlen(ptr), ptr);
		return (str);
	}
	return (ptr);
}

char			*ft_addspacesc(int c, int totalspaces, int lftorig)
{
	int		num;
	char	*str;
	int		sig;

	num = c;
	sig = 0;
	if (totalspaces < 0)
	{
		sig = -1;
		totalspaces *= -1;
		lftorig = checksig(sig, lftorig);
	}
	str = ft_calloc(totalspaces + 1, sizeof(char));
	ft_memset(str, ' ', totalspaces);
	if (lftorig == 1)
		str = ft_strjoin(str + ft_strlen(chartostr(num)), chartostr(num));
	else if (lftorig == 0)
		str = ft_strjoin(chartostr(num), str + ft_strlen(chartostr(num)));
	return (str);
}

char			*ft_addspacescchar(char *ptr, int totalspaces, int lftorig)
{
	char	*str;
	int		sig;

	sig = 0;
	if (totalspaces < 0)
	{
		sig = -1;
		totalspaces *= -1;
	}
	str = ft_calloc(totalspaces + 1, sizeof(char));
	ft_memset(str, ' ', totalspaces);
	if (lftorig == 1)
		str = ft_strjoin(str + ft_strlen(ptr), ptr);
	else if (lftorig == 0)
		str = ft_strjoin(ptr, str + ft_strlen(ptr));
	return (str);
}

static void		createptr(va_list args, char **ptr, t_analyst *data)
{
	int		c;

	c = 0;
	if (data->precision != 0 || data->minusflag != 0)
		data->zeroflag = 0;
	createptrforc(args, ptr, data, &c);
	if (data->leftspaces != 0 && !data->zeroflag)
	{
		if (data->precision == 0)
			*ptr = ft_addspacesc(va_arg(args, int),
			data->leftspaces, ft_leftorright(data));
		else if (data->precision != 0)
			*ptr = ft_addspacescchar(*ptr,
			data->leftspaces, ft_leftorright(data));
	}
}

char			*ft_conversionc(const char *str, va_list args, char c)
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
		ptr = chartostr(va_arg(args, int));
	ft_printchar(ptr);
	return (ptr);
}
