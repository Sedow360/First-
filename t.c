#include <stdio.h>
#include <string.h>

typedef struct addressOfpeople
{
    int hn; char block[10], city[10], state[10];
} add;

void salt(char a[])
{
    char salt[]= "123"; char new[strlen(a)];
    strcpy(new, a);
    printf("Your salted password is:");
    puts(strcat(new, salt));
}

void slice(char a[], int n, int m)
{
    char new[m-n+1];
    for (int i=n, j=0; i<=m; i++, j++)
    {
        new[j]=a[i];
    }
    printf("%s", new);
}

int main()
{
    //char a[50]; scanf("%s", a);
    //int n, m; scanf("%d %d", &n, &m);
    //salt(a);
    //slice(a, n, m);
    add p[5];
    for (int i=0; i<5; i++)
    {
        printf("Enter the following details:\nHpuse no. of person no. %d: ", i+1);
        scanf("%d", &p[0].hn);
        printf("Block of person no. %d: ", i+1); scanf("%s", p[i].block);
        printf("City of person no. %d: ", i+1); scanf("%s", p[i].city);
        printf("State of person no. %d: ", i+1); scanf("%s", p[i].state);
    }

    for (int j=0; j<5; j++)
    {
        printf("Address of person no. %d are :\nHouseno.: %d\n", j+1, p[j].hn);
        printf("Block: %s\n", p[j].block);
        printf("City: %s\n", p[j].city);
        printf("State: %s\n", p[j].state);
    }

    return 0;
}