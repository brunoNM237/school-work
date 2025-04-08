#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct lista Lista;
typedef struct lista2 Lista2;



struct lista {
    int info;
    struct lista* prox;

};

struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
};


Lista* lst_cria(void){
    return NULL;
}

//entender melhor por que eu preciso do return novo na primeira função
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l; 
    return novo;
}

void lst_insere2(Lista** l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = *l;
    *l = novo;
}

Lista* copia(Lista* l){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    Lista* p = l;
    for(p; p!= NULL; p = p->prox){
        
    }

    return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for(p = l; p != NULL; p = p->prox) printf("info = %d\n", p->info);

}

int lst_vazia(Lista* l){
    if (l == NULL){
        return 1;
    } else {
        return 0;
    }
}


Lista* lst_busca(Lista* l, int v)
{
    Lista* p;
    for(p = l; p !=NULL; p = p->prox){
        if (p->info == v) {
            return p;
        }
    
    }
    return NULL;
}

Lista* lst_retira(Lista* l, int v)
{
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }

    if (p == NULL) return l;

    if(ant == NULL) {
        l = l->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}


void libera_lst(Lista* l)
{
    Lista* p = l;
    for (p; p!= NULL; p = p->prox) {

        Lista* t = p->prox;
        free(p);
        p = t; 
    }


} 



Lista* lst_insere_ordenado(Lista* l, int v)
{
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;


    if (ant == NULL) {
        novo->prox = l;
        l = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;


    }
    return l;

}


int lst_igual(Lista* l1, Lista* l2)
{

    if (l1 == NULL && l2 == NULL) return 1;
    else if (l1 == NULL || l2 == NULL) return 0;
    else return l1->info == l2->info && lst_igual(l1->prox, l2->prox); 

}




//Lista duplamente encadeada 2 
Lista2* lst2_insere (Lista2* l, int v)
{
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;

    if (l!= NULL) l->ant = novo;
    return novo;
}

Lista2* lst2_busca(Lista2* l, int v){
    Lista2* p;
    for(p =l; p!= NULL; p = p->prox){
        if (v == p->info) return p;
    }
    return NULL;
}



Lista2 insere(Lista2* l, int v){
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v; 
    novo->prox = l;
    if (l == NULL) l->ant = NULL; 
    
    l->ant = novo;
    l = novo;


}
Lista2* remove(Lista2* l, int v)
{
    Lista2* p = l;
    Lista2* ant1 = NULL;
    
    while (p!= NULL && p->info != v){
       
        p = p->prox;

    }

    if (p ==NULL) return NULL;
    else {
        if (ant1 == NULL) return l;
        ant1->prox = p->prox;
        (ant1->prox)->ant = ant1;

    }
    return l;

}
//EXERCICIOS LISTA ENCADEADA
//2.1 
int comprimento (Lista* l){
    int tam = 0;
    Lista* p = l;
    while (p!= NULL) {
        p = p->prox;
        tam++;
    }
    return tam;
}
//2.2

int maiores(Lista* l, int n){
    int maiores = 0; 
    Lista* p = l;
    while (p!= NULL) {
        if (p->info > n){
            maiores++;
        }
        p = p->prox;
        
    }
    return maiores;
}

//2.3

Lista* ultimo (Lista* l){
    Lista* p = l;
    while (p->prox!= NULL){
        p = p->prox;

    }
    return p;
}   

//2.4

Lista* concatena(Lista* l1, Lista* l2){
    if (l1 ==NULL) return l2;
    Lista* p = ultimo(l1);
    p->prox = l2;
    return l1;



}
//2.5
Lista* retira_n (Lista* l, int n){
    Lista* p = l;
    Lista* ant = NULL;

    while( p != NULL)
    {
        if (p->info == n) {
            Lista* temp = p;

            if (ant == NULL) {
                l = p->prox;
            } else {
                ant->prox = p->prox;
            }

            p = p->prox;
            free(temp);

        } else {
            ant = p;
            p = p->prox;
        }
        
    }
    return l;
}


//2.6
Lista* separa(Lista* l, int n){
    Lista* ant = NULL;
    Lista* p = l;
    if (l == NULL) return NULL;
    while(p->info != n  && p != NULL){
        ant = p;
        p = p->prox;

    }
    if (p == NULL) return NULL;
    if (ant == NULL) {
        l= NULL;
    } else {
        ant->prox = NULL;
    }
    return p;
}

//2.7
Lista* merge(Lista* l1, Lista* l2){
    Lista* p = l1;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    while(p->prox != NULL) p = p->prox; 
    p->prox = l2;
    return l1;


}


//2.8
Lista* inverte(Lista* l){
    Lista* p = l;
    Lista* p2 = NULL;
    Lista* ant = NULL;
    int primeiro = 1;
   
    
    if (l == NULL) return NULL;
    while(p!= NULL)
    {
        
        ant = p;
        p = p->prox;
    
        if (primeiro) {
            ant->prox = NULL;
            p2 = ant;
            primeiro = 0;
            
        } else {
            
            ant->prox = p2;
            p2 = ant;
        }
        
    }
   
    if (p ==NULL) return NULL;
    if (ant == NULL) return p;

    free(p2);
    return ant;
}

//2.9
typedef struct lista_string Lista_string;

struct lista_string {
    char* info;
    Lista_string* prox; 
};

int igual(Lista_string* l1, Lista_string* l2) {
    if (l1 == NULL && l2 == NULL) return 1;
    else if (l1 == NULL || l2 == NULL) return 0;
    else  return ( strcmp(l1->info,l2->info) && igual(l1->prox, l2->prox));

}


//p2 questão 2;

Lista* constroi(int n, int* v){
    Lista* lst = lst_cria();
    for(int i = n -1; i >= 0; i--) {
        lst = lst_insere(lst, v[i]);
    }
    return lst;



}



