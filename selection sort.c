#include <stdio.h>
#include <stdlib.h>

void selection(int num, int* n)
{
    int u, i;
    for(u = 0; u < num - 1; u++)
    {
        int min = n[u];
        int min_pos = u;
        for(i = u+1; i < num; i++)
        {
            if(n[i] < min)
            {
                min = n[i];
                min_pos = i;
            }
        }
        int pass = n[min_pos];
        n[min_pos] = n[u];
        n[u] = pass;
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

    selection(num, n);

    printf("\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d-", n[i]);
    }
    
    return 0;
}