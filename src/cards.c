/*
 *  cards.c
 */

#include "cards.h"

#include <stdio.h>
#include <stdalign.h>
#include <time.h>

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
    stack_t* deck = make_stack();

    for(int i=0; i<52; i++)
    {
        push(deck, make_node(i) );
    }

    return deck;
}

stack_t* shuffled_deck()
{
    stack_t* deck = make_stack();

    int card[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8,
                   9, 10, 11, 12, 13, 14, 15,
                   16, 17, 18, 19, 20, 21, 22,
                   23, 24, 25, 26, 27, 28, 29,
                   30, 31, 32, 33, 34, 35, 36,
                   37, 38, 39, 40, 41, 42, 43,
                   44, 45, 46, 47, 48, 49, 50,
                   51 };

    // Initialize seed randomly
    srand(time(0));

    for (int i=0; i<52 ;i++) {
        // Random for remaining positions.
        int r = i + (rand() % (52 - i));

        int temp = card[i];
        card[i] = card[r];
        card[r] = temp;

        push(deck, make_node(card[i]));
    }

    return deck;
}

stack_t* small_deck()
{
    stack_t* deck = make_stack();

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

stack_t* ssmall_deck()
{
    stack_t* deck = make_stack();

    int card[] = {  5,  6,  7,  8,  9, 10, 11, 12,
                   18, 19, 20, 21, 22, 23, 24, 25,
                   31, 32, 33, 34, 35, 36, 37, 38,
                   44, 45, 46, 47, 48, 49, 50, 51 };

    // Initialize seed randomly
    srand(time(0));

    for (int i=0; i<32 ;i++) {
        // Random for remaining positions.
        int r = i + (rand() % (32 - i));

        int temp = card[i];
        card[i] = card[r];
        card[r] = temp;

        push(deck, make_node(card[i]));
    }

    return deck;
}
