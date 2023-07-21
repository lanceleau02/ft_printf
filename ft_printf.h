/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:13:58 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/11 13:23:44 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_program
{
	int		written;
}	t_program;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, t_program *data);
void	ft_putstr(char *str, t_program *data);
void	ft_putadd(void *nb, t_program *data);
void	ft_putnbr_base(__intmax_t n, int base, char *cbase, t_program *data);
void	ft_putunbr_base(__uintmax_t n, int base, char *cbase, t_program *data);

#endif
