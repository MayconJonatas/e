#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 50

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Cliente {
    char nome[100];
    struct Data dataNascimento;
    int idade;
    char sexo;
};

struct Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

void calcularIdade(struct Cliente *cliente) {
    struct Data dataAtual;
    // Supondo que a data atual já esteja preenchida com valores reais
    // para simular, podemos preencher com uma data fixa:
    dataAtual.dia = 31;
    dataAtual.mes = 12;
    dataAtual.ano = 2022;

    int idade = dataAtual.ano - cliente->dataNascimento.ano;
    if (dataAtual.mes < cliente->dataNascimento.mes ||
        (dataAtual.mes == cliente->dataNascimento.mes && dataAtual.dia < cliente->dataNascimento.dia)) {
        idade--;
    }
    cliente->idade = idade;
}

void cadastrarCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite máximo de clientes alcançado.\n");
        return;
    }

    struct Cliente cliente;

    printf("Digite o nome do cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes, &cliente.dataNascimento.ano);
    getchar(); // descarta o caractere de nova linha após a leitura

    printf("Digite o sexo (M ou F): ");
    scanf("%c", &cliente.sexo);
    getchar(); // descarta o caractere de nova linha após a leitura

    calcularIdade(&cliente);

    clientes[numClientes++] = cliente;

    printf("Cliente cadastrado com sucesso.\n");
}

void listarClientes() {
    printf("Lista de clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Data de nascimento: %d/%d/%d\n",
            clientes[i].dataNascimento.dia,
            clientes[i].dataNascimento.mes,
            clientes[i].dataNascimento.ano);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Sexo: %c\n", clientes[i].sexo);
        printf("\n");
    }
}

int main() {
    int opcao;

    do {
        printf("Selecione uma opção:\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // descarta o caractere de nova linha após a leitura

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
