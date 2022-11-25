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

// Creates a list of random elements [0, 100000] with given size
// and returns the pointer of the head node
ListNode *create_random_list(int size)
{
    ListNode *head = NULL;
    for (int i = 0; i < size; i++)
    {
        int random_data = rand() % 100000;
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

// Sorts the list with given head
// and returns the new head of the list
ListNode *bubble_sort(ListNode *head, int list_size)
{
    // variable to store the new head
    // which we will return
    ListNode *new_head = head;

    // Bubble sort
    // Outer loop runs for the list size number of timess
    for (int i = 0; i < list_size; i++)
    {
        // We need to update the new head
        // if first two elements of the list
        // need to be swapped
        if (new_head->data > new_head->next->data)
        {
            ListNode *temp = new_head->next;
            new_head->next = temp->next;
            temp->next = new_head;
            new_head = temp;
        }

        // Iterating over the entire list
        // we swap adjacent elements whenever
        // the next element is greater than the current element
        ListNode *curr = new_head;
        while (curr != NULL && curr->next != NULL && curr->next->next != NULL)
        {
            if (curr->next->data > curr->next->next->data)
            {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                temp->next = curr->next->next;
                curr->next->next = temp;
            }
            curr = curr->next;
        }
    }

    return new_head;
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
    head = bubble_sort(head, list_size);
    print_list(head, 0, "Sorted list:");
}
