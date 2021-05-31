/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirama <shirama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:06:17 by shirama           #+#    #+#             */
/*   Updated: 2021/05/26 18:25:37 by shirama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

/*
**int		main(void)
**{
**	int		i;
**
**	for (i = 'a'; i <= 'z'; i++)
**	{
**		printf("arg:%c -> %c\n", i, ft_toupper(i));
**	}
**}
*/