#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis
    char cpf[] = "12345678900";
    char senha[] = "01020304";
    float saldo = 1000.00;
    int opcao;
    float valor;
    char extrato[100][50];
    int contador_extrato = 0;
    int tentativas = 0;
    int login_sucesso = 0;

    // Tela de boas-vindas
    printf("Bem-vindo ao sistema bancário!\n");

    // Autenticação com até 2 tentativas
    while (tentativas < 2) {
        char input_cpf[12], input_senha[9];
        printf("Digite seu CPF: ");
        scanf("%s", input_cpf);
        printf("Digite sua Senha: ");
        scanf("%s", input_senha);

        if (strcmp(input_cpf, cpf) == 0 && strcmp(input_senha, senha) == 0) {
            login_sucesso = 1;
            break;
        } else {
            printf("CPF ou senha incorretos. Tente novamente.\n");
            tentativas++;
        }
    }

    if (!login_sucesso) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 1;
    }

    // Menu
    do {
        printf("\nMenu:\n");
        printf("1 – Saldo\n");
        printf("2 – Depósito\n");
        printf("3 – Saque\n");
        printf("4 – Transferência\n");
        printf("5 – Consultar Extrato\n");
        printf("0 – Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Saldo atual: R$%.2f\n", saldo);
                break;

            case 2:
                printf("Digite o valor do depósito: R$");
                scanf("%f", &valor);
                saldo += valor;
                sprintf(extrato[contador_extrato++], "Depósito: R$%.2f", valor);
                printf("Depósito realizado com sucesso!\n");
                break;

            case 3:
                printf("Digite o valor do saque: R$");
                scanf("%f", &valor);
                if (valor > saldo) {
                    printf("Saldo insuficiente para saque.\n");
                } else {
                    saldo -= valor;
                    sprintf(extrato[contador_extrato++], "Saque: R$%.2f", valor);
                    printf("Saque realizado com sucesso!\n");
                }
                break;

            case 4:
                printf("Digite o valor da transferência: R$");
                scanf("%f", &valor);
                if (valor > saldo) {
                    printf("Saldo insuficiente para transferência.\n");
                } else {
                    char conta[20], agencia[10], banco[20];
                    printf("Digite a conta de destino: ");
                    scanf("%s", conta);
                    printf("Digite a agência: ");
                    scanf("%s", agencia);
                    printf("Digite o banco: ");
                    scanf("%s", banco);
                    saldo -= valor;
                    sprintf(extrato[contador_extrato++], "Transferência: R$%.2f para %s - %s - %s", valor, conta, agencia, banco);
                    printf("Transferência realizada com sucesso!\n");
                }
                break;

            case 5:
                printf("Extrato:\n");
                for (int i = 0; i < contador_extrato; i++) {
                    printf("%s\n", extrato[i]);
                }
                break;

            case 0:
                printf("Saindo do sistema. Até logo!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
