/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:54:26 by juykang           #+#    #+#             */
/*   Updated: 2022/08/08 22:03:29 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(t_specifier *option, va_list ap)
{
	long		nb;
	int			nb_len;

	nb = (long)va_arg(ap, int);
	nb_len = ft_num_len(nb, 10);
	option->len = nb_len;
	option->output = malloc(option->len);
	if (!option->output)
		return (-1);
	put_nbr_itoa(nb, nb_len, option->output, "0123456789");
	return (write(1, option->output, option->len));
}

int	put_unbr(t_specifier *option, va_list ap)
{
	unsigned int	unbr;
	int				unbr_len;

	unbr = va_arg(ap, unsigned int);
	unbr_len = ft_num_len(unbr, 10);
	option->len = unbr_len;
	option->output = malloc(option->len);
	if (!option->output)
		return (-1);
	put_unbr_itoa(unbr, unbr_len, option->output, "0123456789");
	return (write(1, option->output, option->len));
}

int	put_hex_lower(t_specifier *option, va_list ap)
{
	unsigned int	hex_nb;
	int				hex_nb_len;

	hex_nb = va_arg(ap, unsigned int);
	hex_nb_len = ft_num_len(hex_nb, 16);
	option->len = hex_nb_len;
	option->output = malloc(option->len);
	if (!option->output)
		return (-1);
	put_unbr_itoa(hex_nb, hex_nb_len, option->output, "0123456789abcdef");
	return (write(1, option->output, option->len));
}

int	put_hex_upper(t_specifier *option, va_list ap)
{
	unsigned int	hex_nb;
	int				hex_len;

	hex_nb = va_arg(ap, unsigned int);
	hex_len = ft_num_len(hex_nb, 16);
	option->len = hex_len;
	option->output = malloc(option->len);
	if (!option->output)
		return (-1);
	put_unbr_itoa(hex_nb, hex_len, option->output, "0123456789ABCDEF");
	return (write(1, option->output, option->len));
}

int	put_ptr(t_specifier *option, va_list ap)
{
	unsigned long	ptr_nb;
	int				ptr_len;

	ptr_nb = (unsigned long)va_arg(ap, void *);
	ptr_len = ft_unbr_len(ptr_nb, 16);
	option->len = ptr_len + 2;
	option->output = malloc(option->len);
	if (!option->output)
		return (-1);
	ft_memcpy(option->output, "0x", 2);
	put_unbr_itoa(ptr_nb, ptr_len, (option->output) + 2, "0123456789abcdef");
	return (write(1, option->output, option->len));
}
