/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:52:04 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/30 16:18:32 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}

/*int	main(void)
{
	char	*str1 = "~aBC ,.#|^";
	char	*str2 = "";
	char	*str3 = "pa\tti";
	char	result;

	result = ft_str_is_printable(str1) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_printable(str2) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	result = ft_str_is_printable(str3) + '0';
	write(1, &result, 1);
	write(1, "\n", 1);

	return (0);
}*/
