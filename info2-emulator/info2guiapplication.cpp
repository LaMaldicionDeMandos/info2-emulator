#include "info2guiapplication.h"
#include <iostream>

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    uint8_t* data = init_shared_memory();
    this->data = data;
    for(int i = 0; i < COMPONENT_COUNT; i++) this->data[i] = 0;
    this->ledsThread = new LedsThread(data);
    this->relaysThread = new RelaysThread(data);
    QObject::connect((this->ledsThread), SIGNAL(changeLed(int)), this, SLOT(setLedState(int)), Qt::QueuedConnection);
    QObject::connect((this->relaysThread), SIGNAL(changeRelay(int)), this, SLOT(setRelays(int)), Qt::QueuedConnection);
    this->ledsThread->start();
    this->relaysThread->start();
}

void Info2GuiApplication::setLedState(const int state) {
    led.led = static_cast<uint8_t>(state);
    emit ledStateChanged();
}

void Info2GuiApplication::setRelays(const int index) {
    relays[index] = RELAY(index);
    emit relaysChanged();
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
}

// Inicialización de la shared memory
key_t Info2GuiApplication::getKey() {
    key_t key;
    if ((key = ftok("/", 'l')) == -1) {
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
