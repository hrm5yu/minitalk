/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirama <shirama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:54:56 by shirama           #+#    #+#             */
/*   Updated: 2021/05/26 18:20:54 by shirama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
**int	main(void)
**{
**	for (int i = 0; i <= 150; i++)
**	{
**		printf("original:%d arg:%c\n", isascii(i), i);
**		printf("ft	:%d arg:%c\n", ft_isascii(i), i);
**	}
**	return (0);
**}
*/
