/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:46 by juykang           #+#    #+#             */
/*   Updated: 2022/08/09 12:15:38 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_percent(t_specifier *option, va_list ap)
{
	if (!ap)
		return (-1);
	option->len = 1;
	option->output = malloc(1);
	if (!option->output)
		return (-1);
	option->output[0] = '%';
	return (write(1, option->output, 1));
}

int	put_chr(t_specifier *option, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	option->len = 1;
	option->output = malloc(1);
	if (!option->output)
		return (-1);
	option->output[0] = c;
	return (write(1, option->output, 1));
}

int	put_str(t_specifier *option, va_list ap)
{
	char	*str;
	int		str_len;

	str = va_arg(ap, char *);
	if (!str)
		str_len = 6;
	else
		str_len = ft_strlen(str);
	option->len = str_len;
	option->output = malloc(option->len);
	if (!option->output)
		return (-1);
	if (!str)
		ft_memcpy(option->output, "(null)", option->len);
	else
		ft_memcpy(option->output, str, option->len);
	return (write(1, option->output, option->len));
}

void	*ft_memcpy(void *dst, const char *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (!(temp_dst || temp_src))
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (temp_dst);
}
