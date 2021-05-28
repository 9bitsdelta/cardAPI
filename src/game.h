/*
 *  game.h
 */

#ifndef GAME_H
#define GAME_H

#include "cards.h"

#include <stdio.h>

/*
 *  Plays war given two hands of cards and
 *  two pointers for the score of the players
 */
void play_war(stack_t* hand1,
              stack_t* hand2,
              int* score1,
              int* score2);

/*
 *  Play septica given a deck, two hands,
 *  and two score piles.
 */
void play_septica(stack_t* deck,
                  stack_t* hand1,
                  stack_t* hand2,
                  stack_t* pile1,
                  stack_t* pile2);

#endif //GAME_H
