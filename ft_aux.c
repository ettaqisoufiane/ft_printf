/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:31:10 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/08 17:25:45 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkifreserved(char c)
{
	if (c == 'c' ||
		c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '-'
		|| c == '*' || c == '.' || ft_isdigit(c))
		return (1);
	return (0);
}

int		ft_getind(const char *str)
{
	int		i;

	i = 0;
	while (str[i++])
		if (!(ft_checkifreserved(str[i - 1])))
			return (i - 1);
	return (i);
}

int		ft_checkifcovers(char c)
{
	if (c == 'c' ||
		c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		ft_checksymbols(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) || str[i] == '%')
			break ;
		i++;
	}
	if (ft_checkifcovers(str[i]))
		return (i);
	return (-1);
}

void	initialvalues(t_analyst *data)
{
	data->leftspaces = 0;
	data->rightspaces = 0;
	data->leftzeroed = 0;
	data->precision = 0;
	data->zeroflag = 0;
	data->minusflag = 0;
}
