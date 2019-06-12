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
    Q_PROPERTY(int thermometer READ thermometer WRITE setThermometer NOTIFY thermometerChanged)
    Q_PROPERTY(int potentiometer READ potentiometer WRITE setPotentiometer NOTIFY potentiometerChanged)
    Q_PROPERTY(int adc_extern READ adc_extern WRITE setAdcExtern NOTIFY adcExternChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void terminate();

    //LED 0: Para que la view lea el estado del led
    uint8_t ledState();
    bool relay0();
    bool relay1();
    bool relay2();
    bool relay3();
    uint16_t thermometer();
    uint16_t potentiometer();
    uint16_t adc_extern();

signals:
    //LED 0: Señal que avisa que el led cambio de estado
    void ledStateChanged();
    void relaysChanged();
    void thermometerChanged();
    void potentiometerChanged();
    void adcExternChanged();

public slots:
    void changeButtonState(int index, bool pressed);
    void changeIn(int index, bool checked);
    void setLedState(const int state);
    void setRelays(const int index);
    void setThermometer(const int value);
    void setPotentiometer(const int value);
    void setAdcExtern(const int value);

private:
    uint8_t* data;
    led_t led;
    bool relays[RELAYS];
    uint16_t thermometerValue;
    uint16_t potentiometerValue;
    uint16_t adcExternValue;
    LedsThread* ledsThread;
    RelaysThread* relaysThread;
    QSharedMemory sharedMemory;
    key_t getKey();
    uint8_t* init_shared_memory();
};

#endif // INFO2GUIAPPLICATION_H
