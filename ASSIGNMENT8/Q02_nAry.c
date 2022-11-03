#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *firstchild;
    struct node *secondchild;
    struct node *thirdchild;
    struct node *fourthchild;
    struct node *fifthchild;
    struct node *sixthchild;
};
struct node *setData(struct node *root)
{
    root->firstchild = setData(12);
    root->secondchild = setData(22);
    root->thirdchild = setData(23);
    root->fourthchild = setData(74);
    root->fifthchild = setData(25);
    root->sixthchild = setData(45);
    return root;
};

void display(struct node *root)
{

    printf("%d\t", root->firstchild);
    printf("%d\t", root->secondchild);
    printf("%d\t", root->thirdchild);
    printf("%d\t", root->fourthchild);
    printf("%d\t", root->fifthchild);
    printf("%d\t", root->sixthchild);
}

int main()
{
    struct node *root = NULL;
    setData(50);
    display(root);
    return 0;
}