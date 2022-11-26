#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Defining the required struct
typedef struct DLLNode DLLNode;
typedef struct DLLNode
{
    int data;
    DLLNode *prev;
    DLLNode *next;
} DLLNode;

// Creates a single ListNode with data as 'data'
// and returns the pointer of the created node
DLLNode *create_node(int data)
{
    DLLNode *node;

    node = malloc(sizeof(DLLNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

// Creates a new node and adds it to the head of the list
// and returns the pointer of the newly created node
DLLNode *add_to_front(int data, DLLNode *head)
{
    DLLNode *new_head = create_node(data);

    new_head->next = head;
    if (head != NULL)
        head->prev = new_head;

    return new_head;
}

// Swaps the data between two nodes
void swap(DLLNode *node1, DLLNode *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Sorts the list using bubble sort
void sort(DLLNode *head, int size)
{
    for (int i = 0; i < size; i++)
    {
        DLLNode *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->data > curr->next->data)
            {
                swap(curr, curr->next);
            }
            curr = curr->next;
        }
    }
}

// Prints the entire list
// so that only 10 elements are printed on each line
void print_dll(DLLNode *head, char *title)
{
    printf("%s\n", title);

    DLLNode *curr = head;
    int i = 0;
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
        if (++i % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

// Removes the node from the DLL
// by rearranging the pointers
void remove_node(DLLNode *node)
{
    DLLNode *prev = node->prev;
    DLLNode *next = node->next;

    // We can assume prev to be not NULL
    // as there would be a duplicate element
    // for which we are removing the node
    assert(prev != NULL);

    prev->next = next;
    if (next != NULL)
        next->prev = prev;
}

// Removes all the duplicates in the given list
void remove_duplicates(DLLNode *head, int size)
{
    // Sort the list
    sort(head, size);

    // Remove adjacent elements with the same value
    DLLNode *curr = head;
    while (curr->next != NULL)
    {
        if (curr->next->data == curr->data)
        {
            remove_node(curr->next);
        }
        else
        {
            curr = curr->next;
        }
    }
}

// Creates a list of random elements [0, 49] with given size
// and returns the pointer of the head node
DLLNode *create_random_list(int size)
{
    DLLNode *head = NULL;
    for (int i = 0; i < size; i++)
    {
        int random_data = rand() % 50;
        head = add_to_front(random_data, head);
    }

    return head;
}

int main(void)
{
    // Initialize size t0 200
    int size = 200;

    // Create a random list and print it
    DLLNode *head = create_random_list(size);
    print_dll(head, "List:");

    // Remove duplicates from the list and print it
    remove_duplicates(head, size);
    print_dll(head, "List after duplication removal:");
}