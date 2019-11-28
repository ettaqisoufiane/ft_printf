/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:03:51 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:27:09 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*controle_theoutput(const char *str, char c, va_list args)
{
	char	*total;

	if (c == 's')
		total = ft_conversions(str, args, c);
	if (c == 'c')
		total = ft_conversionc(str, args, c);
	if (c == 'd')
		total = ft_conversiond(str, args, c);
	if (c == 'p')
		total = ft_conversionp(str, args, c);
	if (c == 'x')
		total = ft_conversionx(str, args, c);
	if (c == 'u')
		total = ft_conversionu(str, args, c);
	if (c == 'i')
		total = ft_conversioni(str, args, c);
	if (c == 'X')
		total = ft_conversionbigx(str, args, c);
	if (c == '%')
		total = ft_conversionpercent(str, args, c);
	return (total);
}

int		ft_prntother(const char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%')
		ft_putchar(str[i++ + 1]);
	else
		ft_putchar(str[i]);
	return (i);
}

void	restoflist_arg(int *i, int *d, size_t *dat, size_t *r)
{
	*i = 0;
	*d = 0;
	*r = 0;
	*dat = 0;
}

void	ft_list_arg(const char *str, va_list args, size_t *total)
{
	int		i;
	int		d;
	size_t	r;
	size_t	dat;

	restoflist_arg(&i, &d, &dat, &r);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			if ((d = ft_checksymbols(str + i + 1)) != -1)
			{
				dat += (int)ft_strlen(controle_theoutput(str + i,
						*(str + i + d + 1), args)) - 1;
				i = i + d + 1;
			}
			else
				i = i + ft_getind(str + i + 1);
		}
		else
			i = ft_prntother(str, i);
		i++;
		r++;
	}
	*total = r + dat;
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		total;

	total = 0;
	va_start(args, str);
	ft_list_arg(str, args, &total);
	va_end(args);
	return (total);
}
