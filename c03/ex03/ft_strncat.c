/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:23:27 by lesescob          #+#    #+#             */
/*   Updated: 2024/11/05 18:13:50 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	ind;

	i = 0;
	ind = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (ind < nb && src[ind] != '\0')
	{
		dest[i] = src[ind];
		i++;
		ind++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	dest1[30] = "forse ho imparato";
	char	src1[] = " qualcosa";
	unsigned int	nb;

	nb = 5;
	ft_strncat(dest1, src1, nb);
	printf("%s\n", dest1);

	return (0);
}*/
