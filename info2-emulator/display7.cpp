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
    AD_X2_TYPE dsps[2];
    for (int i = 0; i < DISPLAYS; i++) {
        for (int j = 0; j < 4; j++) {
            dsps[i].bytes[j] = DSP(i,j);
        }
        if (displays[i] != dsps[i].value) {
            displays[i] = dsps[i].value;
            changeDisplay(i);
        }
    }
}
