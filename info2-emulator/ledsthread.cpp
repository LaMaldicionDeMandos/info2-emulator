#include "ledsthread.h"
#include <QTimer>
#include <iostream>

LedsThread::LedsThread(uint8_t* data)
{
    this->data = data;
}

void LedsThread::run() {
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(evaluateLed()), Qt::DirectConnection);
    timer.setInterval(10);
    timer.start();   // puts one event in the threads event queue
    exec();
    timer.stop();
}

void LedsThread::evaluateLed() {
    int state = LED(LED0);
    if (state != this->state) {
        this->state = state;
        this->changeLed(state);
    }
}
