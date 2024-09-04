#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checa se foi digitado o cartão, caso não tenha retornna a mensagem
    if (argc != 2)
    {
        //mensagem de uando falta adicionar o argumento
        printf("Use: ./recover card.raw\n");
        return 1;
    }
    //abrir arquivo
    FILE *file = fopen(argv[1], "r");
    //confere se o aruvo existe
    if ( file == NULL)
    {
        printf("Could noot open file\n");
        return 2;
    }
    // armazenar bytes em blocos
    unsigned char buffer[512];

    // conta o nummero de imagens geradas
    int count_image = 0;

    //aponta para magens recuperadas
    FILE *image = NULL;

    //nome do arquivo
    char *filename = malloc(8 * sizeof(char));

    //ler os blocos de 512 bytes
    while (fread(buffer, sizeof(char), 512, file))
    {
        //confere se os bytes indicam se incia uma imagem
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //escrever o nome dos aruivos de jpeg
            sprintf(filename, "%03i.jpg", count_image);

             //abre output, ou seja, arquivo criado
             image = fopen(filename, "w");

             //adiciona mais um ao contador de imagens
             count_image++;

        }
        //confere se o  arquivo criado contem algo ou não
        if (image != NULL)
        {
            fwrite(buffer, sizeof(char), 512, image);
        }
    }
    // liberar memoria deve ser usado caso use malloc
    free(filename);
    //fecha os arquivos abertos, nunca esuecer de fechar após abrir
    fclose(file);
    fclose(image);

    return 0;
}
