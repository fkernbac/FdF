/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:25:52 by fkernbac          #+#    #+#             */
/*   Updated: 2022/05/22 01:39:39 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	count_and_free(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	free(str);
	return (len);
}

static size_t	print_parameter(va_list args, char signifier)
{
	char	*str;

	if (signifier == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	else if (signifier == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (signifier == 'p')
		str = ft_ptoa((unsigned long) va_arg(args, unsigned long));
	else if (signifier == 'd' || signifier == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (signifier == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (signifier == 'x' || signifier == 'X')
		str = ft_hextoa(va_arg(args, unsigned int), signifier);
	else if (signifier == '%')
		str = ft_strdup("\%");
	else
		return (0);
	if (str == NULL)
		str = ft_strdup("(null)");
	ft_putstr_fd(str, 1);
	return (count_and_free(str));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	written;
	size_t	i;

	i = 0;
	written = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			written++;
		}
		else
		{
			i++;
			written += print_parameter(args, str[i]);
		}
		i++;
	}
	va_end(args);
	return (written);
}
