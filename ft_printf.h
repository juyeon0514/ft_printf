/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:21:18 by juykang           #+#    #+#             */
/*   Updated: 2022/08/08 21:54:58 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_specifier
{
	unsigned char	flag;
	int				width;
	int				precision;
	char			*output;
	int				len;
}	t_specifier;

typedef int	(*t_idx)(t_specifier *option, va_list);

int		ft_printf(const char *format, ...);
int		put_nbr(t_specifier *option, va_list ap);
int		put_unbr(t_specifier *option, va_list ap);
int		put_hex_lower(t_specifier *option, va_list ap);
int		put_hex_upper(t_specifier *option, va_list ap);
int		put_chr(t_specifier *option, va_list ap);
int		put_str(t_specifier *option, va_list ap);
int		put_percent(t_specifier *option, va_list ap);
int		put_ptr(t_specifier *option, va_list ap);
int		ft_num_len(long nb, int base_len);
int		ft_unbr_len(unsigned long unbr, int base_len);
void	put_nbr_itoa(long nb, int nb_len, char *res, char *nb_base);
void	put_unbr_itoa(unsigned long nb, int nb_len, char *res, char *nb_base);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const char *src, size_t n);
#endif