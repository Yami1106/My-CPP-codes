#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define SIZE_OFDECK 52
#define SIZE_HAND 7
#define SUB_HAND 5
#define FLUSH 5
#define PIPS 13

#define KING 13
#define QUEEN 12
#define JACK 11
#define ACE 1

#define BIG_NUMBER 1000000

int sub_index = 0, count_hands = 0;

//suits
typedef enum { spades, hearts, clubs, diamonds} suit;

// This struct defines a card in a standard deck
typedef struct
{
    short pips; // could be 1-13
    suit suit; // taken from enum
} card;

// comparison to qsort() used in is_straight()
int comp(const void *a, const void *b)
{
    card *a_card = (card *)a;
    card *b_card = (card *)b;
    return (a_card->pips - b_card->pips);
}

// Util method for combinations
void get_combo(card combos[][SUB_HAND], card hand[], int s[]){
    card res[SUB_HAND];
    int i;
    for (i = 0; i < SUB_HAND; i++) {
        memcpy(&res[i], &hand[s[i]], sizeof(card));
    }
    memcpy(combos[sub_index++], res, SUB_HAND * sizeof(card));
}

// takes a 7 card hand an produces all 5 card subhands available
void combinations(card combos[][SUB_HAND], card hand[]){
    int s[SUB_HAND];
    int i;
    for(i = 0; (s[i] = i)<SUB_HAND-1; i++);
    get_combo(combos, hand, s);
    for(;;){
        int j;
        
        for(j = SUB_HAND-1; j >= 0 && s[j] == SIZE_HAND - SUB_HAND + j; j--)
        ;
            if(j<0)break;
            s[j]++;
            
        for(++j; j < SUB_HAND; j++){
            s[j] = s[j-1]+1;
        }
        get_combo(combos, hand, s);
    }
}


//takes a 5 card straight and returns true if the straight is a high straight
int high_straight(card hand[]){
    int i, king_flag = 0, ace_flag = 0;
    for(i = 0; i<SUB_HAND; i++){
        if(hand[i].pips == KING) king_flag = 1;
        else if(hand[i].pips == ACE) ace_flag = 1;
    }
    return (king_flag && ace_flag);
}

// shuffles deck randomly
int shuffle(card deck[])
{

    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand(usec);

    int i;
    for (i = SIZE_OFDECK - 1; i > 0; i--)
    {
        size_t j = (unsigned int)(rand() * (i + 1));
        card t = deck[j];
        deck[j] = deck[i];
        deck[i] = t;
    }
    return 0;
}

//fills the deck with standard poker cards
int init(card deck[])
{
    short i;

    for (i = 1; i <= SIZE_OFDECK; i++)
    {
        deck[i - 1].pips = i % 13;
        if (!(i % 13))
            deck[i - 1].pips = KING;
        if (i <= 13)
            deck[i - 1].suit = spades;
        else if (i <= 26)
            deck[i - 1].suit = hearts;
        else if (i <= 39)
            deck[i - 1].suit = clubs;
        else
            deck[i - 1].suit = diamonds;
    }
    return 0;
}
int print_cards(card deck[], int len)
{

    int i;
    printf("*** Hand start *** \n");
    for (i = 0; i < len; i++)
    {
        short pip = deck[i].pips;
        switch (deck[i].suit)
        {
        case spades:
            switch (pip)
            {
            case ACE:
                printf("Ace of Spades\n");
                break;

            case KING:
                printf("King of Spades\n");
                break;

            case QUEEN:
                printf("Queen of Spades\n");
                break;

            case JACK:
                printf("Jack of Spades\n");
                break;
            default:
                printf("%d of Spades\n", deck[i].pips);
                break;
            }
            break;
        case hearts:
            switch (pip)
            {
            case ACE:
                printf("Ace of Hearts\n");
                break;

            case KING:
                printf("King of Hearts\n");
                break;

            case QUEEN:
                printf("Queen of Hearts\n");
                break;

            case JACK:
                printf("Jack of Hearts\n");
                break;
            default:
                printf("%d of Hearts\n", deck[i].pips);
                break;
            }
            break;
        case clubs:
            switch (pip)
            {
            case ACE:
                printf("Ace of Clubs\n");
                break;

            case KING:
                printf("King of Clubs\n");
                break;

            case QUEEN:
                printf("Queen of Clubs\n");
                break;

            case JACK:
                printf("Jack of Clubs\n");
                break;
            default:
                printf("%d of Clubs\n", deck[i].pips);
                break;
            }
            break;
        case diamonds:
            switch (pip)
            {
            case ACE:
                printf("Ace of Diamonds\n");
                break;

            case KING:
                printf("King of Diamonds\n");
                break;

            case QUEEN:
                printf("Queen of Diamonds\n");
                break;

            case JACK:
                printf("Jack of Diamonds\n");
                break;
            default:
                printf("%d of Diamonds\n", deck[i].pips);
                break;
            }
            break;
        }
    }
    printf("*** Hand %d end *** \n\n", count_hands++);
    return 0;
}

