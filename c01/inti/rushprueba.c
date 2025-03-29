#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 256

int comparar(const char *linea, const char *numero);
void imprimir_coincidencias(const char *line, int fd);
void buscar_decenas_unidades(const char *diccionario, const char *numero);
void buscar_bloques(const char *diccionario, const char *numero, const char **prefijos);
void buscar_unidades_diccionario(const char *diccionario, const char *parte);

const char *prefijos[] = {
    "", "thousand", "million", "billion", "trillion", "quadrillion",
    "quintillion", "sextillion", "septillion", "octillion",
    "nonillion", "decillion", "undecillion"
};

int check_numero(const char *numero) // Verificar si el input es un número
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

int buscar_numero_exacto(const char *diccionario, const char *numero) // Buscar coincidencias exactas en el diccionario
{
    int fd = open(diccionario, O_RDONLY);
    char buffer[BUFFER_SIZE];
    int i = 0;
    int bytes;

    if(fd == -1)
    {
        write(1, "DictError\n", 10);
        return (0);
    }

    while ((bytes = read(fd, &buffer[i], 1)) > 0) 
    {
        if (buffer[i] == '\n' || i == BUFFER_SIZE - 1) 
        {
            buffer[i] = '\0';
            if (comparar(buffer, numero)) 
            { 
                imprimir_coincidencias(buffer, fd);
                return (1); 
            }
            i = 0; 
        }
        else 
            i++; 
    }

    close(fd);
    return (0);  
}

void buscar_decenas_unidades(const char *diccionario, const char *numero) // Separar en decenas y unidades
{
    if (numero[1] != '\0') 
    { 
        char decenas[3] = {numero[0], '0', '\0'};  
        char unidades[2] = {numero[1], '\0'};       

        buscar_unidades_diccionario(diccionario, decenas);  
        write(1, " ", 1);
        buscar_unidades_diccionario(diccionario, unidades); 
    } 
    else {
        buscar_unidades_diccionario(diccionario, numero);
    }
}

void procesar_bloque(const char *diccionario, const char *bloque)
{
    if (bloque[0] != '0') {
        char centena[2] = {bloque[0], '\0'};
        buscar_unidades_diccionario(diccionario, centena);
        write(1, " hundred ", 9);
    }
    if (bloque[1] == '1') {
        buscar_unidades_diccionario(diccionario, &bloque[1]); // 10 a 19
    } else {
        if (bloque[1] != '0') {
            char decenas[3] = {bloque[1], '0', '\0'};
            buscar_unidades_diccionario(diccionario, decenas); // 20, 30, ..., 90
            write(1, " ", 1);
        }
        if (bloque[2] != '0') {
            char unidades[2] = {bloque[2], '\0'};
            buscar_unidades_diccionario(diccionario, unidades); // unidades
        }
    }
}

void buscar_bloques(const char *diccionario, const char *numero, const char **prefijos)
{
    int len = strlen(numero);
    int bloques = (len + 2) / 3; // Cantidad de bloques de tres dígitos
    int start = len % 3; // Posición de inicio en el número para el primer bloque
    if (start == 0) start = 3;

    int prefijo_index = bloques - 1;
    for (int i = 0; i < bloques; i++)
    {
        char bloque[4] = {'0', '0', '0', '\0'};
        if (start > 0) {
            strncpy(bloque, numero, start);
            numero += start;
            start = 0;
        } else {
            strncpy(bloque, numero, 3);
            numero += 3;
        }

        if (bloque[0] != '0' || bloque[1] != '0' || bloque[2] != '0') {
            procesar_bloque(diccionario, bloque);
            if (prefijos[prefijo_index][0] != '\0') {
                write(1, " ", 1);
                write(1, prefijos[prefijo_index], strlen(prefijos[prefijo_index]));
            }
            if (i < bloques - 1) write(1, " ", 1);
        }
        prefijo_index--;
    }
}

int comparar(const char *linea, const char *numero) 
{ 
    while (*linea == *numero && *numero != '\0') 
    { 
        linea++;
        numero++; 
    }
    return (*numero == '\0' && *linea == ':');
}

void buscar_unidades_diccionario(const char *diccionario, const char *parte) // Buscar parte específica en el diccionario
{
    int fd = open(diccionario, O_RDONLY);
    char buffer[BUFFER_SIZE];
    int i = 0;
    int bytes;

    if(fd == -1)
    {
        write(1, "DictError\n", 10);
        return;
    }

    while ((bytes = read(fd, &buffer[i], 1)) > 0) 
    {
        if (buffer[i] == '\n' || i == BUFFER_SIZE - 1) 
        {
            buffer[i] = '\0';
            if (comparar(buffer, parte)) 
            { 
                imprimir_coincidencias(buffer, fd);
                return;
            }
            i = 0; 
        }
        else 
            i++; 
    }

    write(1, "DictError\n", 10); 
    close(fd);
}

void imprimir_coincidencias(const char *line, int fd)
{
    int i = 0;
    while(line[i] != '\0')
    {
        if (line[i] == ' ')
        {
            i++;
            while(line[i] != '\0')
            {
                write(1, &line[i], 1);
                i++;
            }
            break;
        }
        i++;
    }
    close(fd);
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

    if (!buscar_numero_exacto(diccionario, numero)) 
    {
        buscar_bloques(diccionario, numero, prefijos);
    }
}
