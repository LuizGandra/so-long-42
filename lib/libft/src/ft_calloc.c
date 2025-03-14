/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:16:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/06 18:35:21 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	m_size;
	void	*temp;

	if (!nmemb || !size)
		return (malloc(0));
	m_size = nmemb * size;
	if (m_size / size != nmemb)
		return (NULL);
	temp = malloc(m_size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, m_size);
	return (temp);
}