int deal_hand(card deck[], card hand[])
{
    //shuffle the cards before dealing a hand
    shuffle(deck);

    int i;
    for (i = 0; i < SIZE_HAND; i++)
    {
        memcpy(&hand[i], &deck[i], sizeof(card));
    }
    return 0;
}

//checks to see whether a hand has a pair in it
int is_pair(card hand[])
{
    int pips[PIPS] = {0};

    int i;
    
    // Search the hand for a pair
    for (i = 0; i < SIZE_HAND; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            return 1;
    }
    return 0;
}

//checks to see whether a hand has at least two pairs
int is_two_pair(card hand[])
{
    int count = 0, pips[PIPS] = {0}, i;

    for (i = 0; i < SIZE_HAND; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            count++;
    }
    return (count >= 2);
}

//checks to see whether a hand has three of a kind
int is_three(card hand[])
{
    int pips[PIPS] = {0}, i;

    for (i = 0; i < SIZE_HAND; i++)
    {
        pips[hand[i].pips - 1]++;

        // If this card appeared three times
        if (pips[hand[i].pips - 1] == 3)
            return 1;
    }
    return 0;
}

// checks for a straight
int is_straight_5(card hand[]){

    // Sort the 5 card hand before checking
    qsort(hand, SUB_HAND, sizeof(card), comp);
    if(hand[0].pips == ACE && hand[4].pips == KING){
        if(hand[1].pips == 10 && hand[2].pips == JACK && hand[3].pips == QUEEN)
            return 1;
        return 0;
    }
    else{
        int i;
        for(i = SUB_HAND-1; i >= 1; i--){
            if((hand[i].pips - hand[i-1].pips) != 1) return 0;
        }
        return 1;
    }
}

// This method checks to see whether a hand has a staright in it.
int is_straight(int indices[]){
    int i;
    for(i = 0; i<21; i++){
        if(indices[i]) return 1;
    }
    return 0;
}

//takes all 21 combos of 5 card hands from the given 7 cards,marks the indices in which there is a straight
void find_straights(card combos[][SUB_HAND], int indices[]){
    int i;
    for(i = 0; i<21; i++){
        if(is_straight_5(combos[i]))
            indices[i] = 1;
    }
}

//determines whether a hand has a flush in it
int is_flush(card hand[], int SIZE_OFHAND){

    int spades_count = 0;
    int hearts_count = 0;
    int clubs_count = 0;
    int diamonds_count = 0;

    int i, suit;
    for (i = 0; i < SIZE_OFHAND; i++)
    {
        suit = hand[i].suit;
        switch (suit)
        {
        case spades:
            spades_count++;
            if (spades_count == FLUSH)
                return 1;
            break;
        case hearts:
            hearts_count++;
            if (hearts_count == FLUSH)
                return 1;
            break;
        case clubs:
            clubs_count++;
            if (clubs_count == FLUSH)
                return 1;
            break;
        case diamonds:
            diamonds_count++;
            if (diamonds_count == FLUSH)
                return 1;
            break;
        }
    }
    return 0;
}

