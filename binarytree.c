#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node into the binary tree (Linked List)
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    struct Node* temp;
    struct Node* newNode = createNode(data);
    struct Node* queue[100];
    int front = 0;
    int rear = -1;

    queue[++rear] = *root;

    while (front <= rear) {
        temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            queue[++rear] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            queue[++rear] = temp->right;
        }
    }
}

// Inorder Traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder Traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int choice, num, i, n;

    struct Node* root = NULL;

    printf("Enter the number of elements to insert in the binary tree: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(&root, num);
    }

    printf("\nInorder Traversal: ");
    inorderTraversal(root);

    printf("\nPreorder Traversal: ");
    preorderTraversal(root);

    printf("\nPostorder Traversal: ");
    postorderTraversal(root);

    printf("\n");

    return 0;
}
