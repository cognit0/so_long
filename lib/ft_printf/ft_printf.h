/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:51 by ayalman           #+#    #+#             */
/*   Updated: 2022/02/19 18:10:05 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

void	ft_dec2hexhigh(long int decimalNumber);
int		ft_printf(const char *str, ...);
void	ft_dec2hexlow(long int decimalNumber);
int		ft_counthex(long int decimalNumber);
void	ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_countdec(long long p);
void	ft_putnbrlu(double nb);
void	ft_putnbru(unsigned int a);
int		ft_putstr(char *str);
void	ft_pointhex(long long int decimalNumber);
int		ft_count_phex(long long int decimalNumber);
int		ft_string(va_list *args);
int		ft_slapzedik(va_list *args, char c);
int		ft_int_format(va_list *args, char c);
int		ft_hex_format(va_list *args, char c);
int		ft_unsigned_format(va_list *args);

#endif
