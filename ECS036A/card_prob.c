#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

double noInitProb(int deckSize, int copyCount, int handSize)
{
    double notDraw = 1;
    int excess = deckSize - copyCount;
    for (int drawNum = 1; drawNum <= handSize; drawNum++)
    {
        notDraw *= ((double)excess / deckSize);
        excess--;
        deckSize--;
    }
    return notDraw;
}

double noMulliganProb(int deckSize, int copyCount, int handSize, int mulligan)
{
    int currHand = handSize - mulligan;
    double notMulligan = 1;
    deckSize -= currHand + mulligan;
    int excess = deckSize - copyCount;

    for (int i = 1; i <= mulligan; i++)
    {
        notMulligan *= ((double)excess / deckSize);
        excess--;
        deckSize--;
    }

    return notMulligan;
}

double noTurnProb(int deckSize, int copyCount, int handSize, int turns)
{
    double noDraw = 1;
    deckSize -= handSize;
    int excess = deckSize - copyCount;

    for (int turnNum = 1; turnNum <= turns; turnNum++)
    {
        noDraw *= ((double)excess / deckSize);
        excess--;
        deckSize--;
    }

    return noDraw;
}

int main()
{
    int deckSize;
    int copyCount;
    int handSize;
    int mulligan;
    int turns;

    printf("Enter how many total cards there are in the deck: ");
    scanf("%d", &deckSize);

    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf("%d", &copyCount);

    printf("Enter your initial hand size: ");
    scanf("%d", &handSize);

    printf("Enter how many cards you are mulliganing: ");
    scanf("%d", &mulligan);

    printf("Enter what turn you want to draw the card by: ");
    scanf("%d", &turns);

    double notInit = noInitProb(deckSize, copyCount, handSize);
    double notMulligan = noMulliganProb(deckSize, copyCount, handSize, mulligan);
    double noDraw = noTurnProb(deckSize, copyCount, handSize, turns);
    double atLeastOne = 1 - (notInit * notMulligan * noDraw);

    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", turns, mulligan, atLeastOne);

    return 0;
}