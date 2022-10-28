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

    printf("Enter data be inserted : ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(1 * sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
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

void deletenode()
{
}

void traverse(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree");
        return;
    }
    if (t->l != NULL)
        traverse(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)
        traverse(t->r);
}

int flag = 1;

int main()
{
    int ch;
    while (1)
    {
        printf("\n\t\tOPERATIONS On BST\t\t\n");
        printf("\n1 - Insert an element into tree\n");
        printf("\n2 - Delete an element from the tree\n");
        printf("\n3 - Traverse the tree\n");
        printf("\n0 - Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            deletenode();
            break;
        case 3:
            traverse(root);
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