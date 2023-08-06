#include <stdio.h>
#include <stdlib.h>

//Miguel Botelho -- M1
typedef struct Queue_t {
    int val;
    struct Queue_t* next;
} Queue_t;

typedef struct sentinel {
    Queue_t* begin;
    Queue_t* end;
} Sentinel;

Sentinel* Create();
void Push( Sentinel* Sentinel, int val );
int fillCups( int* amount, int amountSize );
void FreeQueue( Sentinel* Sentinel );

int main()
{
	int amount1[] = {7,2,3};
    int amountSize1 = sizeof ( amount1 ) / sizeof ( amount1[0] );
    int min = fillCups ( amount1, amountSize1 );
    printf("\nExemplo 1: Quantidade minima de segundos = %d\n", min); //Output = 7

	int amount2[] = {4,4,4};
    int amountSize2 = sizeof ( amount2 ) / sizeof ( amount2[0] );
    int min2 = fillCups ( amount2, amountSize2 );
    printf("\nExemplo 2: Quantidade minima de segundos = %d\n", min2); //Output = 6

	int amount3[] = {3,2,1};
    int amountSize3 = sizeof ( amount3 ) / sizeof ( amount3[0] );
    int min3 = fillCups ( amount3, amountSize3 );
    printf("\nExemplo 3: Quantidade minima de segundos = %d\n", min3); //Output = 3

	return (0);
}

Sentinel* Create() {

    Sentinel* aux = ( Sentinel* )malloc( sizeof ( Sentinel ) );
    aux->begin = NULL;
    aux->end = NULL;
    return aux;

}

void Push(Sentinel* Sentinel, int val) {

    Queue_t* aux = ( Queue_t* )malloc( sizeof ( Queue_t ));
    aux->val = val;
    aux->next = NULL;

    	if ( Sentinel->end == NULL ) {

        	Sentinel->begin = aux;
        	Sentinel->end = aux;
        	return;

    	} else {

    		Sentinel->end->next = aux;
    		Sentinel->end = aux;

    		}
}

int fillCups(int* amount, int amountSize) {
    Sentinel* Sentinel = Create();
    int max = 0;
    int total = 0;
    int seconds = 0;

    	for ( int i = 0; i < amountSize; i++ ) {
        	if ( amount[i] > max ) {
            	max = amount[i];
        	}
        	Push( Sentinel, amount[i] );
        	total = total + amount[i];
    	}

    seconds = ( total + 1 ) / 2;
    	if ( max > seconds ) {
        	seconds = max;
    	}
	FreeQueue ( Sentinel );	
    return seconds;
}

void FreeQueue( Sentinel* Sentinel ) {

    Queue_t* aux = Sentinel->begin;
    	while ( aux != NULL ) {
        	Queue_t* temp = aux;
        	aux = aux->next;
        	free ( temp );
    	}
    free ( Sentinel );
	free ( aux );
}