/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:59:37 by lesescob          #+#    #+#             */
/*   Updated: 2024/11/04 17:30:56 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main()
{
	int	result;

	result = ft_strcmp("hola", "hola");
	printf("confronto tra \"hola\" e \"hola\": %d\n", result);

	result = ft_strcmp("cassa", "casa");
	printf("confronto tra \"hola\" e \"hora\": %d\n", result);

	return (0);
}*/
