#include "info2guiapplication.h"

#define LED this->data[1]

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    char* data = init_shared_memory();
    this->data = data;
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

void Info2GuiApplication::changeLedState(){
    LED = !LED;
}

void Info2GuiApplication::changeButtonState(bool pressed) {
    LED = !pressed;
}

void Info2GuiApplication::terminate() {
    this->ledsThread->quit();
    this->ledsThread->wait();
}

key_t Info2GuiApplication::getKey() {
    key_t key;
    if ((key = ftok("/", 'd')) == -1) {
        perror("ftok fails\n");
        return -1;
    }
    return key;
}

char* Info2GuiApplication::init_shared_memory() {
    int shmid;

     key_t key;
    if ((key = getKey()) == -1) return nullptr;

     if ((shmid = shmget(key, sizeof (char) * 2, IPC_CREAT | 0644)) == -1) {
        perror("memory segment creation fails\n");
        return nullptr;
    }

     if (shmid < 0) exit(1);
    char* data = static_cast<char*>(shmat(shmid, nullptr, 0));
    return data;
}
