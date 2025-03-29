/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciapett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:12 by fciapett          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:13 by fciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	n;

	num = 0;
	n = 0;
	sign = 1;
	while (str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
		n++;
	while (str[n] == '-' || str[n] == '+' )
	{
		if (str[n] == '-')
		{
			sign = -sign;
		}
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		num = num * 10 + (str[n] - '0');
		n++;
	}
	return (num * sign);
}
/*
int	main(void)
{
	int	r;

	r = ft_atoi(" ---++--+1234ab567");
	printf("%d\n", r);
	return (0);
}*/
