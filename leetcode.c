#include<stdlib.h>
#include<stdio.h>

void merge(int *nums1, int nums1s, int m, int *nums2, int nums2s, int n)
{
    int a[m+n];

    int i = 0, j = 0, k = 0;

    while (i<m && j<n)
    {
        if (*(nums1+i) < *(nums2+j))
        {
            a[k++] = (*(nums1+i)); i++;
        }
        else
        {
            a[k++] = (*(nums2+j)); j++;
        }
    }

    while (i<m)
    {a[k++] = (*(nums1+i)); i++;}

    while (j<n)
    {a[k++] = (*(nums2+j)); j++;}
    printf("\n");
    for (int x = 0; x < m+n; x++)
    {printf("%d ", a[x]);}
    printf("\n");
}

int main()
{
    int n1s, n2s;
    scanf("%d%d", &n1s, &n2s);

    int *n1, *n2;
    printf("Enter array 1:\n");
    for (int i = 0; i<n1s; i++)
    {scanf("%d", n1+i);}
    printf("Enter array 2:\n");
    for (int j = 0; j<n2s; j++)
    {scanf("%d", n2+j);}
    printf("Enter limits: ");
    int m, n;
    scanf("%d%d", &m, &n);

    merge(n1, n1s, m, n2, n2s, n);
}