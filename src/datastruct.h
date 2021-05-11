/*
 *  datastruct.h
 *
 *  Header file containing all the structures and functions necessary for the
 *  implementations of different card games.
 */

#ifndef DS_H
#define DS_H

#include <stdlib.h>

/*
 *  A structure that defines a playing card in a deck
 *
 *  key - has values in the range 0-51
 *      -  0-12 for spades
 *      - 13-25 for hearts
 *      - 26-38 for diamonds
 *      - 39-51 for clubs
 *
 *  next - a pointer to the next node in a list
 */
typedef struct NODE {
    unsigned short key;
    struct NODE* next;
} node_t;

/*
 *  Heap allocates a new node, with a given key value.
 *  Freeing the memory is done with free()
 */
node_t* make_node(unsigned short i);

/*
 *  A simple linked list structure that defines a pile of playing cards be it
 *  the deck, a player's hand or any other sort of pile. Processed under
 *  the form of a stack structure since most games don't require navigating
 *  the piles of cards in any direction other than from top to bottom.
 *
 *  top - pointer to the top node in the stack
 *  bot - pointer to the bottom node in the stack
 *  size - the size of the list, useful if the game requires it
 */
typedef struct STACK {
    node_t* top;
    node_t* bot;
    size_t size;
} stack_t;

/*
 *  Heap allocates a new, empty list.
 */
stack_t* make_list();

/*
 *  Adds a node to the list before the first
 */
void push(stack_t* l, node_t* p);

/*
 *  Removes the first node from the list and returns it
 */
node_t* pop(stack_t* l);

/*
 *  For each element in the least, run the function.
 *  The function prototype must be:
 *  void fun(node_t*);
 *  Can be used to easily process all elements of the list.
 */
void for_each(stack_t* l, void(*fun)(node_t*));

/*
 *
 */
node_t* find(stack_t* l, int(*fun)(node_t*));

/*
 *  Frees all the memory allocated for the list
 */
void free_list(stack_t* l);

#endif //NODE_H
