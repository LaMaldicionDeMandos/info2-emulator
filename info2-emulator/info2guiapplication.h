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
    Q_PROPERTY(bool relaysState0 READ relaysState0 WRITE setRelaysState NOTIFY relaysStateChanged)
    Q_PROPERTY(bool relaysState1 READ relaysState1 WRITE setRelaysState NOTIFY relaysStateChanged)
    Q_PROPERTY(bool relaysState2 READ relaysState2 WRITE setRelaysState NOTIFY relaysStateChanged)
    Q_PROPERTY(bool relaysState3 READ relaysState3 WRITE setRelaysState NOTIFY relaysStateChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void terminate();

    //LED 0: Para que la view lea el estado del led
    bool ledState();
    bool relaysState0();
    bool relaysState1();
    bool relaysState2();
    bool relaysState3();

signals:
    //LED 0: Señal que avisa que el led cambio de estado
    void ledStateChanged();
    void relaysStateChanged();

public slots:
    void changeButtonState(int index, bool pressed);
    void changeIn(int index, bool checked);
    void setLedState(const bool state);
    void setRelaysState(const int index);

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
