#ifndef RELAYSTHREAD_H
#define RELAYSTHREAD_H

#include <QThread>
#include "components.h"

#define RELAYS 4

class RelaysThread: public QThread
{
    Q_OBJECT
signals:
    void changeRelay( int index );
private:
    void run();
    uint8_t* data;
    bool relays[RELAYS];
private slots:
    void evaluateRelays();
public:
    RelaysThread(uint8_t* data);
};

#endif // RELAYSTHREAD_H
