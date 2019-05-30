#ifndef RELAYSTHREAD_H
#define RELAYSTHREAD_H

#include <QThread>
#include "components.h"

#define RELAYS 4

class RelaysThread: public QThread
{
    Q_OBJECT
signals:
    void changeState( int index, bool state );
private:
    void run();
    char* data;
    bool state[RELAYS];
private slots:
    void evaluateRelays();
public:
    RelaysThread(char* data);
};

#endif // RELAYSTHREAD_H
