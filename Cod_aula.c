#include <stdio.h>
#include <stdlib.h>
//Código compila, porém não executa exatamente o testcase 2 ( 5,4,4 )
//Não foi feita a fila
//Miguel Botelho -- M1
int main()
{
	

	return (0);
}

int fillCups(int* amount, int amountSize){
int maior = 0;
int menor = 0;
int mid = 0;
int count = 0;
    if ( amount[0] < amount[1] && amount[0] < amount[2] ){
        menor = amount[0];
        if ( amount[1] <= amount[2] ){
            maior = amount[2];
            mid = amount[1];
            
        } else {
            maior = amount[1];
            mid = amount[2];
        }
    } else if ( amount[1] < amount[0] && amount[1] < amount[2] ){
        menor = amount[1];
        if ( amount[0] <= amount[2] ){
            maior = amount[2];
            mid = amount[0];
        } else {
            maior = amount[0];
            mid = amount[2];
        }
    } else {
        menor = amount[2];
        if ( amount[1] <= amount[0] ){
            maior = amount[0];
            mid = amount[1];
        } else {
            maior = amount[1];
            mid = amount[0];
        }
    }
    while ( menor > 0 ) {
        if ( maior > 0) {
            maior--;
            menor--;
            count++;
    }else if ( mid > 0 ){
            menor--;
            mid--;
            count++;
        }
    }
    while ( mid > 0 ){
        maior--;
        mid--;
        count++;
    }
    while ( maior > 0 ){
        maior--;
        count++;
    }
    return count;
}