//determines whether a hand is a full house
int is_full_house(card hand[]){
    int pips[13], i;
    for(i = 0; i<13; i++){
        pips[i] = 0;
    }
    for (i = 0; i < SIZE_HAND; i++)
    {
        pips[hand[i].pips - 1]++;
    }

    int pair_flag = 0, three_flag = 0;
    for (i = 0; i < 13; i++)
    {
        if (pips[i] == 2)
            pair_flag = 1;
        else if (pips[i] == 3)
            three_flag = 1;
    }
    return (pair_flag == 1 && three_flag == 1);
}

// checks to see whether a hand has four of a kind
int is_four(card hand[])
{
    int pips[13] = {0};
    int i;
    for (i = 0; i < SIZE_HAND; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 4)
            return 1;
    }
    return 0;
}

//checks to see whether a hand is a straight flush
int is_straight_flush(card combos[][SUB_HAND], int indices[]){

    int i;
    for(i = 0; i<21; i++){
        if(indices[i]){
            if(is_flush(combos[i], SUB_HAND)) return 1;
        }
    }
    return 0;
}

//checks to see whether a hand is a royal flush
int is_royale_flush(card combos[][SUB_HAND], int indices[]){
    int i;
    for(i = 0; i<21; i++){
        if(indices[i]){
            if(high_straight(combos[i])){
               if(is_flush(combos[i], SUB_HAND)) return 1;
            }
        }
    }
    return 0;
}

int main(void){

    double royal_flush = 0.0, straight_flush = 0.0, four_of_a_kind = 0.0, full_house = 0.0, flush = 0.0, straight = 0.0, three_of_a_kind = 0.0, two_pair = 0.0, pair = 0.0 , high_card = 0.0;
    card deck[SIZE_OFDECK];
    init(deck);
    card hand[SIZE_HAND], combos[21][SUB_HAND];
    
    int i, j;
    int indices[21] = {0};
    for(i = 0; i<=BIG_NUMBER; i++){
        
        deal_hand(deck, hand);
        for(j = 0; j<21; j++){
            indices[j] = 0;
        }
        combinations(combos,hand);

        find_straights(combos, indices);

        if(is_royale_flush(combos, indices)){
            royal_flush++;
        }

        else if(is_straight_flush(combos, indices)){
            straight_flush++;
        }

        else if(is_four(hand)){
            four_of_a_kind++;
        }

        else if(is_full_house(hand)){
            full_house++;
        }

        else if(is_flush(hand, SIZE_HAND)){
            flush++;
        }

        else if(is_straight(indices)){
            straight++;
        }

        else if(is_three(hand)){
            three_of_a_kind++;
        }

        else if(is_two_pair(hand)){
            two_pair++;
        }

        else if(is_pair(hand)){
            pair++;
        }

        else high_card++;
        sub_index = 0;
    }

    printf("Royal Flush - %lf\n", royal_flush/BIG_NUMBER);
    printf("Straight Flush - %lf\n", straight_flush/BIG_NUMBER);
    printf("Four of a Kind - %lf\n", four_of_a_kind/BIG_NUMBER);
    printf("Full House - %lf\n", full_house/BIG_NUMBER);
    printf("Flush - %lf\n", flush/BIG_NUMBER);
    printf("Straight - %lf\n", straight/BIG_NUMBER);
    printf("Three of a Kind - %lf\n", three_of_a_kind/BIG_NUMBER);
    printf("Two Pairs - %lf\n", two_pair/BIG_NUMBER);
    printf("Pair - %lf\n", pair/BIG_NUMBER);
    printf("High Card - %lf\n", high_card/BIG_NUMBER);
    return 0;
}