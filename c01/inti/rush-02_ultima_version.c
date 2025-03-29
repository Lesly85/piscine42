#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 256

int comparar(const char *linea, const char *numero);
void imprimir_coincidencias(const char *line, int fd);
void buscar_unidades(const char *diccionario, const char *numero);
void buscar_unidades_diccionario(const char *diccionario, const char *parte);

int check_numero(const char *numero) //check per controlare limput
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
int buscar_numero_exacto(const char *diccionario, const char *numero) // cerca coincidenza nel dizionario
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

void buscar_unidades(const char *diccionario, const char *numero) //separare unita
{
    if (numero[1] != '\0') 
    { 
        char decenas[3] = {numero[0], '0', '\0'};  
        char unidades[2] = {numero[1], '\0'};       

        buscar_unidades_diccionario(diccionario, decenas);  
        write(1, " ", 1);
        buscar_unidades_diccionario(diccionario, unidades); 
        write(1, "\n", 1);
    } 
    else {
        write(1, "DictError\n", 10); 
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

void buscar_unidades_diccionario(const char *diccionario, const char *parte) //cerca unita singole
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
    //printf("%s\n", line);
    int i;

    i = 0;
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

    if (!buscar_numero_exacto(diccionario, numero)) //cerca coincidenze nel dizionario
    {
        
        buscar_unidades(diccionario, numero); //cerca unita singole
    }
}