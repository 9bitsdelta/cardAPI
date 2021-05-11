/*
 *  game.c
 */

#include "cards.h"

#include <stdio.h>

unsigned short suit(node_t* p)
{
    return p->key/13;
}

unsigned short face(node_t* p)
{
    return p->key%13;
}

const char* text_suit(node_t* p)
{
    switch(p->key/13)
    {
        case 0:
            return "spades";
        case 1:
            return "hearts";
        case 2:
            return "diamonds";
        case 3:
            return "clubs";
        default:
            return "invalid";
    }
}

const char* text_face(node_t* p)
{
    switch(p->key%13)
    {
        case 0:
            return "two";
        case 1:
            return "three";
        case 2:
            return "four";
        case 3:
            return "five";
        case 4:
            return "six";
        case 5:
            return "seven";
        case 6:
            return "eight";
        case 7:
            return "nine";
        case 8:
            return "ten";
        case 9:
            return "jack";
        case 10:
            return "queen";
        case 11:
            return "king";
        case 12:
            return "ace";
        default:
            return "invalid";
    }
}

void pcard(node_t* p)
{
    printf("[CARD][%d]: %s of %s\n", p->key, text_face(p), text_suit(p));
}

stack_t* sorted_deck()
{
    stack_t* deck = make_list();

    for(int i=0; i<52; i++)
    {
        push(deck, make_node(i) );
    }

    return deck;
}

stack_t* small_deck()
{
    stack_t* deck = make_list();

    for(int i = FACE_7; i < (1 + SUIT_C) * 13; i++)
    {
        node_t* node = make_node(i);
        push(deck, node);

        if( face(node) == FACE_A)
        {
            i += FACE_7;
        }

    }

    return deck;
}


