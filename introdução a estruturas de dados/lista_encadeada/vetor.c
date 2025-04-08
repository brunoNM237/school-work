#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vetor Vetor;

struct vetor {
    int x;
    int y; 
    int z; 
    


};





Vetor* cria_vetor(float x, float y, float z){
    Vetor* vetor = (Vetor*) malloc(sizeof(Vetor));
    vetor->x = x;
    vetor->y = y;
    vetor->z = z;
    return vetor;
}


void libera(Vetor* v){
    free(v);
}

Vetor* soma(Vetor* v1, Vetor* v2){
    Vetor* v_soma = (Vetor*) malloc(sizeof(Vetor));
    v_soma->x = v1->x + v2->x;
    v_soma->y = v1->y + v2->y;
    v_soma->z = v1->z + v2->z;
    return v_soma;

};


struct aluno { char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3; };
    typedef struct aluno Aluno;

    


Aluno* cria(const char* nome,const char* matricula, char turma, float p1, float p2 , float p3){
    Aluno* aluno1 = (Aluno*) malloc(sizeof(Aluno));
    strcpy(aluno1->nome, nome);
    strcpy(aluno1->matricula, matricula);
    
    aluno1->p1 = p1;
    aluno1->p2 = p2;
    aluno1->p3 = p3;


}


int main(){
    Aluno** Turmas = (Aluno**) malloc(sizeof(Aluno));

    Aluno* aluno1 = cria('bruno', '1000', 'A', 10,7,9);
    Turmas[0] = aluno1;


    return 0;
}
