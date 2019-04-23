#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QThread>
#include <QMessageBox>
#include <qtconcurrentrun.h>
#include "observer.h"
#include "reel.h"
using namespace QtConcurrent;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Observer machine;

    Reel reelOne;
    Reel reelTwo;
    Reel reelThree;

    int coinsRemaining = 50;
    int currentBet = 0;

private slots:
    void on_spinReelsButton_clicked();
    void on_betCoinButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
