#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>
#include <QTimer>
#include <QSharedMemory>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "ledsthread.h"
#include "relaysthread.h"
#include "components.h"

class Info2GuiApplication : public QGuiApplication
{
    Q_OBJECT
    Q_PROPERTY(int ledState READ ledState WRITE setLedState NOTIFY ledStateChanged)
    Q_PROPERTY(bool relay0 READ relay0 WRITE setRelays NOTIFY relaysChanged)
    Q_PROPERTY(bool relay1 READ relay1 WRITE setRelays NOTIFY relaysChanged)
    Q_PROPERTY(bool relay2 READ relay2 WRITE setRelays NOTIFY relaysChanged)
    Q_PROPERTY(bool relay3 READ relay3 WRITE setRelays NOTIFY relaysChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void terminate();

    //LED 0: Para que la view lea el estado del led
    bool ledState();
    bool relay0();
    bool relay1();
    bool relay2();
    bool relay3();

signals:
    //LED 0: Señal que avisa que el led cambio de estado
    void ledStateChanged();
    void relaysChanged();

public slots:
    void changeButtonState(int index, bool pressed);
    void changeIn(int index, bool checked);
    void setLedState(const bool state);
    void setRelays(const int index);

private:
    char* data;
    bool led = false;
    bool relays[RELAYS];
    LedsThread* ledsThread;
    RelaysThread* relaysThread;
    QSharedMemory sharedMemory;
    key_t getKey();
    char* init_shared_memory();
};

#endif // INFO2GUIAPPLICATION_H
