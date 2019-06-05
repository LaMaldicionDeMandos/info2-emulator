#include "info2guiapplication.h"
#include <iostream>

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    uint8_t* data = init_shared_memory();
    this->data = data;
    for(int i = 0; i < COMPONENT_COUNT; i++) this->data[i] = 0;
    this->ledsThread = new LedsThread(data);
    this->relaysThread = new RelaysThread(data);
    QObject::connect((this->ledsThread), SIGNAL(changeLed(uint8_t)), this, SLOT(setLedState(uint8_t)), Qt::QueuedConnection);
    QObject::connect((this->relaysThread), SIGNAL(changeRelay(int)), this, SLOT(setRelays(int)), Qt::QueuedConnection);
    this->ledsThread->start();
    this->relaysThread->start();
}

void Info2GuiApplication::setLedState(const uint8_t state) {
    led = state;
    emit ledStateChanged();
}

void Info2GuiApplication::setRelays(const int index) {
    relays[index] = RELAY(index);
    emit relaysChanged();
}

void Info2GuiApplication::setThermometer(const int value) {
    thermometerValue = value;
    THERMOMETER_TYPE thermometerData;
    thermometerData.value = thermometerValue;
    this->data[THERMOMETER] = thermometerData.bytes[0];
    this->data[THERMOMETER + 1] = thermometerData.bytes[1];
    std::cout << "TH = " << thermometerValue << std::endl;

    emit thermometerChanged();
}

uint8_t Info2GuiApplication::ledState() {
    return led;
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

void Info2GuiApplication::changeButtonState(int index, bool pressed) {
    led_t led;
    led.led = this->ledState();
    if (pressed)
        switch (index) {
        case 0: led.bits.red = !led.bits.red;break;
        case 1: led.bits.green = !led.bits.green;break;
        case 2: led.bits.blue = !led.bits.blue;break;
        }
    this->setLedState(led.led);

    BUTTON(index) = pressed;
    std::cout << "BUTTON_" << index << "=" << +BUTTON(index) << std::endl;
    std::cout << "RED: " << +led.bits.red << std::endl;
    std::cout << "GREEN: " << +led.bits.green << std::endl;
    std::cout << "BLUE: " << +led.bits.blue << std::endl;
}

void Info2GuiApplication::changeIn(int index, bool checked) {
    IN(index) = checked;
    std::cout << "IN_" << index << "=" << +IN(index) << std::endl;
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
    if ((key = ftok("/", 'i')) == -1) {
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
