#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *left, *right;
};

struct node *root = NULL;

// Function to create a new node
struct node* create(int d) {
    if (d == -1) {
        return NULL;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = d;
    new_node->left = new_node->right = NULL; // Initialize left and right pointers
    return new_node;
}

// Function to insert an element into the BST
struct node* insert(int n, struct node *t) {   
    if (t == NULL) {
        return create(n);
    }
    if (n < t->data) {
        t->left = insert(n, t->left);
    } else if (n > t->data) {
        t->right = insert(n, t->right);
    }
    return t; // Return the unchanged node pointer
}

// Function to search for an element in the BST
int search(int n, struct node *t) {
    if (t == NULL) {
        return 0; // Not found
    }
    if (n == t->data) {
        return 1; // Found
    } else if (n < t->data) {
        return search(n, t->left);
    } else {
        return search(n, t->right);
    }
}

// Function to find the minimum value node in the BST
struct node* find_min(struct node* t) {
    while (t->left != NULL) {
        t = t->left;
    }
    return t;
}

// Function to delete an element from the BST
struct node* delete(int n, struct node *t) {
    if (t == NULL) {
        printf("Element not found!\n");
        return t;
    }
    
    if (n < t->data) {
        t->left = delete(n, t->left);
    } else if (n > t->data) {
        t->right = delete(n, t->right);
    } else {
        // Node with only one child or no child
        if (t->left == NULL) {
            struct node *temp = t->right;
            free(t);
            return temp;
        } else if (t->right == NULL) {
            struct node *temp = t->left;
            free(t);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = find_min(t->right);
        t->data = temp->data; // Copy the inorder successor's content to this node
        t->right = delete(temp->data, t->right); // Delete the inorder successor
    }
    return t;
}

// Function for inorder traversal of the BST
void inorder(struct node* t) {
    if (t == NULL) {
        return; // Simply return if the node is NULL
    }
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

int main() {
    int ch, n;
    printf("1. Insert an element\n2. Delete an element\n3. View the tree\n4. Exit");
    while (1) {
        printf("\nChoose: "); 
        scanf("%d", &ch);
        if (ch == 4) {
            break;
        }
        switch (ch) {
            case 1: 
                printf("Enter the element: ");
                scanf("%d", &n); 
                if (search(n, root)) {
                    printf("No duplicates are allowed!\n");
                } else {
                    root = insert(n, root); // Update the root
                }
                break;
            case 2: 
                printf("Enter the element: ");
                scanf("%d", &n); 
                root = delete(n, root); // Update the root after deletion
                break;
            case 3: 
                printf("The tree in inorder traversal is as follows:\n");
                inorder(root);
                printf("\n"); // Print a newline for better formatting
                break;
            default: 
                printf("Invalid Choice!\n");
                break;
        }
    }

    printf("Thank you!\n");
    return 0;
}