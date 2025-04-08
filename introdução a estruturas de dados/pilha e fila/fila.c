#include <stdio.h>
#include <stdlib.h>
#define N 50


typedef struct fila Fila;
struct fila {
    int n;
    int ini;
    float vet[N];
};

typedef struct fila Fila2;
struct fila2 {
    int n;
    int ini;
    int fim; 
    float vet[N];
};

Fila* fila_cria(void);
void fila_insere(Fila* f, float v );
float fila_retira(Fila* fila);
int fila_vazia(Fila *f);
void fila_libera(Fila* f);

Fila* fila_cria(void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    f->ini = 0;
    return f;

}

void fila_insere(Fila* f, float v)
{
    int fim; 
    if (f->n == N) {
        printf("Capacidade da fila estorou\n");
        exit(1);

    }

    fim = (f->ini + f->n) % N;
    f->vet[fim] = v;
    f->n++;

}

float fila_retira(Fila* f )
{
    float v; 
    if (fila_vazia(f)){
        exit(1);
    }
    v = f->vet[f->ini];
    f->ini = (f->ini + 1) % N;
    f->n--;
    return v;
}

void fila_libera(Fila *f)
{
    free(f);
}


Fila2* fila2_cria(void);
void fila2_insere_ini(Fila2* f, float v);
void fila2_insere_fim(Fila2* f, float v);
float fila2_retira_ini(Fila2* f);
float fila2_retira_fim(Fila2* f);
int fila2_vazia (Fila2* f);
void fila2_libera(Fila2* f);

float fila2_retira_fila ();

int main(){


    
}