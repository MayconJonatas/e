#include <stdio.h>

#define MAX_SIZE 20

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Conjunto;

Conjunto criarConjuntoVazio() {
    Conjunto conjunto;
    conjunto.tamanho = 0;
    return conjunto;
}

void lerConjunto(Conjunto* conjunto) {
    int i;

    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &(conjunto->tamanho));

    printf("Digite os %d elementos do conjunto:\n", conjunto->tamanho);
    for (i = 0; i < conjunto->tamanho; i++) {
        scanf("%d", &(conjunto->elementos[i]));
    }
}

Conjunto uniao(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto conjuntoUniao;
    int i, j, k;
    int repetido;

    // Inicializar conjuntoUniao como conjunto1
    conjuntoUniao = conjunto1;

    // Adicionar elementos de conjunto2 em conjuntoUniao
    for (i = 0; i < conjunto2.tamanho; i++) {
        repetido = 0;
        for (j = 0; j < conjunto1.tamanho; j++) {
            if (conjunto2.elementos[i] == conjunto1.elementos[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            conjuntoUniao.elementos[conjuntoUniao.tamanho] = conjunto2.elementos[i];
            conjuntoUniao.tamanho++;
        }
    }

    return conjuntoUniao;
}

Conjunto intersecao(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto conjuntoIntersecao;
    int i, j;

    conjuntoIntersecao.tamanho = 0;

    // Adicionar elementos em conjuntoIntersecao se eles estão presentes em ambos conjuntos
    for (i = 0; i < conjunto1.tamanho; i++) {
        for (j = 0; j < conjunto2.tamanho; j++) {
            if (conjunto1.elementos[i] == conjunto2.elementos[j]) {
                conjuntoIntersecao.elementos[conjuntoIntersecao.tamanho] = conjunto1.elementos[i];
                conjuntoIntersecao.tamanho++;
                break;
            }
        }
    }

    return conjuntoIntersecao;
}

int saoIguais(Conjunto conjunto1, Conjunto conjunto2) {
    // Dois conjuntos são iguais se possuem os mesmos elementos, mesmo que fora de ordem

    if (conjunto1.tamanho != conjunto2.tamanho) {
        return 0;
    }

    int i, j;

    for (i = 0; i < conjunto1.tamanho; i++) {
        int encontrado = 0;
        for (j = 0; j < conjunto2.tamanho; j++) {
            if (conjunto1.elementos[i] == conjunto2.elementos[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return 0;
        }
    }

    return 1;
}

void imprimirConjunto(Conjunto conjunto) {
    printf("{ ");
    int i;
    for (i = 0; i < conjunto.tamanho; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto conjunto1, conjunto2, conjuntoUniao, conjuntoIntersecao;
    int iguais;

    // Testando as funções

    conjunto1 = criarConjuntoVazio();
    lerConjunto(&conjunto1);

    conjunto2 = criarConjuntoVazio();
    lerConjunto(&conjunto2);

    conjuntoUniao = uniao(conjunto1, conjunto2);
    printf("União dos conjuntos: ");
    imprimirConjunto(conjuntoUniao);

    conjuntoIntersecao = intersecao(conjunto1, conjunto2);
    printf("Interseção dos conjuntos: ");
    imprimirConjunto(conjuntoIntersecao);

    iguais = saoIguais(conjunto1, conjunto2);
    if (iguais) {
        printf("Os conjuntos são iguais.\n");
    } else {
        printf("Os conjuntos são diferentes.\n");
    }

    return 0;
}
