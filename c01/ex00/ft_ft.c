/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:28:54 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/22 17:16:51 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*int	main(void)
{
	int	a;
	char	tens;
	char	units;
	
	a = 50;
	ft_ft(&a);
	tens = a / 10 + '0';
	write(1, &tens, 1);
	units = a % 10 + '0';
	write(1, &units, 1);
	return (0);
	
	//printf("%d", a);
}*/
