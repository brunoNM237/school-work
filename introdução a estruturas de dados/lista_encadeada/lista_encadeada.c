#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
Lista2* remove_ele(Lista2* l, int v)
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



int comprimento (Lista* l){
    int tam = 0;
    Lista* p = l;
    while (p!= NULL) {
        p = p->prox;
        tam++;
    }
    return tam;
}


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
Lista* ultimo (Lista* l){
    Lista* p = l;
    if (l == NULL) return NULL;
    while (p->prox!= NULL){
        p = p->prox;

    }
    return p;
}   



Lista* concatena(Lista* l1, Lista* l2){
    if (l1 == NULL) return NULL;
    Lista* p = ultimo(l1);
    p->prox = l2;
    return l1;



}


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

Lista* merge(Lista* l1, Lista* l2){
    Lista* p = l1;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    while(p->prox != NULL) p = p->prox; 
    p->prox = l2;
    return l1;


}


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
   
    if (ant == NULL) return l;

    
    return ant;
}



//p2 questão 2;

Lista* constroi(int n, int* v){
    Lista* lst = lst_cria();
    for(int i = n -1; i >= 0; i--) {
        lst = lst_insere(lst, v[i]);
    }
    return lst;



}

// Lista* intersecao (Lista *L1, Lista *L2){
//     Lista* novo = NULL;
//     Lista* p1 = L1;
//     Lista* p2 = L2;
//     int i = 0;
//     if (comprimento(L1) > comprimento(L2)) {
//         int* vetor_intersecao = (int* ) malloc(sizeof(int));
//         for(p1; p1 !=NULL; p1 = p1->prox){
//             for(p2; p2 !=NULL; p2 = p2->prox){
//                 if (p1->info == p2->info &&) 
//                     novo = lst_insere(novo,p1->info);
//                     vetor_intersecao[i] = p1->info;
//                     i++;
//             }
//         }
//     } else {

//     }

// }

Lista* insere_n(Lista* l, int n) {
    Lista* novo = NULL;
    Lista* ant = NULL;
    Lista* p = l;

    int i = 0;


    while (i != n && p != NULL) {
        ant = p;
        p = p->prox;
        i++;
    }
    if (p == NULL) return l;
    if (ant == NULL) return l;

    novo->info = p->info;
    novo->prox = l;
    ant->prox = p->prox;
    return novo;

}


int main(void) {
    Lista* l; 
    l = lst_cria();
    l = lst_insere(l,23);
    l = lst_insere(l,45);
    l = lst_insere_ordenado(l,32);
    l = lst_insere(l,58);
    lst_imprime(l);

    l = insere_n(l, 2);
    lst_imprime(l);
    // Lista* l2;
    // l2 = lst_cria();
    // l2 = lst_insere(l2,23);
    // Lista* l3 = concatena(l,l2);
    
    
    // Lista* l4 = separa(l3,45);
    
    // printf("L3: \n");
    // lst_imprime(l3);
    // printf("\n");
    
    // printf("L4: \n");
    
    // lst_imprime(l4);
    // printf("\n");
   
    
    // printf("L5: \n");
    // Lista* l5 = merge(l3,l4);
    // lst_imprime(l5);
    // printf("\n");


    // Lista* l5_invertida = inverte(l5);
    // printf("L5 invertida: \n");
    // lst_imprime(l5_invertida);
    
    // l5_invertida = inverte(l5_invertida);
    // printf("\n");
    
    // printf("L5 duplamente invertida: \n");
    // lst_imprime(l5_invertida);

    // printf("\n");
    
    // int v[5] = {3,8,1,7,2};
    // Lista* lst = constroi(5, v);
    // lst_imprime(lst);

    


    return 0;
}

