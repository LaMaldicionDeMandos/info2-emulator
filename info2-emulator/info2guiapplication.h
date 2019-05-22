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
        Q_PROPERTY(int relayState READ relayState WRITE setRelayState NOTIFY relayStateChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void terminate();

    //LED 0: Para que la view lea el estado del led
    bool ledState();

    int relayState();

signals:
    //LED 0: Señal que avisa que el led cambio de estado
    void ledStateChanged();
    void relayStateChanged();

public slots:
    void changeButtonState(int index, bool pressed);
    void changeIn(int index, bool checked);
    void setLedState(const bool state);
    void setRelayState(const int state);

private:
    char* data;
    bool led = false;
    int relay = 0;
    LedsThread* ledsThread;
    QSharedMemory sharedMemory;
    key_t getKey();
    char* init_shared_memory();
};

#endif // INFO2GUIAPPLICATION_H
