/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:15:22 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/08 16:53:58 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
int	main(void)
{
	int	mem[12];
	int	i;

	ft_bzero(mem, 3 * sizeof(int));
	i = 0;
	while (i < 3)
		printf("%i\n", mem[i++]);
	return (0);
}
*/
