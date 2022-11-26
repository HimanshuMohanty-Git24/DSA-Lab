#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int search(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct node *buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    struct node *tNode = newNode(pre[preIndex++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void printPostOrder(struct node *node)
{
    if (node == NULL)
        return;

    printPostOrder(node->left);

    printPostOrder(node->right);
    printf("%d ", node->data);
}

int main()
{
    int in[] = {1, 2, 4, 5, 3, 6, 7, 9, 8, 10, 13, 12, 11, 14};
    int pre[] = {3, 2, 1, 5, 4, 8, 7, 6, 9, 10, 13, 12, 11, 14};
    int len = sizeof(in) / sizeof(in[0]);
    struct node *root = buildTree(in, pre, 0, len - 1);

    printf("Inorder traversal of the constructed tree is \n");
    printPostOrder(root);
}