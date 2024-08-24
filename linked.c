#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void ins();
void insp();
void search();
void del();
void print();

int main()
{
    int ch;

    printf("1: Insert an element in the end\n2: Insert at a given position\n3: Delete an element\n4: Search for an element\n5: Display the list\n6: End operation\n"); int n, i, x;

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: ins(); break;
            case 2: insp(); break;
            case 3: del(); break;
            case 4: search(); break;
            case 5: print(); break;
        }

        if (ch == 6) {break;}
    }

    printf("Thanks!\n");

    return 0;
}

void ins()
{
    printf("Enter the element: "); int n;
    scanf("%d", &n);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;

    if (head == NULL) {head = temp; return;}

    struct Node* s = head;

    while (s->next != NULL)
    {
        s = s->next;
    }

    s->next = temp;
}

void insp()
{
    int n, p, c=1;
    printf("Enter the element to be inserted and its position: ");
    scanf("%d%d", &n, &p);

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;

    if (head == NULL || p == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct Node* prev = head;
        struct Node* nex = prev->next;
        int possible = 1;
        
        while (c<p || nex->next != NULL)
        {
            if (prev->next == NULL)
            {
                possible = 0;
                printf("Out of bounds!\n");
                break;
            }
            else if (c==p) {break;}
            prev = nex;
            nex = nex->next;
            c++;
        }

        if (possible)
        {
            prev->next = temp;
            temp->next = nex;
        }
    }
}

void del()
{
    if (head == NULL)
    {
        printf("No list is created!\n");
        return;
    }
    else
    {
        int n; printf("Enter the element to be deleted :");
        scanf("%d", &n);

        if (head->data == n)
        {
            struct Node* t = head;
            head = head->next;
            free(t);
        }
        else
        {
            struct Node* p = head, *t = head->next, *nex;
            nex = t->next;

            while (t->data != n)
            {
                p = t;
                t = nex;
                nex = nex->next;
            }

            p->next = nex;
            free(t);
        }
    }
}

void search()
{
    if (head ==  NULL)
    {
        printf("No list is created!\n");
        return;
    }
    else
    {
        int n, p=1, is_absent=1; printf("Enter the element to be searched: ");
        scanf("%d", &n);
        struct Node* t = head;

        while (t->next != NULL)
        {
            if (t->data == n)
            {
                is_absent = 0;
                printf("The element '%d' is at index %d.\n", n, p);
                break;
            }
            t = t->next;
            p++;
        }

        if (is_absent)
        {
            printf("The element is not present in the list!\n");
        }
    }
}

void print()
{
    if (head == NULL)
    {
        printf("No list is created!\n");
        return;
    }

    struct Node* temp = head;
    printf("The list is: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}