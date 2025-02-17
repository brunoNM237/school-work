#include <stdio.h>
#include <stdlib.h>


void print_vetor(int v[], int dim);
void bubble_sort(int v[], int dim);
int med_tres(int v[], int dim, int i);


int main()
{
    int num = 0;
    int *vetor = NULL;
    int size = 0;
    
    scanf("%d",&num);

    while(num != 0)
    {
        if (num < 0){
            scanf("%d",&num);
            continue;
        }

        int *aux = realloc(vetor, (size+1)*sizeof(int));
        if(!aux){
            free(vetor);
            return 1;

        }
        
        vetor = aux;
        vetor[size] = num;
        
        scanf("%d", &num);
        
        size++;
    }
    
    for(int i = 0; i<(size-2); i++){ 
        int mediana = med_tres(vetor, size, i);
        printf("%d\n", mediana);
    }

    
    free(vetor);

    return 0;
}




void bubble_sort(int v[], int dim)
{
    for(int i=0; i< dim-1 ; i++){     
        for(int j=0; j<dim-1-i ; j++){
            if(v[j]>v[j+1]){
                int aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
                
            }
    }
}
}




void print_vetor(int v[], int dim)
{
    for(int i = 0; i<dim; i++){
        printf("%d ",v[i] );
    }
    printf("\n");
}


int med_tres(int v[], int dim, int i)
{
    int aux[3];
    aux[0] = v[i];
    aux[1] = v[i+1];
    aux[2] = v[i+2];
         
    bubble_sort(aux,3);
        
    return aux[1];
}
