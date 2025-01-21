#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int k=0;
        for (int j = 0; j < n; j++)
        { 
            if (k<i) {printf("%d ", n-k); k++;}
            else {printf("%d ", n-k);}
        }
        for (int j = n; j < 2*n-1; j++)
        { 
            if(j>=2*n-i-1) {k--;}
            printf("%d ", n-k);
        }
        printf("\n");
    }
    for (int i = n-1; i > 0; i--)
    {
        int k=0;
        for (int j = 0; j < n; j++)
        { 
            if (k<i-1) {printf("%d ", n-k); k++;}
            else {printf("%d ", n-k);}
        }
        for (int j = n; j < 2*n-1; j++)
        { 
            if(j>2*n-i-1) {k--;}
            printf("%d ", n-k);
        }
        printf("\n");
    }
    
    return 0;
}