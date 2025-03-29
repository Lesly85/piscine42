/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:00:45 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/29 22:25:29 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char	str1[] = "1234567890";
	char	str2[] = "fdteF3@#";
	char	str3[] = "";

	printf("str1 = %d\n", ft_str_is_numeric(str1));
	printf("str2 = %d\n", ft_str_is_numeric(str2));
	printf("str3 = %d\n", ft_str_is_numeric(str3));
}*/
