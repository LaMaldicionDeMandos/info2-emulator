#include "info2guiapplication.h"
#include <iostream>

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    uint8_t* data = init_shared_memory();
    this->data = data;
    for(int i = 0; i < COMPONENT_COUNT; i++) this->data[i] = 0;
    this->ledsThread = new LedsThread(data);
    this->relaysThread = new RelaysThread(data);
    this->displaysThread = new Display7(data);
    this->lcdsThread = new LCDThread(data);
    QObject::connect((this->ledsThread), SIGNAL(changeLed(int)), this, SLOT(setLedState(int)), Qt::QueuedConnection);
    QObject::connect((this->relaysThread), SIGNAL(changeRelay(int)), this, SLOT(setRelays(int)), Qt::QueuedConnection);
    QObject::connect((this->displaysThread), SIGNAL(changeDisplay(int)), this, SLOT(setDisplays(int)), Qt::QueuedConnection);
    QObject::connect((this->lcdsThread), SIGNAL(changeDisplay0(QString)), this, SLOT(setLcds0(QString)), Qt::QueuedConnection);
    QObject::connect((this->lcdsThread), SIGNAL(changeDisplay1(QString)), this, SLOT(setLcds1(QString)), Qt::QueuedConnection);
    this->ledsThread->start();
    this->relaysThread->start();
    this->displaysThread->start();
    this->lcdsThread->start();
}

void Info2GuiApplication::setLedState(const int state) {
    led.led = static_cast<uint8_t>(state);
    emit ledStateChanged();
}

void Info2GuiApplication::setRelays(const int index) {
    relays[index] = RELAY(index);
    emit relaysChanged();
}

void Info2GuiApplication::setDisplays(const int index) {
    AD_X2_TYPE dsp;
    for (int i = 0; i < 4; i++) {
        dsp.bytes[i] = DSP(index, i);
    }
    displays[index] = dsp.value;
    emit displaysChanged();
}

void Info2GuiApplication::setLcds0(const QString lcdString) {
    lcds[0] = QString::fromStdString(lcdsThread->lcd(0));
    emit lcdsChanged();
}

void Info2GuiApplication::setLcds1(const QString lcdString) {
    lcds[0] = QString::fromStdString(lcdsThread->lcd(1));
    emit lcdsChanged();
}

void Info2GuiApplication::setThermometer(const int value) {
    thermometerValue = static_cast<uint16_t>(value);
    AD_TYPE thermometerData;
    thermometerData.value = thermometerValue;
    this->data[THERMOMETER] = thermometerData.bytes[0];
    this->data[THERMOMETER + 1] = thermometerData.bytes[1];

    emit thermometerChanged();
}

void Info2GuiApplication::setPotentiometer(const int value) {
    potentiometerValue = static_cast<uint16_t>(value);
    AD_TYPE potentiometerData;
    potentiometerData.value = potentiometerValue;
    this->data[POTENTIOMETER] = potentiometerData.bytes[0];
    this->data[POTENTIOMETER + 1] = potentiometerData.bytes[1];

    emit potentiometerChanged();
}

void Info2GuiApplication::setAdcExtern(const int value) {
    adcExternValue = static_cast<uint16_t>(value);
    AD_TYPE adcExternData;
    adcExternData.value = adcExternValue;
    this->data[ADC_EXTERN] = adcExternData.bytes[0];
    this->data[ADC_EXTERN + 1] = adcExternData.bytes[1];

    emit adcExternChanged();
}

uint8_t Info2GuiApplication::ledState() {
    return led.led;
}

bool Info2GuiApplication::relay0() {
    return relays[0];
}

bool Info2GuiApplication::relay1() {
    return relays[1];
}

bool Info2GuiApplication::relay2() {
    return relays[2];
}

bool Info2GuiApplication::relay3() {
    return relays[3];
}

int Info2GuiApplication::dsp0() {
    return displays[0];
}

int Info2GuiApplication::dsp1() {
    return displays[1];
}

QString Info2GuiApplication::lcd0() {
    return lcds[0];
}

QString Info2GuiApplication::lcd1() {
    return lcds[1];
}

uint16_t Info2GuiApplication::thermometer() {
    return thermometerValue;
}

uint16_t Info2GuiApplication::potentiometer() {
    return potentiometerValue;
}

uint16_t Info2GuiApplication::adc_extern() {
    return adcExternValue;
}

void Info2GuiApplication::changeButtonState(int index, bool pressed) {
    BUTTON(index) = pressed;
}

void Info2GuiApplication::changeIn(int index, bool checked) {
    IN(index) = checked;
}

void Info2GuiApplication::terminate() {
    this->ledsThread->quit();
    this->ledsThread->wait();

    this->relaysThread->quit();
    this->relaysThread->wait();

    this->displaysThread->quit();
    this->displaysThread->wait();

    this->lcdsThread->quit();
    this->lcdsThread->wait();
}

// Inicialización de la shared memory
key_t Info2GuiApplication::getKey() {
    key_t key;
    if ((key = ftok("/", 'n')) == -1) {
        perror("ftok fails\n");
        return -1;
    }
    return key;
}

uint8_t* Info2GuiApplication::init_shared_memory() {
    int shmid;

     key_t key;
    if ((key = getKey()) == -1) return nullptr;

     if ((shmid = shmget(key, MEMORY_SIZE, IPC_CREAT | 0644)) == -1) {
        perror("memory segment creation fails\n");
        return nullptr;
    }

     if (shmid < 0) exit(1);
    uint8_t* data = static_cast<uint8_t*>(shmat(shmid, nullptr, 0));
    return data;
}
