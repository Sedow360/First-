#include<stdio.h>
#include<string.h>

typedef struct Student
{
    char name[20]; int roll; char dept[10];
} stu;
int main()
{
    FILE *f;
    f=fopen("Student.txt", "w");

    printf("Enter the number of students in class: "); int n; scanf("%d", &n);
    stu p[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter the date for student no. %d:\n", i+1);
        printf("Name: ");
        fgets(p[i].name, sizeof(p[i].name), stdin);
        p[i].name[strcspn(p[i].name, "\n")]='\0';
        printf("Roll no.: "); scanf("%d", &p[i].roll);
        printf("Department: ");
        fgets(p[i].dept, sizeof(p[i].dept), stdin);
        p[i].dept[strcspn(p[i].dept, "\n")]='\0';
    }

    fclose(f);

    return 0;
}