#include <stdio.h>
#include <stdlib.h>
int main(void){
    int binario[32], hexal[32], octal[32], bcd[32],num, op;
    scanf("%d", &op);
    scanf("%d", &num);
    int aux= num;
    if(num<0){
        num=abs(num);
    }
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
        case 2:
            for(int i=0;i<32;i++){
                if(num>0){
                    hexal[i] = num%16;
                    num = num/16;
                }else{
                    hexal[i]=0;
                }
            }if(aux<0){
                printf("-");
            }   
            for(int i=31;i>=0;i--){
                printf("%d", hexal[i]);
            }
            break;
        case 3:
            for(int i=0;i<32;i++){
                if(num>0){
                    octal[i]=num%8;
                    num = num/8;
                }else{
                    octal[i]=0;
                }
            }if(aux<0){
                printf("-");
            }
            for(int i=31;i>=0;i--){
                printf("%d", octal[i]);
            }
            break;
        case 4:
            int i = 0;
            while(num>0){
                int digitos = num %10;
                for(int j=0; j<4; j++){
                    bcd[i+j] = digitos%2;
                    digitos/=2;
                }
                i+=4;
                num/=10;
            }if(aux<0){
                printf("-");
            }
            for( int k = i -1; k>=0; k--){
                printf("%d", bcd[k]);
            }
            break;
    }
}