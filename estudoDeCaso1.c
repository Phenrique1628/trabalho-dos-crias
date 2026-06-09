#include <stdio.h>

int id[5]={10, 5, 78, 504, 90};
float saldo[5]={200.00, 00.00, 1621.00 , 100.00, 50.00 };

void deposito(int conta, float valor){
    saldo[conta] += valor;
    printf("\nO saldo da conta será de: %f\n", saldo[conta]);
}
void saque(int conta, float valor){
    saldo[conta] -= valor;
    printf("\nO saldo da conta será de: %f\n", saldo[conta]);
}
void ativo(){
    float soma = 0;
    for(int i=0;i<5;i++){
        soma += saldo[i];
    }
    printf("\nA soma total dos saldos é: %f\n", soma);
    
}

int encontrar(int conta){
    for(int i=0;i<5;i++){
        if(id[i] == conta)
        return i;
    }
    printf("\nConta não encontrada!\n");
    return -1;
}
int verificar(int conta, float valor){
    if(saldo[encontrar(conta)] >= valor)
        return 1;
    else 
        printf("\nSaldo insulficiente!\n");
        return 0;
}
int main()
{
    int operacao, conta;
    float valor;
    
    do{
        printf("\n1 – Efetuar depósito\n2 – Efetuar saque\n3 – Consultar o ativo bancário\n4 – Finalizar o programa \nDigite a operação desejada: ");
        scanf("%d", &operacao);
        if(operacao == 1){
            printf("Digite a conta bancária da operação: ");
            scanf("%d", &conta);
            printf("Digite o valor da operação: ");
            scanf("%d", &valor);
            if(encontrar(conta) != -1){
                deposito(encontrar(conta), valor);
                
            }
        }else if(operacao == 2){
            printf("Digite a conta bancária da operação: ");
            scanf("%d", &conta);
            printf("Digite o valor da operação: ");
            scanf("%f", &valor);
            if(encontrar(conta) != -1){
                if(verificar(conta, valor) == 1)
                    saque(encontrar(conta), valor);
            }
        }else if(operacao == 3){
            ativo();
        }
        printf("\n ============================================================= \n");
    }while(operacao != 4);
}
