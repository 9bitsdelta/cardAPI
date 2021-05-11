/*
 *  cards.h
 */

#ifndef CARDS_H
#define CARDS_H

#define SUIT_S  0
#define SUIT_H  1
#define SUIT_D  2
#define SUIT_C  3

#define FACE_2  0
#define FACE_3  1
#define FACE_4  2
#define FACE_5  3
#define FACE_6  4
#define FACE_7  5
#define FACE_8  6
#define FACE_9  7
#define FACE_10 8
#define FACE_J  9
#define FACE_Q  10
#define FACE_K  11
#define FACE_A  12

#include "datastruct.h"

/*
 *  Get the numeric suit of a playing card
 */
unsigned short suit(node_t* p);

/*
 *  Get the numeric face of a playing card
 */
unsigned short face(node_t* p);

/*
 *  Get the text suit of a playing card
 */
const char* text_suit(node_t* p);

/*
 *  Get the text face of a playing card
 */
const char* text_face(node_t* p);

/*
 *  Print card to stdout
 */
void pcard(node_t* p);

/*
 *  Generate an already shuffled deck
 */
stack_t* sorted_deck();

/*
 * Generate a deck with only the cards from 7 to aces
 */
stack_t* small_deck();

#endif //CARDS_H
