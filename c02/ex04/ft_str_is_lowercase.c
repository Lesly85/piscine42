/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:27:29 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/30 14:54:38 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char	str1[] = "laachimba";
	char 	str2[] = "";
	char	str3[] = "AB787^%&";
	char	result;

	result = ft_str_is_lowercase(str1) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_lowercase(str2) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_lowercase(str3) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	return (0);
}*/
