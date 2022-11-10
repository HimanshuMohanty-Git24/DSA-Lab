#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
} *root = NULL, *temp = NULL, *t2, *t1;
void create()
{
    int data;

    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(1 * sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
    return data;
}
int form()
{
    printf("\nEnter the number of elemnt to be inserted:");
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        insert();
    }
}

void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}

void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}

int flag = 1;

int main()
{
    int ch;
    printf("\n\t\tOPERATIONS On BST\t\t\n");
    printf("\n1 - Creation of BST\n");
    printf("\n2-Inorder Traversal\n");
    printf("\n0 - Exit\n");
    while (1)
    {

        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            form();
            break;
        case 2:
            inorder(root);
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }

    return 0;
}