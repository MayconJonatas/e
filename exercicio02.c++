#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario_base;
    float beneficios;
    float descontos;
    float salario_liquido;
};

void cadastrarFuncionarios(struct Funcionario funcionarios[], int num_funcionarios) {
    for (int i = 0; i < num_funcionarios; i++) {
        printf("=== Cadastro do funcionario %d ===\n", i+1);

        printf("Nome: ");
        fflush(stdin);
        fgets(funcionarios[i].nome, 50, stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fflush(stdin);
        fgets(funcionarios[i].cargo, 50, stdin);
        funcionarios[i].cargo[strcspn(funcionarios[i].cargo, "\n")] = '\0';

        printf("Salario base: ");
        scanf("%f", &funcionarios[i].salario_base);

        printf("Beneficios: ");
        scanf("%f", &funcionarios[i].beneficios);

        printf("Descontos: ");
        scanf("%f", &funcionarios[i].descontos);

        funcionarios[i].salario_liquido = funcionarios[i].salario_base + funcionarios[i].beneficios - funcionarios[i].descontos;
        printf("\n");
    }
}

void mostrarFuncionarios(struct Funcionario funcionarios[], int num_funcionarios) {
    printf("=== Dados dos funcionarios ===\n");
    for (int i = 0; i < num_funcionarios; i++) {
        printf("=== Funcionario %d ===\n", i+1);

        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salario base: %.2f\n", funcionarios[i].salario_base);
        printf("Beneficios: %.2f\n", funcionarios[i].beneficios);
        printf("Descontos: %.2f\n", funcionarios[i].descontos);
        printf("Salario liquido: %.2f\n", funcionarios[i].salario_liquido);

        printf("\n");
    }
}

float calcularMediaSalarial(struct Funcionario funcionarios[], int num_funcionarios) {
    float soma_salarios = 0;
    for (int i = 0; i < num_funcionarios; i++) {
        soma_salarios += funcionarios[i].salario_liquido;
    }
    return soma_salarios / num_funcionarios;
}

int encontrarMaiorSalario(struct Funcionario funcionarios[], int num_funcionarios) {
    int indice_maior_salario = 0;
    for (int i = 1; i < num_funcionarios; i++) {
        if (funcionarios[i].salario_liquido > funcionarios[indice_maior_salario].salario_liquido) {
            indice_maior_salario = i;
        }
    }
    return indice_maior_salario;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int num_funcionarios;

    printf("Quantidade de funcionarios (maximo %d): ", MAX_FUNCIONARIOS);
    scanf("%d", &num_funcionarios);

    if (num_funcionarios > MAX_FUNCIONARIOS) {
        printf("Quantidade de funcionarios excede o limite. Utilizando o limite maximo.\n");
        num_funcionarios = MAX_FUNCIONARIOS;
    }

    cadastrarFuncionarios(funcionarios, num_funcionarios);

    mostrarFuncionarios(funcionarios, num_funcionarios);

    float media_salarial = calcularMediaSalarial(funcionarios, num_funcionarios);
    printf("Media Salarial: %.2f\n", media_salarial);

    int indice_maior_salario = encontrarMaiorSalario(funcionarios, num_funcionarios);
    printf("Funcionario com maior salario: %s\n", funcionarios[indice_maior_salario].nome);

    return 0;
}
