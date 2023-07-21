/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:41:21 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/13 09:34:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_program *data)
{
	data->written += write(1, &c, 1);
}

void	ft_putstr(char *str, t_program *data)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", data);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		data->written += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putadd(void *nb, t_program *data)
{
	if (nb == 0)
	{
		ft_putstr("(nil)", data);
		return ;
	}
	ft_putstr("0x", data);
	ft_putunbr_base((unsigned long)nb, 16, "0123456789abcdef", data);
}

void	ft_putnbr_base(__intmax_t n, int base, char *cbase, t_program *data)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', data);
	}
	if (n >= (__intmax_t)base)
		ft_putnbr_base(n / base, base, cbase, data);
	ft_putchar(cbase[n % base], data);
}

void	ft_putunbr_base(__uintmax_t n, int base, char *cbase, t_program *data)
{
	if (n >= (__uintmax_t)base)
		ft_putunbr_base(n / base, base, cbase, data);
	ft_putchar(cbase[n % base], data);
}
