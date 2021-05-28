/*
 *  datastruct.c
 */

#include "datastruct.h"

node_t* make_node(unsigned short i)
{
    node_t* p = malloc(sizeof(node_t));

    p->key = i;
    p->next = NULL;

    return p;
}

stack_t* make_stack()
{
    stack_t* l;

    l = malloc(sizeof(stack_t));

    l->top = NULL;
    l->bot = NULL;
    l->size = 0;

    return l;
}

void push(stack_t* l, node_t* p)
{
    if(!l->top)
    {
        l->top = l->bot = p;
        l->size++;
        return;
    }

    p->next = l->top;
    l->top = p;

    l->size++;
}

node_t* pop(stack_t* l)
{
    if(!l->top) return NULL;

    node_t* p = l->top;
    l->top = p->next;
    p->next = NULL;

    l->size--;

    return p;
}

void for_each(stack_t* l, void(*fun)(node_t*))
{
    for(node_t* p = l->top; p != NULL; p = p->next)
    {
        (*fun)(p);
    }
}

node_t* find(stack_t* l, int(*crit)(node_t*))
{
    for(node_t* p = l->top; p != NULL; p = p->next)
    {
        if( (*crit)(p) ) return p;
    }
    return NULL;
}

void free_list(stack_t* l)
{
    while(l->top != NULL)
    {
        free(pop(l));
    }
    free(l);
}
