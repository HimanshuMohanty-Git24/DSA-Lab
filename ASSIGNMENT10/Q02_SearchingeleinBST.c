#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *Search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return Search(root->right, key);

    return Search(root->left, key);
}
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert(enter -1 for no node):");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d", x);
    newnode->left = create();
    printf("Enter right child of %d", x);
    newnode->right = create();
    return newnode;
}
void Preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d->", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Preorder(root->left);
    printf("%d->", root->data);
    Preorder(root->right);
}
void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Preorder(root->left);
    Preorder(root->right);
    printf("%d->", root->data);
}
int main()
{
    struct node *root;
    root = NULL;
    printf("\nCreation of Tree !!\n");
    root = create();
    printf("\nPreorder Traversal\n");
    Preorder(root);
    printf("\nInorder Traversal\n");
    Inorder(root);
    printf("\nPostorder Traversal\n");
    Postorder(root);
    struct node *found;
    printf("\nSearching an element\n");
    found = Search(root, 10);
    if (found != NULL)
    {
        printf("\nFound %d !!!\n", found->data);
    }
    else
    {
        printf("\nElement not found\n");
    }
}