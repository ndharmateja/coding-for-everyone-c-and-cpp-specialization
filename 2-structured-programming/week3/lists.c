#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;
typedef struct Node
{
    int data;
    Node *next;
} Node;

int is_empty(const Node *node) { return node == NULL; }
Node *create_node(int d)
{
    Node *node;
    node = malloc(sizeof(Node));
    node->data = d;
    node->next = NULL;

    return node;
}

Node *add_to_front(int d, Node *head)
{
    Node *new = create_node(d);
    new->next = head;
    return new;
}

Node *array_to_list(int array[], int size)
{
    Node *head = NULL;
    for (int i = size - 1; i >= 0; i--)
    {
        head = add_to_front(array[i], head);
    }
    return head;
}

void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    print_list(head->next);
}

void print_array(int array[], int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%d", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }
    printf("}\n");
}

int count_element(Node *head, int key)
{
    if (head == NULL)
    {
        return 0;
    }
    return (head->data == key ? 1 : 0) + count_element(head->next, key);
}

Node *concat_lists(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    Node *curr = head1;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = head2;
    return head1;
}

// Insert q between p1 and p2
// p1 -> p2 becomes p1 -> q -> p2
void insert(Node *p1, Node *p2, Node *q)
{
    assert(p1->next == p2);
    p1->next = q;
    q->next = p2;
}

// * **head => pointer to pointer to the head
void delete (Node *elem, Node **prev, Node **head)
{
    if (*head == *prev)
    {
        *head = elem->next;
    }
    else
    {
        (*prev)->next = elem->next;
    }
    free(elem);
}

int main(void)
{
    printf("List 1:\n");
    int array1[] = {5, 4, 3, 15, 1};
    Node *head1 = array_to_list(array1, 5);
    print_array(array1, 5);
    print_list(head1);

    int key = 5;
    printf("Count of %d in list is %d.\n", key, count_element(head1, key));
    key = -3;
    printf("Count of %d in list is %d.\n", key, count_element(head1, key));

    int array2[] = {-2, 3, 10};
    Node *head2 = array_to_list(array2, 3);

    Node *concatenated = concat_lists(head1, head2);
    printf("\nList 1: ");
    print_list(head1);
    printf("List 2: ");
    print_list(head2);
    printf("Concatenated list: ");
    print_list(concatenated);

    printf("Inserting 6 between 3 and 15\n");
    insert(head1->next->next, head1->next->next->next, create_node(6));
    print_list(head1);
}