#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_COUNT 52
#define CARDS_PER_SUIT 13
#define HAND_SIZE 5
#define ROUND 100

// Card count from 0 to 51
// Suit 1: card_value[ 0 ] -> card_value[ 12 ] (2 to A)
// Suit 2: card_value[ 13 ] -> card_value[ 25 ] (2 to A)
// Suit 3: card_value[ 26 ] -> card_value[ 38 ] (2 to A)
// Suit 4: card_value[ 39 ] -> card_value[ 51 ] (2 to A)

// Get rank of a card ( 0 - 13 )
int getCardRank( int cardValue ) {
    return cardValue % 13;
}

// Hand Rank is max repeat of a certain card rank
// 1 == Unique
// 2 == Pair
// 3 == Three of a Kind
// 4 == Four Of A Kind
int getHandKind( int* handCardValues ) {
    int handCardRank[ 13 ];

    // Clear out handCardRank
    for ( int i = 0; i < 13; i++) {
        handCardRank[i] = 0;
    }

    // Loop through all cards in our hand
    //
    // The indexes of handCardRank ( i == 0 to 12 ) represents the possible ranks of the card ( 0 to 12 ).
    //
    // The value of handCardRank ( handCardRank[ index ] ) represents the amounts of card with rank 'index'
    // we have in our hand.
    //
    for ( int i = 0; i < 5; i++) {
        // i can be 0 to 4
        // handCardValues[ i ] can be 0 to 12
        // handCardRank can be 0 to 4
        handCardRank[ handCardValues[ i ] ] += 1;
    }

     // 'kind' là:
     // 1 == Unique ( mỗi card trên hand từ 0 đến 4 lặp lại 1 lần )
     // 2 == Pair ( có 1 rank trên hand lặp lại 2 lần )
     // 3 == Three of a Kind ( có 1 rank trên hand lặp lại 3 lần )
     // 4 == Four of a Kind ( có 1 rank trên hand lặp lại 4 lần )
     int kind = handCardRank[ 0 ];

     for ( int i = 1; i < 13; i++){
            if ( kind < handCardRank[ i ])
                kind = handCardRank[ i ];
     }

     return kind;
}


int  main()
{
    // http://stackoverflow.com/questions/21273550/how-does-srand-relate-to-rand-function
    // srand(time(NULL))

    /* Intializes random number generator */
    srand(time(NULL));
    // Play
    // Chơi 1000 lần
    //
    // roundResultValues[] chứa số lần mà mình đc:
    // - Unique ( roundResultValues[ 1 ]
    // - Pair   ( roundResultValues[ 2 ]
    // - Three of a Kind ( roundResultValues[ 3 ] )
    // - Four of a Kind  ( roundResultValues[ 4 ] )
    //
    double roundResultCounts[ 5 ];
    for ( int i = 0; i < 5; ++i ) {
        roundResultCounts[ i ] = 0;
    }

    int NUM_PLAY_ROUNDS = 2000000;
    // Chơi 1000 rounds
    for ( int j = 0; j < NUM_PLAY_ROUNDS; j++ ) {
        // Get 5 cards
        int hand[ 5 ];
        for ( int i = 0; i < 5; i++ ) {
            hand[ i ] = rand() % 52;
        }

        // Translate 5 cards to ranks
        int handRanks[ 5 ];
        for ( int i = 0; i < 5; i++ ) {
            handRanks[ i ] = getCardRank( hand[ i ] );
        }
        // Get round result
        // roundsResult có thể có các value sau:
        //
        // 1 == Unique ( mỗi card trên hand từ 0 đến 4 lặp lại 1 lần )
        // 2 == Pair ( có 1 rank trên hand lặp lại 2 lần )
        // 3 == Three of a Kind ( có 1 rank trên hand lặp lại 3 lần )
        // 4 == Four of a Kind ( có 1 rank trên hand lặp lại 4 lần )
        //
        // roundResult là handKind của mình, tức là số lần lặp maximum của 1 rank nào đó trên tay mình
        //
        int roundResult = getHandKind( handRanks );

        // If roundResult == 1 => we got Unique
        //     => increment the number of 'Unique' rounds by 1 ( roundResultValues[ 1 ] += 1 )
        // If roundResult == 2 => we got Pair
        //     => increment the number of 'Pair' rounds by 1 ( roundResultValues[ 2 ] += 1 )
        // If roundResult == 3 => we got Three of a Kind
        //     => increment the number of 'Three of a Kind' rounds by 1 ( rou +ndResultValues[ 3 ] += 1 )
        // If roundResult == 4 => we got Four of a Kind
        //     => increment the number of 'Four of a Kind' rounds by 1 ( roundResultValues[ 4 ] += 1 )
        //
        // + roundResultCounts[ 1 ]: Số lần mình đc Unique
        // + roundResultCounts[ 2 ]: Số lần mình đc Pair
        // + roundResultCounts[ 3 ]: Số lần mình đc Three of a Kind
        // + roundResultCounts[ 4 ]: Số lần mình đc Four of a Kind

        roundResultCounts[ roundResult ] = roundResultCounts[ roundResult ] + 1;
    }

    // Calculate probability
    // roundResultCounts[ i ] là số vòng mà handKind của mình là 'i'
    // + roundResultCounts[ 1 ]: Số lần mình đc Unique
    // + roundResultCounts[ 2 ]: Số lần mình đc Pair
    // + roundResultCounts[ 3 ]: Số lần mình đc Three of a Kind
    // + roundResultCounts[ 4 ]: Số lần mình đc Four of a Kind
    //
    // roundResultProbability[ i ] là probability mà mình thắng đc handKind là 'i'.
    //
    // i có thể mang các giá trị sau:
    //    + 1 - Unique:
    //        roundResultProbability[ 1 ] = roundResultCounts[ 1 ] / NUM_PLAY_ROUNDS
    //    + 2 - Pair:
    //        roundResultProbability[ 2 ] = roundResultCounts[ 2 ] / NUM_PLAY_ROUNDS
    //    + 3 - Three of a Kind:
    //        roundResultProbability[ 3 ] = roundResultCounts[ 3 ] / NUM_PLAY_ROUNDS
    //    + 4 - Four of a Kind:
    //        roundResultProbability[ 4 ] = roundResultCounts[ 4 ] / NUM_PLAY_ROUNDS
    //
    double roundResultProbability[ 5 ];
    for ( int i = 1; i < 5; i++ ) {
        roundResultProbability[ i ] = (double)roundResultCounts[ i ] / (double)NUM_PLAY_ROUNDS;
        printf(" the probability of kind %d is %f\n ", i, roundResultProbability[ i ] );
    }
}
