/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:28:42 by lesescob          #+#    #+#             */
/*   Updated: 2024/11/05 18:11:39 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	ind;

	i = 0;
	ind = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[ind] != '\0')
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

	ft_strcat(dest1, src1);
	printf("%s\n", dest1);

	return (0);
}*/
