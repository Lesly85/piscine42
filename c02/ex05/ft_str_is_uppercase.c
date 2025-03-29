/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:11:26 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/30 15:48:45 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}

/*int	main (void)
{
	char	*str1 = "PAPAYA";
	char	*str2 = "";
	char	*str3 = "ajaja@#$%";
	char	result;

	result = ft_str_is_uppercase(str1) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_uppercase(str2) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_uppercase(str3) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);
	
	return (0);
}*/
