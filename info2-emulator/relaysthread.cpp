#include "relaysthread.h"
#include <QTimer>

RelaysThread::RelaysThread(char* data)
{
    this->data = data;
}

void RelaysThread::run() {
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(evaluateRelays()), Qt::DirectConnection);
    timer.setInterval(10);
    timer.start();   // puts one event in the threads event queue
    exec();
    timer.stop();
}

void RelaysThread::evaluateRelays() {
    for (int i = 0; i < RELAYS; i++) {
        bool isOn = RELAY(i);
        if (isOn != this->state[i]) {
            this->state[i] = isOn;
            this->changeState(i, this->state[i]);
        }
    }
}
