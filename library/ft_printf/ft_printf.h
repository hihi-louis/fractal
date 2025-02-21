/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:09 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 04:57:16 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_putpointer(unsigned long long p);
int		ft_puthex(unsigned long long n, const char type);
int		ft_putui(unsigned int n);
int		ft_printf(const char *format, ...);
void	ft_putendl_fd(char *s, int fd);
int		ft_putstr(char *str);

#endif
