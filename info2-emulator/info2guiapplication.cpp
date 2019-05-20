#include "info2guiapplication.h"
#include <iostream>

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    char* data = init_shared_memory();
    this->data = data;
    LED(0) = 0;
    for(int i = 0; i < 0; i++) this->data[i] = 0;
    this->ledsThread = new LedsThread(data);
    QObject::connect((this->ledsThread), SIGNAL(changeLed(bool)), this, SLOT(setLedState(bool)), Qt::QueuedConnection);
    this->ledsThread->start();
}

void Info2GuiApplication::setLedState(const bool state) {
    led = state;
    emit ledStateChanged();
}

bool Info2GuiApplication::ledState() {
    return led;
}

void Info2GuiApplication::changeButtonState(int index, bool pressed) {
    BUTTON(index) = pressed;
    std::cout << "BUTTON_" << index << "=" << +BUTTON(index) << std::endl;
}

void Info2GuiApplication::terminate() {
    this->ledsThread->quit();
    this->ledsThread->wait();
}

// Inicialización de la shared memory
key_t Info2GuiApplication::getKey() {
    key_t key;
    if ((key = ftok("/", 'f')) == -1) {
        perror("ftok fails\n");
        return -1;
    }
    return key;
}

char* Info2GuiApplication::init_shared_memory() {
    int shmid;

     key_t key;
    if ((key = getKey()) == -1) return nullptr;

     if ((shmid = shmget(key, MEMORY_SIZE, IPC_CREAT | 0644)) == -1) {
        perror("memory segment creation fails\n");
        return nullptr;
    }

     if (shmid < 0) exit(1);
    char* data = static_cast<char*>(shmat(shmid, nullptr, 0));
    return data;
}
