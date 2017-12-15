#include <stdio.h>
#include <stdlib.h>

#include "unittest.h"

#define TRUE 1
#define FALSE 0

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
Node_t* find_nth_last_node(LinkedList_t list, int n);
void print_linked_list(LinkedList_t* list);
void remove_duplicates(LinkedList_t* list);
int _list_contains(Node_t* start, Node_t* value);

/************************************************************************/

int main()
{
    // Test basic list construction
    struct Node test;
    test.data = 5;
    int arr[] = {1,2,3,4,5};
    int size = 5;
    LinkedList_t* test_list = array_to_linked_list(arr, size);

    // Test node deletion
    Node_t* deleted_node = delete_node(test_list, 4);
    printf("Testing deleting node 4 expected output 1, 2, 3, 5\n");
    printf("Deleted Node: %d\n", deleted_node->data);
    print_linked_list(test_list);

    printf("\n******************************************************************\n\n");

    // Test removing duplicates from a linked list
    printf("Testing duplicate removal");
    int arr_duplicates[] = {1, 2, 2, 3, 4, 5};
    LinkedList_t* test_duplicates = array_to_linked_list(arr_duplicates, 6);
    printf("Heres the linked list before: \n");
    print_linked_list(test_duplicates);
    remove_duplicates(test_duplicates);
    printf("After removing duplicates");
    print_linked_list(test_duplicates);

    printf("\n******************************************************************\n\n");
    printf("Testing getting nth last item\n");
    Node_t* nth_last = find_nth_last_node(*test_list, 2);
    print_linked_list(test_list);
    printf("2nd last item is: %d\n", nth_last->data);
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
    printf("List: ");
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
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

/**
 * Deletes elements from linked list
 */
void remove_duplicates(LinkedList_t* list)
{
    // Empty list
    if (list->head == NULL)
    {
        return;
    }

    Node_t* previous_node = list->head;
    Node_t* current_node = previous_node->next;
    while (current_node != NULL)
    {
        // If in the list, delete the node
        if (_list_contains(current_node->next, current_node))
        {
            previous_node->next = current_node->next;
            current_node = previous_node->next;
        }
        else
        {
            previous_node = current_node;
            current_node = current_node->next;
        }

    }
}


/**
 * Returns boolean indicating if the list contains the input node.
 * Start node indicates the start of the list. Searches until it finds the node
 * or NULL
 */
int _list_contains(Node_t* start, Node_t* value)
{
    Node_t* current_node = start;
    while (current_node != NULL)
    {
        if (current_node->data == value->data)
            return TRUE;
        current_node = current_node->next;
    }
    return FALSE;
}

/**
 * Locates and returns a copy of the nth node in the linked list
 */
Node_t* find_nth_last_node(LinkedList_t list, int n)
{
    // Iterate through twice first time calculate the length
    // TODO Refactor this into its own method (list_length)
    int length = 0;
    Node_t* current_node = list.head;
    while (current_node != NULL)
    {
        length++;
        current_node = current_node->next;
    }
    // Ensure the nth node is smaller than the length of the list
    int nth_node = length - n;
    if (nth_node < 0)
        return NULL;

    current_node = list.head;
    for (int i = 0; i < nth_node; ++i)
    {
        current_node = current_node->next;
    }
    return current_node;
}
