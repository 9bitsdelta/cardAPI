#include <stdio.h>

#define _DEBUG

#include "cards.h"
#include "game.h"

int g_score;

void score_fun(node_t* p)
{
    if(face(p) == FACE_10 || face(p) == FACE_A)
    {
        g_score++;
    }
}

int main()
{
	stack_t* deck;

    stack_t* hand1;
    stack_t* hand2;

    int score1, score2;

    printf("\n---PLAYING SEPTICA\n");
    {
        deck = ssmall_deck();
        hand1 = make_stack();
        hand2 = make_stack();

        score1 = score2 = 0;

        stack_t *pile1, *pile2;

        pile1 = make_stack();
        pile2 = make_stack();

        play_septica(deck, hand1, hand2, pile1, pile2);

        g_score = 0;
        for_each(pile1, &score_fun);
        score1 = g_score;

        g_score = 0;
        for_each(pile2, &score_fun);
        score2 = g_score;

        printf("---GAME ENDED %d TO %d\n", score1, score2);

        free_list(hand1);
        free_list(hand2);
        free_list(deck);

        free_list(pile1);
        free_list(pile2);
    }
    
}
