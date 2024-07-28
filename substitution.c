#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que verifica se a chave é válida
bool is_valid_key(string key);

// Função que converte a chave para letras maiúsculas
void convert_to_uppercase(string key);

// Função que criptografa e imprime o texto
void encrypt_and_print(string text, string key);

int main(int argc, string argv[])
{
    // Verifica se o usuário forneceu exatamente um argumento (a chave)
    if (argc != 2)
    {
        printf("Uso: ./substitution <chave de 26 caracteres>\n");
        return 1;
    }

    string key = argv[1];

    // Valida a chave fornecida
    if (!is_valid_key(key))
    {
        return 1; // Retorna 1 se a chave não for válida
    }

    // Pede ao usuário que insira um texto para criptografar
    string text = get_string("plaintext: ");

    // Converte a chave para letras maiúsculas
    convert_to_uppercase(key);

    // Criptografa o texto e imprime o resultado
    encrypt_and_print(text, key);

    return 0; // Retorna 0 indicando sucesso
}

// Função para validar a chave
bool is_valid_key(string key)
{
    // Verifica se a chave tem 26 caracteres
    if (strlen(key) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return false;
    }

    // Cria um array booleano para rastrear letras repetidas
    bool letters[26] = {0};

    // Verifica cada caractere da chave
    for (int i = 0; i < 26; i++)
    {
        // Verifica se o caractere é uma letra
        if (!isalpha(key[i]))
        {
            printf("A chave deve conter apenas letras.\n");
            return false;
        }

        // Converte a letra para maiúscula e calcula seu índice
        int index = toupper(key[i]) - 'A';

        // Verifica se a letra já foi usada
        if (letters[index])
        {
            printf("A chave não deve conter caracteres repetidos.\n");
            return false;
        }

        // Marca a letra como usada
        letters[index] = true;
    }

    return true; // Retorna true se a chave for válida
}

// Função para converter a chave para letras maiúsculas
void convert_to_uppercase(string key)
{
    // Converte cada letra da chave para maiúscula
    for (int i = 0; i < 26; i++)
    {
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }
}

// Função para criptografar e imprimir o texto
void encrypt_and_print(string text, string key)
{
    printf("ciphertext: ");

    // Itera sobre cada caractere do texto
    for (int i = 0; i < strlen(text); i++)
    {
        // Se o caractere é uma letra maiúscula
        if (isupper(text[i]))
        {
            // Calcula o índice e imprime o caractere correspondente da chave
            int index = text[i] - 'A';
            printf("%c", key[index]);
        }
        // Se o caractere é uma letra minúscula
        else if (islower(text[i]))
        {
            // Calcula o índice e imprime o caractere correspondente da chave em minúscula
            int index = text[i] - 'a';
            printf("%c", tolower(key[index]));
        }
        // Se o caractere não é uma letra
        else
        {
            // Imprime o caractere como está
            printf("%c", text[i]);
        }
    }

    printf("\n"); // Imprime uma nova linha após o texto cifrado
}
