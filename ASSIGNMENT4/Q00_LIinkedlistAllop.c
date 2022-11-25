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
    display();
}
int search()
{
    printf("\nEnter the elemnt you want to search:");
    int x;
    scanf("%d", &x);
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            printf("\nElement found in the list !!!");
            return 0;
        }
        temp = temp->next;
    }
    printf("\nElement not found!!!!\n");
}
void sumofnode()
{
    printf("\nSum of all node:\n");
    struct node *temp = head;
    int sum = 0;
    do
    {
        sum = sum + temp->data;
        temp = temp->next;
    } while (temp != NULL);
    printf("%d\n", sum);
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
    int pick;
    printf("\n\t\tMENU\t\t\n");
    printf("\nChoose one task: \n");
    printf("\n1. Creation of a List\n");
    printf("\n2. Insert at first\n");
    printf("\n3. Insert at last\n");
    printf("\n4. Insert at any position\n");
    printf("\n5. Delete at first\n");
    printf("\n6. Delete at last\n");
    printf("\n7. Delete at any position\n");
    printf("\n8. Display the list\n");
    printf("\n9. Length of the List\n");
    printf("\n10. Reverse the List\n");
    printf("\n11. Search an element in the list\n");
    printf("\n12. Sum of all nodes in the list\n");
    printf("\n13. Swap node of the list\n");
    printf("\n0. To exit\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &pick);
        switch (pick)
        {
        case 0:
            exit(1);
            break;
        case 1:
            Create();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_pos();
            break;
        case 5:
            delete_beg();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            display();
            break;
        case 9:
            get_length();
            break;
        case 10:
            reverseLL();
            break;
        case 11:
            search();
            break;
        case 12:
            sumofnode();
            break;
        case 13:
            swap();
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
