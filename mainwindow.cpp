#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    //setup window with 50 coins and 0 current bet
    ui->setupUi(this);
    ui->coinsRemainingLabel->setNum(coinsRemaining);
    ui->currentBetAmount->setNum(currentBet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinReelsButton_clicked()
{
    //play game if bet is made
    if (currentBet > 0)
    {
        //send reels to 3 different threads and spin them randomly
        QFuture<int> reelOneValue = run(reelOne, Reel::spinReels);
        reelOneValue.waitForFinished();
        QFuture<int> reelTwoValue = run(reelTwo, Reel::spinReels);
        reelTwoValue.waitForFinished();
        QFuture<int> reelThreeValue = run(reelThree, Reel::spinReels);
        reelThreeValue.waitForFinished();

        //update the GUI to display the letters representing the random reel spins
        ui->reelOneLabel->setText(machine.assignSymbol(reelOneValue));
        ui->reelTwoLabel->setText(machine.assignSymbol(reelTwoValue));
        ui->reelThreeLabel->setText(machine.assignSymbol(reelThreeValue));

        //update the GUI coin displays
        ui->coinsWonLabel->setNum(machine.assignWin(reelOneValue, reelTwoValue, reelThreeValue, currentBet));
        ui->coinsRemainingLabel->setNum(coinsRemaining + machine.assignWin(reelOneValue, reelTwoValue, reelThreeValue, currentBet));

        //update the actual amount of coins and bets
        coinsRemaining = coinsRemaining + machine.assignWin(reelOneValue, reelTwoValue, reelThreeValue, currentBet);
        currentBet = 0;
        ui->currentBetAmount->setNum(currentBet);
    }
    //warn player to make a wager
    else
    {
        QMessageBox::warning(this, "No bet!", "Make sure to place a bet before you spin!");
    }

}

void MainWindow::on_betCoinButton_clicked()
{
    //allow player to bet up to 3 as long as they have coins
    if (currentBet < 3 && coinsRemaining > 0)
    {
        QSound::play(":/SoundEffects/insertcoin.wav");
        currentBet++;
        ui->currentBetAmount->setNum(currentBet);
        ui->coinsRemainingLabel->setNum(--coinsRemaining);
    }
    //inform player the max they can bet is 3 coins
    else if (currentBet == 3)
    {
        QMessageBox::warning(this, "Max Bet Reached", "The maximum bet on this machine is 3 coins. Good luck!");
    }
    //tell player they are out of coins and quit program
    else if (coinsRemaining == 0 && currentBet == 0)
    {
        QMessageBox::warning(this, "You're broke!", "Sorry, you have no coins left to place a bet! Have a nice day!");
        QApplication::quit();
    }
}
