#include <stdio.h>

int fact(int n)
{ if (n==0){return 1;}
    int f= fact(n-1);
    int ans= f*n;
    return ans;
}

int main()
{int n=0;
    scanf("%d", &n);
    printf("%d", fact(n));
    return 0;
}