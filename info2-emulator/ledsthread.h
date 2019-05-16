#ifndef LEDSTHREAD_H
#define LEDSTHREAD_H

#include <QThread>

#define LED_0 1
class LedsThread: public QThread
{
    Q_OBJECT
signals:
    void changeLed( bool state );
private:
    void run();
    void* data;
    bool on;
private slots:
    void evaluateLed();
public:
    LedsThread(void* data);
};

#endif // LEDSTHREAD_H
