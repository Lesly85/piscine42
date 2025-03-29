/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:36:51 by lesescob          #+#    #+#             */
/*   Updated: 2024/11/04 22:39:23 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

/*int	main(void)
{
	char	s1[] = "hella";
	char	s2[] = "hella";
	char	s3[] = "helios";
	char	s4[] = "hell";
	unsigned int	n;

	n = 3;
	printf("test 1: %d\n", ft_strncmp(s1, s2, n));
	printf("test 2: %d\n", ft_strncmp(s1, s3, n));
	printf("test 3: %d\n", ft_strncmp(s1, s3, 5));
	printf("test 4: %d\n", ft_strncmp(s1, s4, 5));
	printf("test 5: %d\n", ft_strncmp(s1, s2, 10));
	
	return (0);
}*/
