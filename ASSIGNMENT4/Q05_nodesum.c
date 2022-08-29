#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertfirst()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new_node->data);
    if (head == NULL)
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insertlast()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new_node->data);
    if (head == NULL)
        head = new_node;
    else
    {
        struct node *temp = NULL;
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
    }
}
void insetanypos()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new_node->data);
    int pos;
    scanf("%d", &pos);
    if (head == NULL)
        head = new_node;
    else
    {
        struct node *temp = NULL;
        int i = 1;
        for (temp = head; i < pos - 1; temp = temp->next, ++i)
            ;
        struct node *temp1 = temp->next;
        temp->next = new_node;
        new_node->next = temp1;
    }
}
void traverse()
{
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
}
int sumofnode()
{
    struct node *temp = head;
    int sum = 0;
    do
    {
        sum = sum + temp->data;
        temp = temp->next;
    } while (temp != NULL);
    return sum;
}
int main()
{
    int pick;
    printf("\nMENU\n");
    printf("\nChoose one task: \n");
    printf("\n1. Add node at first.\n");
    printf("\n2. Add node at last.\n");
    printf("\n3. Add node at any position.\n");
    printf("\n4. Display all nodes.\n");
    printf("\n5. Display sum of all nodes.\n");
    printf("\n6. To exit\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &pick);
        switch (pick)
        {
        case 1:
            insertfirst();
            break;
        case 2:
            insertlast();
            break;
        case 3:
            insetanypos();
            break;
        case 4:
            traverse();
            break;
        case 5:
            printf("Sum of all node :%d", sumofnode());
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
