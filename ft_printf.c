/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:19:22 by juykang           #+#    #+#             */
/*   Updated: 2022/08/09 12:03:16 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_specifier(t_specifier *option)
{
	option->flag = 0;
	option->len = 0;
	option->precision = 0;
	option->output = 0;
	option->width = 0;
}

int	find_flags(const char c)
{
	const char	flag[5] = {'-', '+', '0', ' ', '.'};
	int			i;

	i = -1;
	while (flag[++i])
	{
		if (flag[i] == c)
			return (i);
	}
	return (-1);
}

int	find_specifier(const char c)
{
	const char	specifier[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
	int			i;

	i = -1;
	while (specifier[++i])
	{
		if (specifier[i] == c)
			return (i);
	}
	return (-1);
}

int	print_specifier(const char *format, int i, va_list ap)
{
	const t_idx	put[9] = {put_chr, put_str, put_ptr, put_nbr, put_nbr, \
						put_unbr, put_hex_lower, put_hex_upper, put_percent};
	t_specifier	option;
	int			res;

	init_specifier(&option);
	res = put[find_specifier(format[i])](&option, ap);
	free(option.output);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		tem;
	int		res;
	int		i;

	i = -1;
	res = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			tem = print_specifier(format, i + 1, ap);
			i++;
		}
		else
			tem = write(1, &format[i], 1);
		if (tem < 0)
			return (-1);
		res += tem;
	}
	va_end(ap);
	return (res);
}
