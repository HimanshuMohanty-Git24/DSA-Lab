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
void insert_beg()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d", &new_node->data);
    if (head == NULL)
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insert_end()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
    }
}
void insert_pos()
{
    struct node *new_node, *temp;
    int pos, i;
    i = 1;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position you want to insert:");
    scanf("%d", &pos);
    printf("\nEnter data:");
    scanf("%d", &new_node->data);
    if (head == NULL)
        head = new_node;
    else
    {
        for (temp = head; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void delete_beg()
{
    if (head == NULL)
    {
        printf("\nNO ELEMENT IN THE LIST");
    }
    else
    {
        printf("\nElement deleted:%d\n", head->data);

        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}
void delete_end()
{
    struct node *temp, *temp1;
    if (head == NULL)
    {
        printf("\nNO ELEMENT IN THE LIST");
    }
    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            temp1 = temp;
        }
        printf("\nElement deleted:%d\n", temp->data);
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            temp1->next = NULL;
        }
        free(temp);
    }
}
void delete_pos()
{
    struct node *temp1, *temp;
    int i = 1;
    int pos;
    printf("\nEnter the position you want to delete:");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("\nNO ELEMENT IN THE LIST");
    }
    else
    {
        for (temp1 = head; i < pos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp = temp1->next;
        printf("\nElement deleted:%d\n", temp->data);
        temp1->next = temp->next;
        free(temp);
    }
}
void get_length()
{
    int count = 0;
    struct node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        count++;
    }
    printf("\nThe length of linked list is:%d", count);
}
void reverseLL()
{
    printf("\nReversed linkedlist is:");
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}
int main()
{
    Create();
    display();
    insert_beg();
    display();
    insert_end();
    display();
    insert_pos();
    display();
    delete_beg();
    display();
    delete_end();
    display();
    delete_pos();
    display();
    get_length();
    reverseLL();
    display();

    return 0;
}
