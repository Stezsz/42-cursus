/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:41:56 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/19 14:41:56 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int			ft_printf(const char *format, ...);
int			ft_conver(va_list v1, const char format);
int			ft_putstr(char *str);
int			ft_putchar(int c);
int			ft_putnbr(int n);
int			ft_len(int n);
int			len_p(uintptr_t n);
int			hex_len(unsigned int num);
int			ft_puthex(unsigned int num, const char format);
int			ft_putunsigned(unsigned int n);
int			ft_unsigned_len(unsigned int n);
int			ft_putp(uintptr_t ptr);
char		*ft_uitoa(unsigned int n);
char		*ft_itoa(int n);
char		*ft_char(char *result, unsigned int number, int len);
void		ft_put_hex(unsigned int num, const char format);
void		ft_put_p(uintptr_t n);

#endif
