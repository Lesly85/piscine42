/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:50:45 by lesescob          #+#    #+#             */
/*   Updated: 2024/10/31 18:09:10 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int   main()
{
        char    src[] = "hola care bola";
        char    dest[20];

        ft_strncpy(dest, src, 6);// il sei sta per il parametro n
        //dest[6] = '\0';//per forzare  metto meno spazio a dest
        printf("copia:%s", dest);
        return (0);

}*/
