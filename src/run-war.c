#include <stdio.h>

#define _DEBUG

#include "cards.h"
#include "game.h"

int main()
{
    stack_t* deck;

    stack_t* hand1;
    stack_t* hand2;

    int score1, score2;

    printf("\n---PLAYING WAR\n");
    {
        deck = shuffled_deck();
        hand1 = make_stack();
        hand2 = make_stack();

        score1 = score2 = 0;

        for(int i = 0; i < 26; i++)
        {
            push(hand1, pop(deck));
            push(hand2, pop(deck));
        }

        play_war(hand1, hand2, &score1, &score2);

        printf("---GAME ENDED %d TO %d\n", score1, score2);

        free_list(deck);
        free_list(hand1);
        free_list(hand2);
    }

    return 0;
}
