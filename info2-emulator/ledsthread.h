#ifndef LEDSTHREAD_H
#define LEDSTHREAD_H

#include <QThread>
#include "components.h"

#define LED0 0

class LedsThread: public QThread
{
    Q_OBJECT
signals:
    void changeLed( bool state );
private:
    void run();
    uint8_t* data;
    bool on;
private slots:
    void evaluateLed();
public:
    LedsThread(uint8_t* data);
};

#endif // LEDSTHREAD_H
