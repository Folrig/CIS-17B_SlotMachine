#include "observer.h"

Observer::Observer()
{

}

Observer::~Observer()
{

}

QString Observer::assignSymbol(int x)   //listen to reel spin and inform GUI of equivalent letter display
{
    return slotSymbols[x];
}

int Observer::assignWin(int x, int y, int z, int bet)
{
    //interpret reel results and send them to the coin amounts
    //char slotSymbols[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    QString reelOne = slotSymbols[x];
    QString reelTwo = slotSymbols[y];
    QString reelThree = slotSymbols[z];

    if (reelOne == "A" && reelTwo == "A" && reelThree == "A")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet;
    }
    else if (reelOne == "B" && reelTwo == "B" && reelThree == "B")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 2;
    }
    else if (reelOne == "C" && reelTwo == "C" && reelThree == "C")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 3;
    }
    else if (reelOne == "D" && reelTwo == "D" && reelThree == "D")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 4;
    }
    else if (reelOne == "E" && reelTwo == "E" && reelThree == "E")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 5;
    }
    else if (reelOne == "F" && reelTwo == "F" && reelThree == "F")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 6;
    }
    else if (reelOne == "G" && reelTwo == "G" && reelThree == "G")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 7;
    }
    else if (reelOne == "A" && reelTwo == "B" && reelThree == "C")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 8;
    }
    else if (reelOne == "D" && reelTwo == "E" && reelThree == "F")
    {
        QSound::play(":/SoundEffects/payoff.wav");
        return bet * 9;
    }
    else
    {
        return 0;
    }
}
