/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:16 by lesescob          #+#    #+#             */
/*   Updated: 2024/11/02 15:50:06 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 256

int check_numero(const char *numero)
{
    if (*numero == '\0')
    {
        write(1, "Error\n", 6);
        return (0);
    }
    while (*numero) 
    {
        if (*numero < '0' || *numero > '9') 
        { 
            write(1, "Error\n", 6);
            return (0); 
        } 
        numero++;
    } 
    return (1);        
}

int compare_strings(const char *str1, const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return (*str2 == '\0');
}

void buscar_en_diccionario(const char *diccionario, const char *numero)
{
    int fd;
    char buffer[BUFFER_SIZE];
    int bytes;
    int i;
    int found = 0;

    fd = open(diccionario, O_RDONLY);
    if (fd == -1)
    {
        write(1, "DictError\n", 10);
        return;
    }

    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        i = 0;
        while (i < bytes)
        {
            // Trova l'inizio di una potenziale corrispondenza
            if (buffer[i] == numero[0])
            {
                // Verifica se `numero` è presente da questa posizione
                if (compare_strings(&buffer[i], numero))
                {
                    found = 1;
                    write(1, buffer, bytes);
                    break;
                }
            }
            i++;
        }
        if (found) break;
    }
    close(fd);
    if (!found)
        write(1, "Number not found\n", 17);
}

int main(int argc, char *argv[])
{
    const char *diccionario;
    const char *numero;

    if (argc > 3)
    {
        write(1, "Error\n", 6);
        return (1);
    }

    if (argc == 2)
    {
        if (!check_numero(argv[1]))  
            return (1);
        diccionario = "numbers.dict";
        numero = argv[1];
    } 
    else if (argc == 3)
    {
        if (!check_numero(argv[2]))  
            return (1);
        diccionario = argv[1];
        numero = argv[2];
    } 
    else
    {
        write(1, "Error\n", 6);
        return (1);
    }

    buscar_en_diccionario(diccionario, numero);
    return (0);
}

