
/*
Nome: Vinicius Diniz Amorim Simões;
data de início: 21/08/24 12:10;
data de termino:   ;
Email: vdas@cesar.school;

Mudanças:
1- 21/08/24 12:30 - Binário;
2- 21/08/24 12:36 - Hexal;
3- 21/08/24 12:44 - Octal;
4- 21/08/24 16:04 - BCD, e correção de falhas no codigo;
5- 24/08/24 18:26 - Correção do codigo;

Instruções: 

Construa uma calculadora programador didática,  implementada na linguagem C, que tenha as seguintes conversões
1 - de base 10 para:✅
a)base 2,✅ caso 1 
b) base 8,✅ caso 2 
c) base16, ✅ caso 3 
d) código BCD✅ caso 4

2 - de base 10  para base com sinal com 16 bits, (complemento a 2)
3 - converter real em decimal para float e double, mostrando os respectivos bits de sinal , expoente, expoente com viés e fração 
OBS: deve ser entregue o executável com as iniciais do email e link do git com código.  
A cada questão implementada deve ser feito um comite no git . 
O codigo fonte deve conter um cabeçalho dos dados do autor e  revisões/ atualizações com datas e hora

*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int binario[32], hexal[32], octal[32], bcd[32], num, op;
    scanf("%d", &op);
    scanf("%d", &num);
    int aux = num;
    int i = 0;

    if (num < 0) {
        num = abs(num);
    }

    switch (op) {
        case 1:
            for (i = 0; num > 0; i++) {
                binario[i] = num % 2;
                num = num / 2;
            }
            if (aux < 0) {
                printf("-");
            }
            for (int j = i - 1; j >= 0; j--) {
                printf("%d", binario[j]);
            }
            break;

        case 2:
            for (i = 0; num > 0; i++) {
                hexal[i] = num % 16;
                num = num / 16;
            }
            if (aux < 0) {
                printf("-");
            }
            for (int j = i - 1; j >= 0; j--) {
                printf("%d", hexal[j]);
            }
            break;

        case 3:
            for (i = 0; num > 0; i++) {
                octal[i] = num % 8;
                num = num / 8;
            }
            if (aux < 0) {
                printf("-");
            }
            for (int j = i - 1; j >= 0; j--) {
                printf("%d", octal[j]);
            }
            break;

        case 4:
            for (i = 0; num > 0; i += 4) {
                int digitos = num % 10;
                for (int j = 0; j < 4; j++) {
                    bcd[i + j] = digitos % 2;
                    digitos /= 2;
                }
                num /= 10;
            }
            if (aux < 0) {
                printf("-");
            }
            for (int k = i - 1; k >= 0; k--) {
                printf("%d ", bcd[k]);
            }
            break;
        case 5:
            break;
    }

    return 0;
}
