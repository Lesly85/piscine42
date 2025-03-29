/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:08:37 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/28 16:25:45 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*int	main(int argc, char **argv) // mi volevo complicare la vita
{	
	char	*str;
	
	if (argc > 1)
	{
		str = argv[1];
		ft_putstr(str);
	}
	else
	{
		ft_putstr("nada de nada");
	}
	return (0);
}*/

/*	char c = 'a';
	char	*	str;
	str = &c;
	write(1, &c, 1);
	write(1, "\n", 1);


	*str = 'x';
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, str, 1);
	write(1, "\n", 1);
}
	return (0);
}*/
