/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:49:48 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/29 21:50:54 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 65 && str[i] <= 90)
				|| (str[i] >= 97 && str[i] <= 122)))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("str1 = %d\n", ft_str_is_alpha("ABCdef"));
	printf("str2 = %d\n", ft_str_is_alpha(""));
        printf("str3 = %d\n", ft_str_is_alpha("12345@#$"));
	return (0);
}*/
