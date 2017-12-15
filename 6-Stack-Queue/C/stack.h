//
// Created by Lee Sutton on 2017-12-15.
//

#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Node
{
    int data;
    struct Node* item_below;
} Node_t;

typedef struct Stack
{
    Node_t* top;
}Stack_t;

/**
 * Pushes the input item onto the stack
 * @param stack: Stack to be modified
 * @param node: Pointer to the node to be pushed on top
 * only a single node may be pushed on top. If the input node
 * has references to nodes below, these nodes will be lost
 */
void stack_push(Stack_t* stack, Node_t* node)
{
    stack->top
}

/**
 * Pops the top item off the input stack
 * @param stack to be modified
 * @return top node from the stack
 */
Node_t* stack_pop(Stack_t* stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }

    Node_t* top_node = stack->top;
    stack->top = top_node->item_below;
    return top_node;
}

#endif //STACK_H
