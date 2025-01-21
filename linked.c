#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;
void insp();
void search();
void del();
void print();

int main()
{
    int ch;

    printf("1: Insert at a given position\n2: Delete an element\n3: Search for an element\n4: Display the list\n5: End operation\n"); int n, i, x;

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        if (ch == 5) {break;}
        switch(ch)
        {
            case 1: insp(); break;
            case 2: del(); break;
            case 3: search(); break;
            case 4: print(); break;
            default: printf("Invalid choice!\n");
        }
    }

    printf("Thanks!\n");

    return 0;
}


// void insp()
// {
//     int n, p, c=1;
//     printf("Enter the element to be inserted and its position: ");
//     scanf("%d%d", &n, &p);

//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = n;

//     if (head == NULL || p == 1)
//     {
//         temp->next = head;
//         head = temp;
//     }
//     else
//     {
//         struct Node* prev = head;
//         struct Node* nex = prev->next;
//         int possible = 1;
        
//         while (c<p || nex->next != NULL)
//         {
//             if (prev->next == NULL)
//             {
//                 possible = 0;
//                 printf("Out of bounds!\n");
//                 break;
//             }
//             else if (c==p) {break;}
//             prev = nex;
//             nex = nex->next;
//             c++;
//         }

//         if (possible)
//         {
//             prev->next = temp;
//             temp->next = nex;
//         }
//     }
// }

// void del()
// {
//     if (head == NULL)
//     {
//         printf("No list is created!\n");
//         return;
//     }
//     else
//     {
//         int n; printf("Enter the element to be deleted :");
//         scanf("%d", &n);

//         if (head->data == n)
//         {
//             struct Node* t = head;
//             head = head->next;
//             free(t);
//         }
//         else
//         {
//             struct Node* p = head, *t = head->next, *nex;
//             nex = t->next;

//             while (t->data != n)
//             {
//                 p = t;
//                 t = nex;
//                 nex = nex->next;
//             }

//             p->next = nex;
//             free(t);
//         }
//     }
// }

// void search()
// {
//     if (head ==  NULL)
//     {
//         printf("No list is created!\n");
//         return;
//     }
//     else
//     {
//         int n, p=1, is_absent=1; printf("Enter the element to be searched: ");
//         scanf("%d", &n);
//         struct Node* t = head;

//         while (t->next != NULL)
//         {
//             if (t->data == n)
//             {
//                 is_absent = 0;
//                 printf("The element '%d' is at index %d.\n", n, p);
//                 break;
//             }
//             t = t->next;
//             p++;
//         }

//         if (is_absent)
//         {
//             printf("The element is not present in the list!\n");
//         }
//     }
// }

// void print()
// {
//     if (head == NULL)
//     {
//         printf("No list is created!\n");
//         return;
//     }

//     struct Node* temp = head;
//     printf("The list is: ");
//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

void insp()
{
    int n, p;
    printf("Enter the element and the position it should be inserted at: ");
    scanf("%d%d", &n, &p);

    Node *temp =(Node*)calloc(1, sizeof(Node));

    temp->data = n;

    if (p == 1)
    {
        temp->next = head;
        head = temp;
    }
    else 
    {
        int i = 1;

        Node *ptr = head;

        while (i<p && ptr != NULL)
        {
            if (ptr->next == NULL)
            {
                break;
            }

            ptr = ptr->next;
            i++;
        }

        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void del()
{
    int n; printf("Enter the element to be deleted: ");
    scanf("%d", &n);

    Node *ptr = head;

    if (ptr->data == n)
    {
        head = ptr->next;
        free(ptr);
    }
    else
    {
        Node *temp;
        while (ptr->data != n)
        {
            if (ptr == NULL)
            {
                printf("Out of bounds!\n"); return;
            }

            temp = ptr;
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        free(ptr);
    }
}

void search()
{
    int n; printf("Enter the element to be searched: ");
    scanf("%d", &n);

    Node *ptr = head;
    int p = 1;

    while (ptr->next != NULL)
    {
        if (ptr->data == n)
        {
            printf("The element %d is at index no. %d.\n", n, p);
            return;
        }
        if (ptr->next == NULL)
        {
            printf("Element %d was not found!\n", n);
            return;
        }

        ptr = ptr->next; p++;
    }
}

void print()
{
    print("The list is as follows:\n");
    Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);

        ptr = ptr->next;
    }
    
    printf("NULL\n");
}