#include<stdio.h>

typedef struct 
{
    float profit; int deadline;
}job;

void bubble(job jobs[], int lb, int ub)
{
    for (int i = lb; i<ub; i++)
    {
        for (int j = i; j<ub-1-i; j++)
        {
            if (jobs[j].profit < jobs[j+1].profit)
            {
                job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }

    printf("Sorted list:\nDeadline \tProfit\n");
    for (int k =lb; k<ub; k++)
    {
        printf("%d \t%f\n", jobs[k].deadline, jobs[k].profit);
    }
}

float sequencing(job jobs[], int max, int lb, int ub, int done[])
{
    float maxP = 0;

    for (int d = 1; d<=max; d++)
    {
        for (int i=lb; i<ub; i++)
        {
            if (jobs[i].deadline>=d && !done[i])
            {
                printf("Job %d done.\n", i+1);
                done[i] = 1;
                maxP += jobs[i].profit;
                break;
            }
        }
    }

    return maxP;
}

int main()
{
    int n; printf("No. of jobs: ");
    scanf("%d", &n);
    job jobs[n]; int max=0, done[n];

    printf("Enter deadline and profit for\n");
    for (int i=0; i<n; i++)
    {
        printf("job %d: ", i+1);
        scanf("%d %f", &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > max)
        {
            max = jobs[i].deadline;
        }
        done[i] = 0;
    }

    bubble(jobs, 0, n);

    printf("Max profit: %f", sequencing(jobs, max, 0, n, done));
    return 0;
}