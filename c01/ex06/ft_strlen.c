/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:29:55 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/28 22:32:24 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	int	length;
	char    ten;
	char	unit;
	char	str[] = "hola come estas?";

	length = ft_strlen(str);
		ten = (length / 10) + '0';
		unit = (length % 10) + '0';
		write(1, &ten, 1);
		write(1, &unit, 1);
		write(1, "\n", 1);
	return (0);
}*/
