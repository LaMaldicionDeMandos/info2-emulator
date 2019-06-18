#ifndef LCDTHREAD_H
#define LCDTHREAD_H

#include <QThread>
#include "components.h"
#include <iostream>

#define LCDS 2

class LCDThread: public QThread
{
    Q_OBJECT
signals:
    void changeDisplay( int index );
private:
    void run();
    uint8_t* data;
    std::string displays[LCDS];
private slots:
    void evaluateDisplays();
public:
    LCDThread(uint8_t* data);
    std::string lcd(const int index);
};

#endif // LCDTHREAD_H
