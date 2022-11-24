#include <stdio.h>

#define MAX_LENGTH 1000
#define EMPTY -1
#define FULL MAX_LENGTH - 1

typedef struct
{
    char array[MAX_LENGTH];
    int top;
} Stack;

void push(Stack *stack, char c) { stack->array[++stack->top] = c; }
char pop(Stack *stack) { return stack->array[stack->top--]; }
char top(const Stack *stack) { return stack->array[stack->top]; }
void reset(Stack *stack) { stack->top = EMPTY; }
int is_empty(const Stack *stack) { return stack->top == EMPTY; }
int is_full(const Stack *stack) { return stack->top == FULL; }

void reverse(char string[], int length)
{
    printf("Original string: %s\n", string);

    Stack stack = {{}, EMPTY};
    for (int i = 0; i < length; i++)
    {
        push(&stack, string[i]);
    }

    for (int i = 0; i < length; i++)
    {
        string[i] = pop(&stack);
    }

    printf("Reversed string: %s\n", string);
}

int main(void)
{
    char string[] = "dharma";
    reverse(string, 6);
    return 0;
}
