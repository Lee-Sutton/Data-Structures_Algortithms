#include <stdio.h>
#include <stdlib.h>

/**
 * Node data structure for nodes in a linked list
 */
typedef struct Node
{
    int data;
    struct Node* next;
}Node_t;

/**
 * Linked list data structure holds integers
 */
typedef struct LinkedList
{
    int length;
    Node_t* head;
}LinkedList_t;

/************************************************************************/
// Function definitions
struct Node;
struct LinkedList;
typedef struct Node Node_t;
typedef struct LinkedList LinkedList_t;
LinkedList_t* array_to_linked_list(int* arr, size_t size);
Node_t* construct_node(int data);
Node_t* delete_node(LinkedList_t* list, int data);
void print_linked_list(LinkedList_t* list);

/************************************************************************/

int main()
{
    struct Node test;
    test.data = 5;
    int arr[] = {1,2,3,4,5};
    int size = 5;
    LinkedList_t* test_list = array_to_linked_list(arr, size);
    print_linked_list(test_list);

    // Test deleting some nodes
    Node_t* deleted_node = delete_node(test_list, 4);
    printf("Testing deleting node 4 expected output 1, 2, 3, 5\n");
    printf("Deleted Node: %d\n", deleted_node->data);
    print_linked_list(test_list);
}

/************************************************************************/
/**
 * Converts input array to a linked list
 */
LinkedList_t* array_to_linked_list(int* arr, size_t size)
{
    LinkedList_t* list = malloc(sizeof(LinkedList_t));

    if (size < 1)
    {
        return list;
    }

    list->head = construct_node(arr[0]);

    // Loop through the array adding elements to the list
    Node_t* current_node = list->head;
    for (int i = 1; i < size; i++)
    {
        current_node->next = construct_node(arr[i]);
        current_node = current_node->next;
    }
    return list;
}

void print_linked_list(LinkedList_t* list)
{
    Node_t* current_node = list->head;
    while (current_node != NULL)
    {
        printf("Node: %d\n", current_node->data);
        current_node = current_node->next;
    }
}

/**
 * Allocates memory for a node and constructs with the input data
 */
Node_t* construct_node(int data)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * Locates the first node matching the input data, removes this node from the list
 * and returns a pointer to the deleted node
 */
Node_t* delete_node(LinkedList_t* list, int data)
{
    Node_t* current_node = list->head;

    // Check if the head contains the data
    if (current_node->data == data)
    {
        list->head = current_node->next;
        return current_node;
    }

    // If the head does not contain the data iterate
    // through the list until the node is found
    Node_t* previous_node = current_node;
    current_node = current_node->next;
    while (current_node != NULL)
    {
        if (current_node->data == data)
        {
            previous_node->next = current_node->next;
            return current_node;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    // If we don't find the node return NULL
    return NULL;
}
