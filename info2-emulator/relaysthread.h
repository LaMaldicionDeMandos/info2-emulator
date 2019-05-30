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
    char* data;
    bool relays[RELAYS];
private slots:
    void evaluateRelays();
public:
    RelaysThread(char* data);
};

#endif // RELAYSTHREAD_H
