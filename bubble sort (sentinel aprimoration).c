#include <stdio.h>
#include <stdlib.h>

void bubble(int num, int *n){
    while(1){
        int range = num - 1;
        //range is the number of comparations, its starts as the size of the array less one.
        int count = 0;
        int s;
        for(int i = 0; i < range; i++){
            if(n[i] > n[i+1]){
                int pass;
                pass = n[i+1];
                n[i+1] = n[i];
                n[i] = pass;
                s = i; //sentinel 
            }else{count++;}
        }
        if(count == range){break;}else{range = s;}       
    }
}

int main(){   
    int num, i;

    printf("...enter the size of array to be ordered\n");
    scanf("%d", &num);

    int *n = (int*) malloc(num * sizeof(int));
    printf("\n...enter the values of the array elements\n");
    for(i = 0; i < num; i++){
        scanf("%d", &n[i]);
    }
    
    bubble(num, n);

    printf("\n");
    for (int i = 0; i < num; i++){
        printf("%d-", n[i]);
    }
    
    return 0;
}