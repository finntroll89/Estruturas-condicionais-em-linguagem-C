#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // Declaracao de variaveis
    float rendaMensal, valorEmprestimo, valorEntrada;
    char historicoCredito, estabilidadeEmprego;
    float limiteEmprestimo;
    int aprovado = 1; // 1 = aprovado, 0 = rejeitado
    
    // Comando para limpar a tela
    system("cls");
    
    // Cabecalho do programa
    printf(" ** Emprestimo Financeiro **\n");
    printf("=====================================\n\n");
    
    // Leitura das informacoes necessarias ao programa
    printf("Digite sua renda mensal.....: ");
    scanf("%f", &rendaMensal);
    
    printf("Digite o valor do emprestimo......: ");
    scanf("%f", &valorEmprestimo);
    
    // Limpeza do buffer antes de ler caracteres
    while(getchar() != '\n');
    
    printf("Digite seu historico de credito (B=Bom, R=Ruim).............: ");
    scanf("%c", &historicoCredito);
    historicoCredito = toupper(historicoCredito);
    
    // Limpeza do buffer antes de ler caracteres
    while(getchar() != '\n');
    
    printf("Digite a sua estabilidade no emprego (E=Estavel, I=Instavel.): ");
    scanf("%c", &estabilidadeEmprego);
    estabilidadeEmprego = toupper(estabilidadeEmprego);
    
    printf("Digite o valor da entrada....: ");
    scanf("%f", &valorEntrada);
    
    printf("\n=====================================\n");
    printf("ANALISE DE CREDITO\n");
    printf("=====================================\n\n");
    
    // Calculo do limite de emprestimo (30% da renda mensal)
    limiteEmprestimo = rendaMensal * 0.30;
    
    // Criterio 1: Relacao entre renda e valor do emprestimo
    if (valorEmprestimo > limiteEmprestimo) {
        printf("[REJEITADO] CRITERIO 1: O valor do emprestimo (R$ %.2f) excede 30%% da sua renda mensal (R$ %.2f)\n", 
               valorEmprestimo, limiteEmprestimo);
        aprovado = 0;
    } else {
        printf("[APROVADO] CRITERIO 1: Valor do emprestimo aprovado (%.2f%% da renda mensal)\n", 
               (valorEmprestimo/rendaMensal)*100);
    }
    
    // Criterio 2: Historico de credito
    if (historicoCredito == 'R') {
        printf("[REJEITADO] CRITERIO 2: Historico de credito ruim - emprestimo rejeitado\n");
        aprovado = 0;
    } else if (historicoCredito == 'B') {
        printf("[APROVADO] CRITERIO 2: Historico de credito bom - criterio atendido\n");
    } else {
        printf("[REJEITADO] CRITERIO 2: Historico de credito invalido - digite B ou R\n");
        aprovado = 0;
    }
    
    // Criterio 3: Estabilidade no emprego
    if (estabilidadeEmprego == 'I') {
        printf("[REJEITADO] CRITERIO 3: Emprego instavel - risco aumentado\n");
        aprovado = 0;
    } else if (estabilidadeEmprego == 'E') {
        printf("[APROVADO] CRITERIO 3: Emprego estavel - criterio atendido\n");
    } else {
        printf("[REJEITADO] CRITERIO 3: Estabilidade no emprego invalida - digite E ou I\n");
        aprovado = 0;
    }
    
    // Criterio 4: Valor da entrada (minimo 20% do valor do emprestimo)
    float entradaMinima = valorEmprestimo * 0.20;
    if (valorEntrada < entradaMinima) {
        printf("[REJEITADO] CRITERIO 4: Valor da entrada insuficiente (minimo R$ %.2f)\n", entradaMinima);
        aprovado = 0;
    } else {
        printf("[APROVADO] CRITERIO 4: Valor da entrada adequado (%.2f%% do emprestimo)\n", 
               (valorEntrada/valorEmprestimo)*100);
    }
    
    printf("\n=====================================\n");
    printf("RESULTADO FINAL\n");
    printf("=====================================\n\n");
    
    // Resultado final da analise
    if (aprovado) {
        printf("*** PARABENS! Seu emprestimo foi APROVADO! ***\n\n");
        printf("Detalhes da aprovacao:\n");
        printf("- Valor do emprestimo: R$ %.2f\n", valorEmprestimo);
        printf("- Valor da entrada: R$ %.2f\n", valorEntrada);
        printf("- Valor a financiar: R$ %.2f\n", valorEmprestimo - valorEntrada);
        printf("- Comprometimento da renda: %.2f%%\n", (valorEmprestimo/rendaMensal)*100);
    } else {
        printf("*** EMPRESTIMO REJEITADO! ***\n\n");
        printf("Motivos da rejeicao:\n");
        printf("- Verifique os criterios marcados com [REJEITADO] acima\n");
        printf("- Ajuste as condicoes e solicite novamente\n");
        printf("- Procure orientacao financeira se necessario\n");
    }
    
    printf("\n=====================================\n");
    printf("Fim do Programa!\n");
    printf("=====================================\n");
    
    return 0;
}
