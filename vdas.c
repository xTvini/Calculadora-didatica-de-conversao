/*
Nome: Vinicius Diniz Amorim Simões;
data de início: 21/08/24 12:10;
data de termino: 25/04/2024 17:57;
Email: vdas@cesar.school;

Mudanças:
1- 21/08/24 12:30 - Binário;
2- 21/08/24 12:36 - Hexal;
3- 21/08/24 12:44 - Octal;
4- 21/08/24 16:04 - BCD, e correção de falhas no codigo;
5- 24/08/24 18:26 - Correção do codigo;
6- 25/08/24 12:15 - Complemento a 2;
7- 25/08/24 17:47 - decimal pra float e pra double;
8- 25/08/24 17:57 - Read.me;

Instruções: 

Construa uma calculadora programador didática,  implementada na linguagem C, que tenha as seguintes conversões
1 - de base 10 para:✅
a)base 2,✅ caso 1 
b) base 8,✅ caso 2 
c) base16, ✅ caso 3 
d) código BCD✅ caso 4

2 - de base 10  para base com sinal com 16 bits, (complemento a 2)✅ caso 5
3 - converter real em decimal para float e double, mostrando os respectivos bits de sinal , expoente, expoente com viés e fração ✅
                                    ⮩caso 6✅  ⮩caso 7✅
OBS: deve ser entregue o executável com as iniciais do email e link do git com código.  
A cada questão implementada deve ser feito um commit no git . 
O codigo fonte deve conter um cabeçalho dos dados do autor e  revisões/ atualizações com datas e hora

*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int binario[32], hexal[32], octal[32], bcd[32], num, op;
    unsigned int complemento;
    unsigned int mascara;
    int i, j;

    scanf("%d", &op);

    switch (op) {
        case 1:
            scanf("%d", &num);
            if (num < 0) {
                num = abs(num);
            }
            i = 0;
            while (num > 0) {
                binario[i++] = num % 2;
                num /= 2;
            }
            for (j = i - 1; j >= 0; j--) {
                printf("%d", binario[j]);
            }
            break;

        case 2:
            scanf("%d", &num);
            if (num < 0) {
                num = abs(num);
            }
            i = 0;
            while (num > 0) {
                hexal[i++] = num % 16;
                num /= 16;
            }
            for (j = i - 1; j >= 0; j--) {
                printf("%X", hexal[j]);
            }
            break;

        case 3:
            scanf("%d", &num);
            if (num < 0) {
                num = abs(num);
            }
            i = 0;
            while (num > 0) {
                octal[i++] = num % 8;
                num /= 8;
            }
            for (j = i - 1; j >= 0; j--) {
                printf("%d", octal[j]);
            }
            break;

        case 4:
            scanf("%d", &num);
            if (num < 0) {
                num = abs(num);
            }
            i = 0;
            while (num > 0) {
                int digitos = num % 10;
                for (j = 0; j < 4; j++) {
                    bcd[i + j] = digitos % 2;
                    digitos /= 2;
                }
                num /= 10;
                i += 4;
            }
            for (j = i - 1; j >= 0; j--) {
                printf("%d ", bcd[j]);
            }
            break;

        case 5:
            scanf("%d", &num);
            complemento = (num < 0) ? (~(-num) + 1) & 0xFFFF : (unsigned int)num;
            mascara = 1 << 15;
            for (i = 0; i < 16; i++) {
                printf("%c", (complemento & mascara) ? '1' : '0');
                mascara >>= 1;
            }
            break;

        case 6: {
            float floatNum;
            union {
                float f;
                unsigned int bits;
            } floatUnion;

            scanf("%f", &floatNum);
            floatUnion.f = floatNum;

            unsigned int sinal = (floatUnion.bits >> 31) & 1;
            unsigned int expoente = (floatUnion.bits >> 23) & 0xFF;
            unsigned int fracao = floatUnion.bits & 0x7FFFFF;

            printf("Float: %f\n", floatNum);
            printf("Sinal: %u\n", sinal);
            printf("Expoente: %u\n", expoente);
            printf("Expoente com viés: %d\n", expoente - 127);
            printf("Fração: %u\n", fracao);
            break;
        }

        case 7: {
            double doubleNum;
            union {
                double d;
                unsigned long long bits;
            } doubleUnion;

            scanf("%lf", &doubleNum);
            doubleUnion.d = doubleNum;

            unsigned long long sinal = (doubleUnion.bits >> 63) & 1;
            unsigned long long expoente = (doubleUnion.bits >> 52) & 0x7FF;
            unsigned long long fracao = doubleUnion.bits & 0xFFFFFFFFFFFFF;

            printf("Double: %lf\n", doubleNum);
            printf("Sinal: %llu\n", sinal);
            printf("Expoente: %llu\n", expoente);
            printf("Expoente com viés: %lld\n", expoente - 1023);
            printf("Fração: %llu\n", fracao);
            break;
        }

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
