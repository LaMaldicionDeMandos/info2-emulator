#include "display7.h"
#include <QTimer>

Display7::Display7(uint8_t* data)
{
    this->data = data;
}

void Display7::run() {
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(evaluateDisplays()), Qt::DirectConnection);
    timer.setInterval(10);
    timer.start();   // puts one event in the threads event queue
    exec();
    timer.stop();
}

void Display7::evaluateDisplays() {
    for (int i = 0; i < DISPLAYS; i++) {
         bool isOn = DSP(i);
         if (isOn != displays[i]) {
             this->displays[i] = isOn;
             this->changeDisplay(i);
         }
    }
}
