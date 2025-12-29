/* Write a program
a) ToconstructabinarySearchtree.
b) To traverse the tree using all the methods i.e., in-order,
preorder and post order
c) To display the elements in the tree. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

struct node* insert(struct node *root, int x)
{
    if (root == NULL)
        return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}

/* Output:
20 30 40 50 60 70 80
50 30 20 40 70 60 80
20 40 30 60 80 70 50
*/
