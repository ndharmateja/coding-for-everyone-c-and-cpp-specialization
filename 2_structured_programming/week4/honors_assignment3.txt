#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Defining the required struct
typedef struct TreeNode TreeNode;
typedef struct TreeNode
{
    int data;
    TreeNode *left_child;
    TreeNode *right_child;
} TreeNode;

// Recursive function to print the inorder traversal
void print_inorder(TreeNode *root)
{
    if (root != NULL)
    {
        print_inorder(root->left_child);
        printf("%d, ", root->data);
        print_inorder(root->right_child);
    }
}

// Creates a single TreeNode with the given "data"
TreeNode *create_tree_node(int data)
{
    TreeNode *node;
    node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

// Recursively inserts "data" into the binary search tree
// rooted at "root"
void insert_into_tree(TreeNode *root, int data)
{
    assert(root != NULL);

    if (data < root->data)
    {
        if (root->left_child == NULL)
        {
            TreeNode *new_node = create_tree_node(data);
            root->left_child = new_node;
        }
        else
        {
            insert_into_tree(root->left_child, data);
        }
    }
    else
    {
        if (root->right_child == NULL)
        {
            TreeNode *new_node = create_tree_node(data);
            root->right_child = new_node;
        }
        else
        {
            insert_into_tree(root->right_child, data);
        }
    }
}

// Reads and returns the first integer of the file
int read_size(FILE *fp)
{
    rewind(fp);
    int size;
    fscanf(fp, "%d", &size);
    return size;
}

// Reads the file data into the given array
void read_data(FILE *fp, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d", &array[i]);
    }
}

// Creates a tree from the array
// and returns the pointer of the root of
// the created tree
TreeNode *create_tree_from_array(int array[], int size)
{
    assert(size > 0);

    TreeNode *root = create_tree_node(array[0]);

    for (int i = 1; i < size; i++)
    {
        insert_into_tree(root, array[i]);
    }

    return root;
}

// Prints an array
void print_array(int array[], int size, char *title)
{
    printf("\n%s\n", title);

    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }

    printf("}\n");
}

int main(int argc, char *argv[])
{
    // If input filename is given as arg, we use it
    // otherwise we use "input_data.txt"
    char *input_filename = argc == 1 ? "in.txt" : argv[1];

    // Open file pointer
    FILE *ifp = fopen(input_filename, "r");

    // Read size and data from the file into array
    int size = read_size(ifp);
    int array[size];

    read_data(ifp, array, size);

    // Close the file pointer
    fclose(ifp);

    // Print contents of the array
    printf("\nIntegers in file read to array complete (%d elements read).\n", size);
    print_array(array, size, "Contents of array: ");

    // Create a binary search tree from the elements of the array
    TreeNode *root = create_tree_from_array(array, size);
    printf("\nBinary Search Tree creation from the elements of the array complete.\n");

    // Inorder traversal
    printf("\nInorder traversal of the elements in the tree ");
    printf("(Note: These will be sorted as it is a binary search tree.):\n");
    print_inorder(root);
    printf("\n\n");

    return 0;
}