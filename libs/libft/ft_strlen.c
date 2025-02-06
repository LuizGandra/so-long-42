/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:09:44 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 08:29:15 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("Teste retorna %zu\n", ft_strlen("Teste")); // 5
	printf("São retorna %zu\n", ft_strlen("São")); // 4
	printf("Açaí retorna %zu\n", ft_strlen("Açaí")); // 6
	printf("\\0 retorna %zu\n", ft_strlen("\0")); // 0
	printf("strlen retorna %zu\n", ft_strlen("strlen")); // 6
	return (0);
}
*/
