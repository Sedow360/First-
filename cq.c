#include <stdio.h>
#include <stdlib.h>

#define N 5 // Maximum size of the queue

int p = 0; // Current number of elements in the queue

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL, *r = NULL;

// Function to create a new node
struct node* create(int n) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = n;
    temp->next = NULL; // Initialize next to NULL
    return temp;
}

// Function to enqueue an element
void enQueue() {
    if (p == N) {
        printf("Maximum limit reached!\n");
        return;
    }
    int n;
    printf("Enter the value: ");
    scanf("%d", &n);

    struct node *t = create(n);
    if (p == 0) { // If the queue is empty
        f = r = t; // Both front and rear point to the new node
        f->next = r; // Point to itself
        r->next = f; // Complete the circular link
    } else {
        r->next = t; // Link the new node to the rear
        t->next = f; // Link the new node to the front
        r = t; // Update the rear pointer
    }
    p++; // Increment the count of elements
}

// Function to dequeue an element
void deQueue() {
    if (p == 0) {
        printf("Underflow!\n");
        return;
    }

    struct node *t = f; // Save the front node
    printf("%d was popped!\n", t->data);

    if (f == r) { // If there's only one element
        f = r = NULL; // Reset both pointers
    } else {
        f = f->next; // Move front to the next node
        r->next = f; // Update rear's next to point to new front
    }

    free(t); // Free the removed node
    p--; // Decrement the count
}

// Function to print the elements of the queue
void print() {
    if (p == 0) {
        printf("Underflow!\n");
        return;
    }

    struct node *t = f; // Start from the front node
    do {
        printf("%d ", t->data);
        t = t->next; // Move to the next node
    } while (t != f); // Continue until we loop back to the front

    printf("\n"); // New line after printing all elements
}

// Main function
int main() {
    int ch;
    printf("1. EnQueue\n2. DeQueue\n3. Print\n4. End\n");

    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &ch) != 1) { // Validate input
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        if (ch == 4) {
            break;
        }
        switch(ch) {
            case 1: enQueue(); break;
            case 2: deQueue(); break;
            case 3: print(); break;
            default: printf("Invalid input!\n"); break;
        }
    }

    // Free all remaining nodes (if any)
    while (p > 0) {
        deQueue();
    }
}
