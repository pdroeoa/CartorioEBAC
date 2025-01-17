#include <stdio.h>     // Biblioteca para entrada e saida de dados (ex: printf, scanf)
#include <stdlib.h>    // Biblioteca para alocacao de memoria e comandos do sistema (ex: system, exit)
#include <locale.h>    // Biblioteca para configurar o uso de acentuacao e outros caracteres regionais
#include <string.h>    // Biblioteca para manipulacao de strings (ex: strcpy)
#define SENHA_SISTEMA "EBAC2025"  // Senha geral para acessar o sistema

// Funcao para verificar a senha geral do sistema
int verificarSenhaSistema() {
    char senhaDigitada[40];  // Armazena a senha digitada pelo usuario
    printf("\t\t-Registro de usuarios EBAC-\n\n");
    printf("Digite a senha do sistema: ");
    scanf("%s", senhaDigitada);
    
    if (strcmp(senhaDigitada, SENHA_SISTEMA) == 0) {
        return 1;  // Senha correta
    } else {
         int escolha;
    printf("\nSenha incorreta!\n");
    printf("1 - Tentar novamente\n");
    printf("2 - Sair do programa\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        return verificarSenhaSistema();  // Tenta novamente
    } else {
        printf("\nEncerrando o programa...\n");
        printf("\nObrigado por utilizar o sistema nosso sistema!\n");
        exit(0);  // Encerra o programa
    }
    }
}

// Funcao responsavel por cadastrar novos usuarios no sistema
void registrar() {
    char arquivo[40];     // Nome do arquivo (CPF)
    char cpf[40];         // CPF do usuario
    char nome[100];       // Nome do usuario
    char sobrenome[100];  // Sobrenome do usuario
    char cargo[100];      // Cargo do usuario

    printf("Digite o CPF a ser cadastrado:  ");
    scanf("%s", cpf);     // Le o CPF do usuario

    strcpy(arquivo, cpf); // Copia o CPF para a variavel arquivo (nome do arquivo)

    FILE *file = fopen(arquivo, "w");  // Criacao e abertura do arquivo no modo "w" (escrita/write)
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a");  // Abertura do arquivo no modo "a" (acrescimo)
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    getchar();  // Limpa o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;  // Remove o \n do final da string
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado:  ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = 0;  // Remove o \n do final da string
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:  ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = 0;  // Remove o \n do final da string
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

// Funcao para consultar um usuario no sistema pelo CPF
void consultar() {
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("Usuario nao localizado, pressione qualquer tecla para voltar ao menu principal\n");
        system("pause");
        return;
    }

    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
    system("pause");
}

// Funcao para deletar um usuario cadastrado no sistema
void deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: \n");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuario deletado com sucesso.\n");
    } else {
        printf("Erro: O usuario nao esta cadastrado no sistema.\n");
    }

    system("pause");
}

// Funcao principal que gerencia o programa
int main() {
    int opcao = 0;
    int laco = 1;

    if (!verificarSenhaSistema()) {
        exit(0);
    }

    while (laco == 1) {
        system("cls");
        setlocale(LC_ALL, "English");

        printf("\t\t-Registro de usuarios EBAC-\n\n");
        printf("\t1 - Registrar usuario\n\n");
        printf("\t2 - Consultar usuario\n\n");
        printf("\t3 - Deletar usuario\n\n");
        printf("\t0 - Sair do programa\n\n");
        printf("\tOpcao desejada: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registrar();
                break;
            case 2:
                consultar();
                break;
            case 3:
                deletar();
                break;
            case 0:
                printf("Obrigado por utilizar o sistema nosso sistema!");
                exit(0);
            default:
                printf("\tEssa opcao nao esta disponivel!\n");
                system("pause");
                break;
        }
    }
}

