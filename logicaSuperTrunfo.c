#include <stdio.h>
#include <string.h>

int main() {
    printf("\n------- Desafio Nível Aventureiro -------\n");

    // ===== VARIÁVEIS CARTA 1 =====
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosturisticos1;

    float densidade1;
    float pibpercapita1;

    // ===== VARIÁVEIS CARTA 2 =====
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosturisticos2;

    float densidade2;
    float pibpercapita2;

    int escolha; // atributo que o jogador vai escolher

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
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    printf("\n------- Comparação de Cartas -------\n");

    // ===== SWITCH PARA ESCOLHA DO ATRIBUTO =====
    switch (escolha) {
        case 1: // População
            printf("Comparação: População\n");
            printf("%s: %lu habitantes\n", cidade1, populacao1);
            printf("%s: %lu habitantes\n", cidade2, populacao2);

            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else {
                if (populacao2 > populacao1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
            break;

        case 2: // Área
            printf("Comparação: Área\n");
            printf("%s: %.2f km²\n", cidade1, area1);
            printf("%s: %.2f km²\n", cidade2, area2);

            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else {
                if (area2 > area1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
            break;

        case 3: // PIB
            printf("Comparação: PIB\n");
            printf("%s: %.2f bilhões\n", cidade1, pib1);
            printf("%s: %.2f bilhões\n", cidade2, pib2);

            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else {
                if (pib2 > pib1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
            break;

        case 4: // Pontos Turísticos
            printf("Comparação: Pontos Turísticos\n");
            printf("%s: %d pontos\n", cidade1, pontosturisticos1);
            printf("%s: %d pontos\n", cidade2, pontosturisticos2);

            if (pontosturisticos1 > pontosturisticos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else {
                if (pontosturisticos2 > pontosturisticos1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
            break;

        case 5: // Densidade (menor vence)
            printf("Comparação: Densidade Populacional\n");
            printf("%s: %.2f hab/km²\n", cidade1, densidade1);
            printf("%s: %.2f hab/km²\n", cidade2, densidade2);

            if (densidade1 < densidade2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else {
                if (densidade2 < densidade1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    return 0;
}