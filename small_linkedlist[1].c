#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

void add_node_begin();
void add_node_end();
void add_node_position();
void del_beg();
void del_end();
void del_position();
void display();

struct node *head = NULL;
struct node *temp = NULL;
struct node *ptr = NULL;

int main()
{
    int choice;
    while (1)
    {
        printf("\nchoice : 1(add_beg)/2(add_end)/3(add_pos)/4(del_beg)/5(del_end)\n");
        printf("\nchoice : 6(del_position)/7(display)/8(exit)\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            add_node_begin();
        }
        else if (choice == 2)
        {
            add_node_end();
        }
        else if (choice == 3)
        {
            add_node_position();
        }
        else if (choice == 4)
        {
            del_beg();
        }
        else if (choice == 5)
        {
            del_end();
        }
        else if (choice == 6)
        {
            del_position();
        }
        else if (choice == 7)
        {
            display();
        }
        else
        {
            break;
        }
    }
}

void add_node_begin()
{
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}
void display()
{
    temp = head;
    if (head == NULL)
    {
        printf("No nodes");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void add_node_end()
{
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}
void add_node_position()
{
    int a;
    int count = 0;
    // Allocate memory for new node
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
        return;
    }

    // Count the number of nodes in the list
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\nCurrent nodes = %d\n", count);
    // Check if position is valid
    printf("\nEnter the position\n");
    scanf("%d", &a);
    if (a < 1)
    {
        printf("\n Invalid Position\n");
        free(ptr);
        return;
    }
    else if (a == 1)
    {
        free(ptr);
        add_node_begin();
        return;
    }
    else if (a > count + 1)
    {
        printf("\n Invalid Position\n");
        free(ptr);
        return;
    }

    // Traverse to (a-1)th node
    temp = head;
    for (int i = 1; i < a - 1; i++)
    {
        temp = temp->next;
    }

    // Insert new node
    ptr->next = temp->next;
    temp->next = ptr;
}

void del_beg()
{
    temp = head;
    if (head == NULL)
    {
        printf("No Nodes\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

void del_end()
{
    temp = head;
    struct node *temp1 = head;
    if (head == NULL)
    {
        printf("No Nodes\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp1->next != temp)
        {
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void del_position()
{
    int n, count = 0;
    struct node *temp1 = NULL;
    ;

    printf("Enter the position\n");
    scanf("%d", &n);
    temp = head;

    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }

    if (head == NULL)
    {
        printf("No Nodes");
    }
    else if (n <= 0 || n > count)
    {
        printf("Invalid Position");
    }
    else if (n == 1)
    {
        del_beg();
        return;
    }
    else
    {
        temp = head;
        temp1 = head;
        for (int i = 1; i <= n - 1; i++)
        {
            temp = temp->next;
        }
        while (temp1->next != temp)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp->next;
        free(temp);
        temp = NULL;
    }
}
