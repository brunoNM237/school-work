#include <stdlib.h>
#include <stdio.h>

#define N 50

typedef struct pilha Pilha;


struct pilha {
    int n;
    float vet[N];

};



Pilha* pilha_cria(void);
void pilha_push (Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);


Pilha* pilha_cria (void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

int pilha_vazia (Pilha* p)
{
    return (p->n == 0);
}


void pilha_push(Pilha* p, float v){
    if (p->n == N) {
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

float pilha_pop (Pilha* p)
{
    float v;
    if(pilha_vazia(p)) exit(1);

    v = p->vet[p->n-1];
    p->n--;
    return v;
}


void concatena_pilhas(Pilha* p1 , Pilha* p2 ){
    if (p2->n == 0 ) return p1;
    if (p1->n == 0 ) return p2;
    for(int i = 0; i < p2->n; i++) {
        pilha_push(p1,p2->vet[i]);
    } 
    

}

int main(void){
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();

    pilha_push(p1,2);
    pilha_push(p1,3);
    pilha_push(p2,4);
    pilha_push(p2,5);

    concatena_pilhas(p1,p2);
    for(int i = p1->n-1; i >= 0; i--)
    {
        printf("%f",p1);
    }


    return 0;    
}
