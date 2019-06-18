#ifndef DISPLAY7_H
#define DISPLAY7_H

#include <QThread>
#include "components.h"

#define DISPLAYS 2

class Display7: public QThread
{
    Q_OBJECT
signals:
    void changeDisplay( int index );
private:
    void run();
    uint8_t* data;
    uint32_t displays[DISPLAYS];
private slots:
    void evaluateDisplays();
public:
    Display7(uint8_t* data);
};

#endif // DISPLAY7_H
