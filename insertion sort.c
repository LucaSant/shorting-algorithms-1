#include <stdio.h>
#include <stdlib.h>

void insertion(int num, int *n)
{
    int i, u;
    for(i = 1; i < num; i++)
    {
        u = 1;
        int cpy = n[i];
        while(cpy < n[i-u])
        {
            n[i-u+1] = n[i-u];
            n[i-u] = cpy;
            if(i - u - 1 < 0){break;}else{u++;}
        }
    }
}

int main()
{
    int num, i;

    printf("...enter the size of array to ordered\n");
    scanf("%d", &num);

    int *n = (int*) malloc(num * sizeof(int));
    printf("....enter the values of the array elements\n");
    for(i = 0; i < num; i++)
    {
        scanf("%d", &n[i]);
    }

    insertion(num, n);

    printf("\n");
    for(i = 0; i < num; i++)
    {
        printf("%d-", n[i]);
    }
    
    return 0;
}