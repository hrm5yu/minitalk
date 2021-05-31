/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirama <shirama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:17:19 by shirama           #+#    #+#             */
/*   Updated: 2021/05/26 18:25:24 by shirama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return ((char *)s1);
	while (ft_memchr(set, s1[i], ft_strlen(set)) != NULL)
		i++;
	len = ft_strlen(s1);
	while (ft_memchr(set, s1[len - 1], ft_strlen(set)) != NULL)
		len--;
	if (len < i)
	{
		p = (char *)malloc(sizeof(char));
		if (!(p))
			return (NULL);
		p[0] = '\0';
	}
	else
		p = ft_substr(s1, i, len - i);
	return (p);
}

/*
**int		main(void)
**{
**	printf("\n");
**	printf("s1:%s\n", "123hello123");
**	printf("set:%s\n", "123");
**	printf("return:\"%s\"\n", ft_strtrim("123hello123", "123"));
**	printf("\n");
**	printf("s1:%s\n", "123hel123lo123");
**	printf("set:%s\n", "123");
**	printf("return:\"%s\"\n", ft_strtrim("123hel123lo123", "123"));
**	printf("\n");
**	printf("s1:%s\n", "123332131231321313321113");
**	printf("set:%s\n", "123");
**	printf("return:\"%s\"\n", ft_strtrim("123332131231321313321113", "123"));
**	printf("\n");
**	printf("s1:%s\n", "123332131231321313321113");
**	printf("set:%s\n", "123");
**	printf("return:\"%s\"\n", ft_strtrim("123332131231321313321113", "123"));
**	printf("\n");
**	printf("s1:%s\n", "NULL");
**	printf("set:%s\n", "123");
**	printf("return:\"%s\"\n", ft_strtrim(NULL, "123"));
**	printf("\n");
**	printf("s1:%s\n", "hello");
**	printf("set:%s\n", "NULL");
**	printf("return:\"%s\"\n", ft_strtrim("hello", NULL));
**	printf("\n");
**	printf("s1:%s\n", "NULL");
**	printf("set:%s\n", "NULL");
**	printf("return:\"%s\"\n", ft_strtrim(NULL, NULL));
**	printf("\n");
**	return (0);
**}
*/
