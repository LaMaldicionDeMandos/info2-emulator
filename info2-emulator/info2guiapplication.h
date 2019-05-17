#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>
#include <QTimer>
#include <QSharedMemory>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "ledsthread.h"

class Info2GuiApplication : public QGuiApplication
{
    Q_OBJECT
    Q_PROPERTY(int ledState READ ledState WRITE setLedState NOTIFY ledStateChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void terminate();
    bool ledState();

signals:
    void ledStateChanged();

public slots:
    void changeLedState();
    void setLedState(const bool state);

private:
    char* data;
    bool led = false;
    LedsThread* ledsThread;
    QSharedMemory sharedMemory;
    key_t getKey();
    char* init_shared_memory();
};

#endif // INFO2GUIAPPLICATION_H
