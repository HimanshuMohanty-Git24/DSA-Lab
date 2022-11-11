// Himanshu Mohanty 2105719
#include <stdio.h>
#include <stdlib.h>
int choice;
struct digit
{
    int data;
    struct digit *next;
};
struct ch
{
    char ch;
    struct ch *next;
};
struct digit *top_digit = NULL;
struct ch *bottom_alpha = NULL;
struct digit *last_dg;
struct ch *last_ch;
void link()
{
    for (last_dg = top_digit; last_dg->next != NULL; last_dg = last_dg->next)
        ;
    for (last_ch = bottom_alpha; last_ch->next != NULL; last_ch = last_ch->next)
        ;
    last_ch->next = last_dg;
    last_dg->next = last_ch;
}

int push()
{
    printf("\nWhat do you want to insert ?\n1.Digit\n2.Char\n:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        struct digit *newdata;
        newdata = (struct digit *)malloc(sizeof(struct digit));
        printf("\nEnter the digit:");
        scanf("%d", &newdata->data);
        newdata->next = top_digit;
        top_digit = newdata;
    }
    if (choice == 2)
    {
        int p;
        struct ch *newch;
        newch = (struct ch *)malloc(sizeof(struct ch));
        printf("\nEnter the char(To Exit Click 90 89):");
        scanf("%c ", &newch->ch);
        scanf("%d  ", &p);
        newch->next = bottom_alpha;
        bottom_alpha = newch;
    }
}
void display()
{
    if (choice == 1)
    {
        struct digit *temp;
        temp = top_digit;
        if (top_digit == NULL)
        {
            printf("Under flow");
        }
        else
        {
            printf("\nStack Is:\n");
            while (temp != NULL)
            {
                printf("%d\n", temp->data);
                temp = temp->next;
            }
        }
    }
    if (choice == 2)
    {
        struct ch *temp;
        temp = bottom_alpha;
        if (bottom_alpha == NULL)
        {
            printf("Under flow");
        }
        else
        {
            printf("\nStack Is:\n");
            while (temp != NULL)
            {
                printf("%c\n", temp->ch);
                temp = temp->next;
            }
        }
    }
}
void peek()
{
    if (choice == 1)
    {
        if (top_digit == NULL)
        {
            printf("Under Flow");
        }
        else
        {
            printf("The top element is:%d", top_digit->data);
        }
    }
    if (choice == 2)
    {
        if (bottom_alpha == NULL)
        {
            printf("Under Flow");
        }
        else
        {
            printf("The bottom element is:%c", bottom_alpha->ch);
        }
    }
}
void pop()
{
    if (choice == 1)
    {
        struct digit *temp;
        temp = top_digit;
        if (top_digit == NULL)
        {
            printf("Under Flow");
        }
        else
        {
            printf("The popped element is:%d", top_digit->data);
            top_digit = top_digit->next;
            free(temp);
        }
    }
    if (choice == 2)
    {
        struct ch *temp;
        temp = bottom_alpha;
        if (bottom_alpha == NULL)
        {
            printf("Under Flow");
        }
        else
        {
            printf("The popped element is:%c", bottom_alpha->ch);
            bottom_alpha = bottom_alpha->next;
            free(temp);
        }
    }
}
int main()
{
    link();
    int choose;
    int x;
    printf("\n\n\t\t\tStack Operation\t\t\t\n\n");
    printf("\nPress 1 to push\n");
    printf("\nPress 2 to pop\n");
    printf("\npress 3 to peek\n");
    printf("\npress 4 to Display the stack\n");
    printf("\npress 0 to exit the operation\n");
    while (1)
    {
        printf("\nChoose your desired operation:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    }
    return 0;
}
