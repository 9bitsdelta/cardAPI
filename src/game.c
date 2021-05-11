/*
 *  game.c
 */

#include "game.h"

void play_war(stack_t* hand1, stack_t* hand2, int* score1, int* score2)
{
    if(hand1->top && hand2->top)
    {
        node_t* c1 = pop(hand1);
        node_t* c2 = pop(hand2);

        int res = face(c2) - face(c1);

        pcard(c1);
        pcard(c2);

        if (res < 0)
        {
            printf("---PLAYER 1 HAS A HIGHER SCORE\n");

            (*score1)++;
        }

        if (res > 0)
        {
            printf("---PLAYER 2 HAS A HIGHER SCORE\n");

            (*score2)++;
        }

        if (res == 0)
        {
            printf("---EQUAL SCORE, POPPING %d CARDS\n", face(c1) );

            for(int i = 0; i < face(c1); i++)
                pop(hand1); pop(hand2);
        }

        free(c1);
        free(c2);

        play_war(hand1, hand2, score1, score2);
    }
}

void play_septica(stack_t* deck,
                  stack_t* hand1,
                  stack_t* hand2,
                  stack_t* pile1,
                  stack_t* pile2)
{
    if(hand1->size < 4 && deck->size)
    {
        size_t needed = 4 - (hand1->size * 2);
        size_t available = ( needed < deck->size ) ? needed : deck->size;

        for(size_t i = 0; i < available/2; i++)
            push(hand1, pop(deck));

        for(size_t i = 0; i < available/2; i++)
            push(hand2, pop(deck));

    }

    if(hand1->top && hand2->top)
    {
        node_t* c1 = pop(hand1);
        node_t* c2 = pop(hand2);

        pcard(c1);
        pcard(c2);

        if( face(c1) == face(c2) || face(c2) == FACE_7 )
        {
            printf("---SWITCHED ORDER\n");
            push(pile2, c1);
            push(pile2, c2);
            play_septica(deck, hand2, hand1, pile2, pile1);
        }
        else
        {
            printf("---SAME ORDER\n");
            push(pile1, c1);
            push(pile1, c2);
            play_septica(deck, hand1, hand2, pile1, pile2);
        }
    }
}