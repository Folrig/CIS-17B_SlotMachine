#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>
#include <QSound>

class Observer
{
public:
    Observer();
    ~Observer();
    QString slotSymbols[7] = { "A", "B", "C", "D", "E", "F", "G" };
    QString assignSymbol(int);
    int assignWin(int, int, int, int);

private:

};

#endif // OBSERVER_H
