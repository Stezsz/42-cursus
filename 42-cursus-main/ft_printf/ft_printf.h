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
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *printed);
void	ft_putstr(char *s, int *len);
void	ft_putadd(void	*add, int	*printed);
void	ft_putadd(void	*add, int	*printed);
void	ft_putnbr(int n, int *printed);
void	ft_putnbr_u(unsigned int n, int *printed);

#endif
