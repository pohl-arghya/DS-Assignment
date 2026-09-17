#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertLast(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertPosition(int value, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        insertFront(value);
        return;
    }

    if (head == NULL)
    {
        printf("Position does not exist!\n");
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            printf("Position does not exist!\n");
            return;
        }
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    struct Node *deleteNode = head;

    head = head->next;
    temp->next = head;

    free(deleteNode);
}
void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    struct Node *deleteNode = temp->next;

    temp->next = head;

    free(deleteNode);
}

void deletePosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (pos <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        deleteFront();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            printf("Position does not exist!\n");
            return;
        }
    }

    if (temp->next == head)
    {
        printf("Position does not exist!\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);
}

void deleteByValue(int value)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->data == value)
    {
        deleteFront();
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
    {
        if (temp->next->data == value)
        {
            struct Node *deleteNode = temp->next;

            temp->next = deleteNode->next;

            free(deleteNode);

            printf("%d deleted successfully.\n", value);
            return;
        }

        temp = temp->next;
    }

    printf("%d not found in the list.\n", value);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main()
{
    int choice, value, pos;

    while (1)
    {
        printf("\n===== CIRCULAR SINGLY LINKED LIST =====\n");
        printf("1. Insert at front\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at front\n");
        printf("5. Delete at last\n");
        printf("6. Delete at any position\n");
        printf("7. Delete by value\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertLast(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}