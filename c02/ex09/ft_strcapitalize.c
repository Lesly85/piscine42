/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:25:49 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/31 15:48:57 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && new_word)
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && !new_word)
			str[i] += 32;
		new_word = !(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= '0' && str[i] <= '9');
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "Ciao, come stai? 42 parole quarantadue; cinquanta+e+uno";

	ft_strcapitalize(str);
	write(1, str, 55);

	return (0);
}*/
