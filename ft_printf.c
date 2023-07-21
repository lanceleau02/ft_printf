/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:34:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/21 15:26:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	define_type(char c, t_program *data, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), data);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), data);
	if (c == 'p')
		ft_putadd(va_arg(ap, void *), data);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), 10, "0123456789", data);
	if (c == 'u')
		ft_putunbr_base(va_arg(ap, unsigned int), 10, "0123456789", data);
	if (c == 'x')
		ft_putunbr_base(va_arg(ap, unsigned int), 16, "0123456789abcdef", data);
	if (c == 'X')
		ft_putunbr_base(va_arg(ap, unsigned int), 16, "0123456789ABCDEF", data);
	if (c == '%')
		ft_putchar('%', data);
}

int	ft_printf(const char *format, ...)
{
	t_program	data;
	va_list		ap;
	int			i;

	if (format == NULL)
		return (-1);
	data.written = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			define_type(format[i + 1], &data, ap);
			i++;
		}
		else
			ft_putchar(format[i], &data);
		i++;
	}
	va_end(ap);
	return (data.written);
}
