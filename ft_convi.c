/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:14:44 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:26:32 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*ft_conversioni(const char *str, va_list args, char c)
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
	if (str[i] == c && *ptr == '\0' && !data.precision && !data.minusflag)
		ptr = ft_itoa(va_arg(args, int));
	ft_putstr(ptr);
	return (ptr);
}
