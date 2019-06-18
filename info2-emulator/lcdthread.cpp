#include "lcdthread.h"
#include <QTimer>

LCDThread::LCDThread(uint8_t* data)
{
    this->data = data;
}

void LCDThread::run() {
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(evaluateDisplays()), Qt::DirectConnection);
    timer.setInterval(10);
    timer.start();   // puts one event in the threads event queue
    exec();
    timer.stop();
}

void LCDThread::evaluateDisplays() {
    char lcds[2][16];
    for (int i = 0; i < LCDS; i++) {
        for (int j = 0; j < 16; j++) {
            lcds[i][j] = LCD(i,j);
        }
        std::string stringLcd = lcds[i];
        if (displays[i] != stringLcd) {
            displays[i] = stringLcd;
            changeDisplay(i);
        }
    }
}

std::string LCDThread::lcd(const int index) {
    return displays[index];
}
