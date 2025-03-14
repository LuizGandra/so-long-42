/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:17:49 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/06 18:37:46 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_number(long long n, int fd)
{
	char	c;

	if (n > 9)
		write_number(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		long_n = -long_n;
		ft_putchar_fd('-', fd);
	}
	write_number(long_n, fd);
}
