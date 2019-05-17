#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>
#include <QTimer>
#include <QSharedMemory>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "ledsthread.h"
#include "components.h"

class Info2GuiApplication : public QGuiApplication
{
    Q_OBJECT
    Q_PROPERTY(int ledState READ ledState WRITE setLedState NOTIFY ledStateChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void terminate();

    //LED 0: Para que la view lea el estado del led
    bool ledState();

signals:
    //LED 0: Señal que avisa que el led cambio de estado
    void ledStateChanged();

public slots:
    void changeButtonState(int index, bool pressed);
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
