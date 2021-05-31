/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirama <shirama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:50:54 by shirama           #+#    #+#             */
/*   Updated: 2021/05/26 18:18:20 by shirama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
**int		main(void)
**{
**	int		i;
**	puts("------------------");
**	for (i = '0'; i <= '9'; i++)
**	{
**		printf("original:%d arg:%c\n", isdigit(i), i);
**		printf("ft	:%d arg:%c\n", ft_isdigit(i), i);
**		puts("------------------");
**	}
**	printf("original:%d arg:%c\n", isdigit('A'), 'A');
**	printf("ft	:%d arg:%c\n", ft_isdigit('A'), 'A');
**	puts("------------------");
**	return (0);
**}
*/
