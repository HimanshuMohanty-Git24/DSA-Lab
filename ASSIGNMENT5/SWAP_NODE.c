#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void Create()
{
    struct node *newnode, *temp;
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to continue(0,1):");
        scanf("%d", &choice);
    }
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            printf("%d->", temp->data);
        }
        else
        {
            printf("%d", temp->data);
        }
        temp = temp->next;
    }
}
void swap()
{
    int pos1, pos2;
    struct node *currX, *currY, *prevX, *prevY, *temp;
    currX = currY = head;
    prevX = prevY = NULL;
    printf("\nWhich position do you want to swap:");
    scanf("%d %d", &pos1, &pos2);
    if (pos1 == pos2)
    {
        printf("\nSame position\n");
    }
    int i1 = 1;
    for (; i1 < pos1; i1++)
    {
        prevX = currX;
        currX = currX->next;
    }
    int i2 = 1;
    for (; i2 < pos2; i2++)
    {
        prevY = currY;
        currY = currY->next;
    }
    if (currX == head)
    {
        head = currY;
        prevY->next = currX;
        temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
    else
    {
        prevX->next = currY;
        prevY->next = currX;
        temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
}
int main()
{
    Create();
    display();
    swap();
    display();
    return 0;
}
