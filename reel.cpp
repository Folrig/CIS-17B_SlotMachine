#include "reel.h"


Reel::Reel()
{
    //seed each reel randomly when created
    unsigned int seed = time(NULL);
    srand(seed);
}

Reel::~Reel()
{

}

int Reel::spinReels()
{
    //spin the reel to give a result of 0-6 to be sent to the observer
    int reelDisplay = rand() % 7;
    return reelDisplay;
}
