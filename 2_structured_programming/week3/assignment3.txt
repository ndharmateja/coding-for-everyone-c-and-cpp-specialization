#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the struct required
typedef struct ListNode ListNode;
typedef struct ListNode
{
    int data;
    ListNode *next;
} ListNode;

// Creates a single ListNode with data as 'd'
// and returns the pointer of the created node
ListNode *create_node(int d)
{
    ListNode *node;
    node = malloc(sizeof(ListNode));
    node->data = d;
    node->next = NULL;

    return node;
}

// Creates a new node and adds it to the head of the list
// and returns the pointer of the newly created node
ListNode *add_to_front(int d, ListNode *head)
{
    ListNode *new_head = create_node(d);
    new_head->next = head;

    return new_head;
}

// Creates a list of random elements [0, 10000] with given size
// and returns the pointer of the head node
ListNode *create_random_list(int size)
{
    ListNode *head = NULL;
    for (int i = 0; i < size; i++)
    {
        int random_data = rand() % 10000;
        head = add_to_front(random_data, head);
    }

    return head;
}

// Prints the entire list
// so that only 5 elements are printed on each line
void print_list(ListNode *head, int index, char *title)
{
    printf("%s\n", title);

    ListNode *curr = head;
    int i = 0;
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
        if (++i % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

// Swaps the data between two nodes
void swap(ListNode *node1, ListNode *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Sorts the list with given head
void bubble_sort(ListNode *head, int list_size)
{
    // Bubble sort
    // Outer loop runs for the list size number of timess
    for (int i = 0; i < list_size; i++)
    {
        // Iterating over the entire list
        // we swap adjacent elements whenever
        // the next element is greater than the current element
        ListNode *curr = head;
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

int main(void)
{
    // Reset random seed
    srand(time(0));

    // Create a random list of size 100 and print it
    int list_size = 100;
    ListNode *head = create_random_list(list_size);
    print_list(head, 0, "Unsorted list:");

    // Sort the list and print it
    bubble_sort(head, list_size);
    print_list(head, 0, "Sorted list:");
}
