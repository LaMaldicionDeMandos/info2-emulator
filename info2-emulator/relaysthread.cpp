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
    /*
    bool isOn = LED(LED0);
    if (isOn != this->on) {
        this->on = isOn;
        this->changeLed(on);
    }
    */
}
