#include<stdio.h>

typedef struct
{
    double weight;
    double value;
    double ratio;
} item;

int partition(item items[], int lb, int ub);
void quick(item items[], int lb, int ub);
double knapsack(item items[], int n, double cap);

int main()
{
    int n; printf("Enter no. of items: "); scanf("%d", &n);
    item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i=0; i<n; i++)
    {
        printf("For item %d: ", i+1);
        scanf("%lf %lf", &items[i].weight, &items[i].value);
        items[i].ratio = items[i].value / items[i].weight;
    }

    quick(items, 0, n-1);
    double cap; printf("Enter capacity: "); 
    scanf("%lf", &cap);

    printf("Max value: %lf\n", knapsack(items, n, cap));
    return 0;
}

int partition(item items[], int lb, int ub)
{
    double pivot = items[ub].ratio;
    int i = lb-1;

    for (int j=lb; j<ub; j++)
    {
        if (items[j].ratio >= pivot)
        {
            i++;
            item temp = items[i];
            items[i] = items[j];
            items[j] = temp;
        }
    }

    item temp = items[i+1];
    items[i+1] = items[ub];
    items[ub] = temp;

    return i+1;
}

void quick(item items[], int lb, int ub)
{
    if (lb<ub)
    {
        int loc = partition(items, lb, ub);
        quick(items, lb, loc-1);
        quick(items, loc+1, ub);
    }
}

double knapsack(item items[], int n, double cap)
{
    double value = 0;
    double currWeight = 0;

    for (int i=0; i<n; i++)
    {
        if (items[i].weight + currWeight <= cap)
        {
            currWeight += items[i].weight;
            value += items[i].value;
        }
        else 
        {
            double remain = cap - currWeight;
            value += items[i].value*(remain/items[i].weight);
            break;
        }
    }

    return value;
}