#include <stdio.h>
#include <stdlib.h>

void intercala(int* n, int c, int meio, int f)
{
    int i, k;
    int tam = f - c + 1; //tamanho do vetor atual
    int lim1 = 0, lim2 = 0; //flags que verifica se os vetores já foram completamente passados ao auxiliar
    int c1 = c; // começo do vetor 1
    int c2 = meio+1; //começo do vetor 1
    int *aux = (int*)malloc(tam*sizeof(int)); //vetor auxiliar que recebera os valores ordenados

    for(i = 0; i < tam; i++)
    {
        if(!lim1 && !lim2)//se nenhum dos vetores foi completamente passado para o vetor auxiliar, então...
        {
            if(n[c1] > n[c2]){aux[i] = n[c2]; c2++;} //se o elemento atual do vetor 1 for maior que o elemento atual do vetor 2 então o valor do deste é colocado no vetor auxiliar
            else{aux[i] = n[c1]; c1++;}//caso contrário, o vetor auxiliar recebe o valor do elemento atual do vetor 1
            if(c1 > meio){lim1 = 1;}//se o indice do elemento atual do vetor 1 for maior que o indice 'meio', então o vetor 1 foi completamento passado para o vetor auxiliar
            if(c2 > f){lim2 = 1;}//se indice do elemento atual do vetor 2 for maior que o indice 'f', então o vetor 2 foi completamente passado para o vetor auxiliar
        }else{ //caso algum dos tenha chegado ao fim (completamento passado ao vetor auxiliar), então
            if(!lim1){aux[i] = n[c1]; c1++;} //se o vetor 1 ainda não acabou, o resto do vetor auxiliar será preenchico pelo restante do vetor 1
            else{aux[i] = n[c2]; c2++;}//se o vetot 2 ainda não acabou, o resto do vetor 2 será copiado para o vetor auxiliar
        }
    }
    for(i = 0, k = c; i < tam; i++, k++)//após o vetor auxiliar ser completo, passaremos ele para o vetor original
    {
        n[k] = aux[i];
    } 

    free(aux);
}

void merge(int* n, int c, int f)
{
    int meio;
    if(c < f)
    {
        meio = (c + f)/2;
        merge(n, c, meio);
        merge(n, meio+1, f);
        intercala(n, c, meio, f);
    }
}

int main()
{
    int num, i;

    printf("...enter the size of array to ordered\n");
    scanf("%d", &num);

    int *n = (int*)malloc(num*sizeof(int));
    printf("....enter the values of the array elements\n");
    for(i = 0; i < num; i++){scanf("%d", &n[i]);}
    
    merge(n, 0, num-1); //o vetor, o começo e o fim

    for(i = 0; i < num; i++){printf("- %d", n[i]);}

    return 0;
}