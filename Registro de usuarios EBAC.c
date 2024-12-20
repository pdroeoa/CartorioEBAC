#include <stdio.h>     // Biblioteca para entrada e saida de dados (ex: printf, scanf)
#include <stdlib.h>    // Biblioteca para alocacao de memoria e comandos do sistema (ex: system, exit)
#include <locale.h>    // Biblioteca para configurar o uso de acentuacao e outros caracteres regionais
#include <string.h>    // Biblioteca para manipulacao de strings (ex: strcpy)

// Funcao responsavel por cadastrar novos usuarios no sistema
void registrar() {
    char arquivo[40];     // Nome do arquivo (CPF)
    char cpf[40];         // CPF do usuario
    char nome[40];        // Nome do usuario
    char sobrenome[40];   // Sobrenome do usuario
    char cargo[40];       // Cargo do usuario
    
    printf("Digite o CPF a ser cadastrado:  ");
    scanf("%s", cpf);     // Le o CPF do usuario
    
    strcpy(arquivo, cpf); // Copia o CPF para a variavel arquivo (nome do arquivo)
    
    // Criacao e abertura do arquivo no modo "w" (escrita/write)
    FILE *file = fopen(arquivo, "w");  
    fprintf(file, cpf);   // Escreve o CPF no arquivo
    fclose(file);         // Fecha o arquivo
    
    // Abertura do arquivo no modo "a" (acrescimo)
    file = fopen(arquivo, "a");
    fprintf(file, ",");   // Adiciona uma virgula como separador
    fclose(file);

    // Entrada e registro do nome
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Entrada e registro do sobrenome
    printf("Digite o sobrenome a ser cadastrado:  ");
    scanf("%s", sobrenome);
    
	file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Entrada e registro do cargo
    printf("Digite o cargo a ser cadastrado:  ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);         // Fecha o arquivo

    system("pause");      // Pausa o sistema ate o usuario clicar alguma tecla
}

// Funcao para consultar um usuario no sistema pelo CPF
void consultar() {
    setlocale(LC_ALL, "English");  // Define o uso de caracteres especiais
    char cpf[40];                  // Armazena o CPF digitado para consulta
    char conteudo[200];            // Armazena o conteudo do arquivo para exibir
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);  // Le o CPF para consulta
    
    FILE *file = fopen(cpf, "r");  // Abre o arquivo com o nome do CPF
    if (file == NULL) {
        printf("Usuario nao localizado, pressione qualquer tecla para voltar ao menu principal\n");
        system("pause");
        return;
    }
    
    // Leitura e exibicao do conteudo do arquivo
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    fclose(file);  // Fecha o arquivo
    system("pause");  // Pausa o sistema
}

// Funcao para deletar um usuario cadastrado no sistema
void deletar() {
    char cpf[40];  // Armazena o CPF do usuario a ser deletado
    
    printf("Digite o CPF a ser deletado: \n");
    scanf("%s", cpf);  // Le o CPF
    
    // Tentativa de remover o arquivo com o nome do CPF
    if (remove(cpf) == 0) {
        printf("Usuario deletado com sucesso.\n");
    } else {
        printf("Erro: O usuario nao esta cadastrado no sistema.\n");
    }
    
    system("pause");  // Pausa o sistema
}

// Funcao principal que gerencia o programa
int main() {
    int opcao = 0;  // Armazena a escolha do usuario no menu
    int laco = 1;   // Controla o loop do menu
    
    while (laco == 1) {  // Loop infinito do menu
        system("cls");  // Limpa a tela
        setlocale(LC_ALL, "English");  // Define a linguagem
        
        // Exibe o menu de opcoes
        printf("\t\t-Registro de usuarios EBAC-\n\n");
        printf("\tEscolha a opcao desejada no menu:\n\n");
        printf("\t1 - Registrar usuario\n\n");
        printf("\t2 - Consultar usuario\n\n");
        printf("\t3 - Deletar usuario\n\n");
        printf("\t0 - Sair do programa\n\n");
        printf("\tOpcao desejada: ");
        scanf("%d", &opcao);  // Le a escolha do usuario
        
        system("cls");  // Limpa a tela
        
        // Executa a funcao correspondente a opcao escolhida
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
                exit(0);  // Sai do programa
            default:
                printf("\tEssa opcao nao esta disponivel!\n");
                system("pause");
                break;
        }
    }
}
