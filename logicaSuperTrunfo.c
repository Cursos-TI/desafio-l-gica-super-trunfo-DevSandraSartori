#include <stdio.h>
#include <string.h>

int main() {
    printf("\n------- Desafio Nível Mestre -------\n");

    // ===== VARIÁVEIS CARTA 1 =====
    char estado1, codigo1[4], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosturisticos1;
    float densidade1, pibpercapita1;

    // ===== VARIÁVEIS CARTA 2 =====
    char estado2, codigo2[4], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosturisticos2;
    float densidade2, pibpercapita2;

    int atributo1, atributo2; // escolhas do jogador

    // ===== CADASTRO CARTA 1 =====
    printf("\n------- Cadastro da Carta 1 -------\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Código da carta (Ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade/País: ");
    getchar();
    fgets(cidade1, 50, stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%lu", &populacao1);

    printf("Digite a área (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosturisticos1);

    // CÁLCULOS CARTA 1
    densidade1 = (float) populacao1 / area1;
    pibpercapita1 = (pib1 * 1000000000) / (float) populacao1;

    // ===== CADASTRO CARTA 2 =====
    printf("\n------- Cadastro da Carta 2 -------\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da carta (Ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade/País: ");
    getchar();
    fgets(cidade2, 50, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosturisticos2);

    // CÁLCULOS CARTA 2
    densidade2 = (float) populacao2 / area2;
    pibpercapita2 = (pib2 * 1000000000) / (float) populacao2;

    // ===== MENU DE ESCOLHA =====
    printf("\nEscolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &atributo1);

    printf("\nEscolha o SEGUNDO atributo para comparação:\n");
    switch (atributo1) {
        case 1: printf("2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n"); break;
        case 2: printf("1 - População\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n"); break;
        case 3: printf("1 - População\n2 - Área\n4 - Pontos Turísticos\n5 - Densidade Populacional\n"); break;
        case 4: printf("1 - População\n2 - Área\n3 - PIB\n5 - Densidade Populacional\n"); break;
        case 5: printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n"); break;
        default: printf("Opção inválida! Encerrando.\n"); return 0;
    }
    printf("Digite sua escolha: ");
    scanf("%d", &atributo2);

    // ===== PEGAR VALORES =====
    float valor1A, valor2A, valor1B, valor2B;
    switch (atributo1) {
        case 1: valor1A = populacao1; valor2A = populacao2; break;
        case 2: valor1A = area1; valor2A = area2; break;
        case 3: valor1A = pib1; valor2A = pib2; break;
        case 4: valor1A = pontosturisticos1; valor2A = pontosturisticos2; break;
        case 5: valor1A = densidade1; valor2A = densidade2; break;
    }
    switch (atributo2) {
        case 1: valor1B = populacao1; valor2B = populacao2; break;
        case 2: valor1B = area1; valor2B = area2; break;
        case 3: valor1B = pib1; valor2B = pib2; break;
        case 4: valor1B = pontosturisticos1; valor2B = pontosturisticos2; break;
        case 5: valor1B = densidade1; valor2B = densidade2; break;
    }

    printf("\n------- Comparação de Cartas -------\n");
    printf("Cidade 1: %s\nCidade 2: %s\n\n", cidade1, cidade2);

    int pontos1 = 0, pontos2 = 0;

    // ===== COMPARAÇÃO ATRIBUTO 1 =====
    printf("Atributo 1: ");
    if (atributo1 == 1) printf("População -> %lu vs %lu\n", populacao1, populacao2);
    if (atributo1 == 2) printf("Área -> %.2f vs %.2f\n", area1, area2);
    if (atributo1 == 3) printf("PIB -> %.2f vs %.2f\n", pib1, pib2);
    if (atributo1 == 4) printf("Pontos Turísticos -> %d vs %d\n", pontosturisticos1, pontosturisticos2);
    if (atributo1 == 5) printf("Densidade Populacional -> %.2f vs %.2f\n", densidade1, densidade2);

    if (atributo1 == 5) { // densidade: menor vence
        if (valor1A < valor2A) { printf("Vencedor: %s\n\n", cidade1); pontos1++; }
        else if (valor2A < valor1A) { printf("Vencedor: %s\n\n", cidade2); pontos2++; }
        else printf("Empate neste atributo!\n\n");
    } else {
        if (valor1A > valor2A) { printf("Vencedor: %s\n\n", cidade1); pontos1++; }
        else if (valor2A > valor1A) { printf("Vencedor: %s\n\n", cidade2); pontos2++; }
        else printf("Empate neste atributo!\n\n");
    }

    // ===== COMPARAÇÃO ATRIBUTO 2 =====
    printf("Atributo 2: ");
    if (atributo2 == 1) printf("População -> %lu vs %lu\n", populacao1, populacao2);
    if (atributo2 == 2) printf("Área -> %.2f vs %.2f\n", area1, area2);
    if (atributo2 == 3) printf("PIB -> %.2f vs %.2f\n", pib1, pib2);
    if (atributo2 == 4) printf("Pontos Turísticos -> %d vs %d\n", pontosturisticos1, pontosturisticos2);
    if (atributo2 == 5) printf("Densidade Populacional -> %.2f vs %.2f\n", densidade1, densidade2);

    if (atributo2 == 5) {
        if (valor1B < valor2B) { printf("Vencedor: %s\n\n", cidade1); pontos1++; }
        else if (valor2B < valor1B) { printf("Vencedor: %s\n\n", cidade2); pontos2++; }
        else printf("Empate neste atributo!\n\n");
    } else {
        if (valor1B > valor2B) { printf("Vencedor: %s\n\n", cidade1); pontos1++; }
        else if (valor2B > valor1B) { printf("Vencedor: %s\n\n", cidade2); pontos2++; }
        else printf("Empate neste atributo!\n\n");
    }

    // ===== SOMA FINAL =====
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;
    printf("Soma dos atributos: %.2f (%s) vs %.2f (%s)\n", soma1, cidade1, soma2, cidade2);

    if (soma1 > soma2) {
        printf("Resultado Final: Carta 1 (%s) venceu!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("Resultado Final: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado Final: Empate!\n");
    }

    return 0;
}