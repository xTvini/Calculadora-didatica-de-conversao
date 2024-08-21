#include <stdio.h>
#include <stdlib.h>
int main(void){
    int binario[32], hexal[32], octal[32],num, op;
    scanf("%d", &op);
    scanf("%d", &num);
    switch(op){
        case 1:
            for(int i=0;i<32;i++){
                if(num>0){
                    binario[i] = num%2;
                    num = num/2;
                }else{
                    binario[i]=0;
                }
            }
            for(int i=31;i>=0;i--){
                printf("%d", binario[i]);
            }
            break;
        default:
            printf("Inválido\n");
    }
}