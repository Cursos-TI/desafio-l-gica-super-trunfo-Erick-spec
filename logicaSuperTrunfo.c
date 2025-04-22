#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    return pib / populacao;
}

int main() {
    // Cadastro das duas cartas (manualmente)
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 236500000000.0, 50};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6718903, 1182.30, 369000000000.0, 40};

    // Cálculo dos atributos derivados
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);

    carta1.pibPerCapita = calcularPibPerCapita(carta1.pib, carta1.populacao);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.pib, carta2.populacao);

    // Escolha do atributo para comparação (fixa: População)
    printf("Comparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Comparação usando if / if-else
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
