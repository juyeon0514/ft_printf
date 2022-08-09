/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:43:30 by juykang           #+#    #+#             */
/*   Updated: 2022/08/08 21:59:30 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(long nb, int base_len)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb = nb / base_len;
	}
	return (len);
}

int	ft_unbr_len(unsigned long unbr, int base_len)
{
	int	len;

	len = 0;
	if (unbr == 0)
		len = 1;
	while (unbr != 0)
	{
		len++;
		unbr = unbr / base_len;
	}
	return (len);
}

void	put_nbr_itoa(long nb, int nb_len, char *res, char *nb_base)
{
	const int	base_len = ft_strlen(nb_base);

	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	else if (nb == 0)
		res[0] = '0';
	while (nb != 0 && (--nb_len) >= 0)
	{
		res[nb_len] = nb_base[nb % base_len];
		nb = nb / base_len;
	}
}

void	put_unbr_itoa(unsigned long nb, int nb_len, char *res, char *nb_base)
{
	const int	base_len = ft_strlen(nb_base);
	int			i;

	i = 0;
	if (nb == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[--nb_len] = nb_base[nb % base_len];
		nb = nb / base_len;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
