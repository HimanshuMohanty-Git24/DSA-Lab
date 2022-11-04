#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *child[100];
};

// int n = 0;

struct queue
{
    int front;
    int rear;
    struct node **arr;
    int count;
};

void push(struct queue q, struct node data)
{
    if (q->front == 99)
        return;
    q->front++;
    q->arr[q->front] = data;
    q->count++;
}

void pop(struct queue *q)
{
    if (q->rear == 99)
    {
        return;
    }
    q->rear++;
    q->count--;
}

struct node *root = NULL;

struct node *initialize(struct node *root, int deg, int data)
{

    root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    for (int i = 0; i < deg; i++)
    {
        root->child[i] = NULL;
    }
    // n++;
    return root;
}

struct node *create(struct node *root, int degree)
{
    printf("Enter data: ");
    int data;
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    root = initialize(root, degree, data);

    for (int i = 0; i < degree; i++)
    {
        printf("Enter data for inserting in  child of node %d \n", data);
        root->child[i] = create(root, degree);
    }
    return root;
}

void traverse(struct node *root, int degree)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    for (int i = 0; i < degree; i++)
    {
        traverse(root->child[i], degree);
    }
}

void levelTraverse(struct node *root, int degree)
{
    // int n = 0;
    // countnodes(root, degree, &n);
    // printf("%d ", n);
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.count = 0;
    q.arr = (struct node *)malloc(99 * sizeof(struct node));
    push(&q, root);

    while (q.count)
    {
        pop(&q);
        struct node *temp = q.arr[q.rear];
        printf("%d ", temp->data);
        for (int i = 0; i < degree; i++)
        {
            if (temp->child[i])
            {
                push(&q, temp->child[i]);
            }
        }
    }
}

struct node *buildFromLevelOrder(struct node *root, int degree)
{
    struct queue s;
    s.front = -1;
    s.rear = -1;
    s.count = 0;
    s.arr = (struct node *)malloc(99 * sizeof(struct node));
    int data;
    printf("\nEnter data: ");
    scanf("%d", &data);

    if (data == -1)
    {
        root = NULL;
        return root;
    }
    root = initialize(root, degree, data);
    push(&s, root);
    // printf("\n%d", s.count);
    while (s.count)
    {
        pop(&s);
        struct node *temp = s.arr[s.rear];
        for (int i = 0; i < degree; i++)
        {
            printf("Enter child of node %d: ", temp->data);
            scanf("%d", &data);
            if (data != -1)
            {
                temp->child[i] = initialize(temp->child[i], degree, data);
                push(&s, temp->child[i]);
            }
        }
    }
    return root;
}

int main()
{
    int deg;
a:
    printf("\n------------------------------------------------");
    printf("\nPress 1 to create N-ary tree.\nPress 2 to traverse tree.\nPress 3 to level order traverse.\nPress 4 to create N-ary tree from Level Order.\nPress 0 to exit the program.");
    printf("\n------------------------------------------------\n");
    int choice;
    printf("Enter the choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\n");
        printf("\nEnter the degree of tree: ");
        scanf("%d", &deg);
        root = create(root, deg);
        goto a;
    }
    else if (choice == 2)
    {
        printf("\nThe preOreder traversal of N-ary tree is: ");
        traverse(root, deg);
        goto a;
        printf("\n");
    }
    else if (choice == 0)
    {
        exit;
    }
    else if (choice == 3)
    {
        printf("\nThe levelOreder traversal of N-ary tree is: ");
        levelTraverse(root, deg);
        goto a;
    }
    else if (choice == 4)
    {
        printf("\n");
        printf("\nEnter the degree of tree: ");
        scanf("%d", &deg);
        root = buildFromLevelOrder(root, deg);
        goto a;
    }
    else
    {
        printf("\nInvalid choice. Please enter correct choice! \n");
        goto a;
    }
    return 0;
}