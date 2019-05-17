#include "ledsthread.h"
#include <QTimer>
#include <stdio.h>

LedsThread::LedsThread(char* data)
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
    bool isOn = this->data[LED_0];
    if (isOn != this->on) {
        printf("Change LED: %d\n", isOn);
        this->on = isOn;
        this->changeLed(on);
    }
}
