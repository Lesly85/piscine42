/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:24:21 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/21 21:27:55 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numb(int x)
{
	char	ten;
	char	one;

	ten = x / 10 + '0';
	one = x % 10 + '0';
	write(1, &ten, 1);
	write(1, &one, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_print_numb(first);
			write(1, " ", 1);
			ft_print_numb(second);
			if (first != 98)
			{
				write(1, ", ", 2);
			}
			second++;
		}
		first++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
