#include <unistd.h>
#include <fcntl.h>
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
void buscar_en_diccionario(const char *diccionario, const char *numero)
{
    int fd;
    char buffer[BUFFER_SIZE];
    int i;
    int bytes;

    i = 0;
    fd = open(diccionario, O_RDONLY);
    if(fd == -1)
    {
        write(1, "DictError", 9);
        return;
    }



}
int main(int argc, char *argv[])
{
    const char *diccionario;
    const char *numero;
    if (argc == 2 && check_numero(argv[1]))
    {
        diccionario = "numbers.dict";
        numero = argv[1];
    } 
    else if (argc == 3 && check_numero(argv[2]))
    {
        diccionario = argv[1];
        numero = argv[2];
    } 
    else if (argc > 3)
        write(1, "Error\n", 6);

    buscar_en_diccionario(diccionario, numero);
}