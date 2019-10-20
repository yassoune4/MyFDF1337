/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:50:31 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/15 15:59:14 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar_fd((char)s[i], fd);
			i++;
		}
	}
}
