#include "info2guiapplication.h"

#define LED data[1]

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    this->data = init_shared_memory();
    if (this->data == 0) {
        perror("No pudo crear la shared memory");
        exit(1);
    }
    LedsThread thread(this->data);
    this->ledsThread = &thread;
    QObject::connect((this->ledsThread), SIGNAL(changeLed(bool)), this, SLOT(changeLedState(bool)), Qt::QueuedConnection);
    this->ledsThread->start();
}

void Info2GuiApplication::setLedState(const bool state) {
    led = state;
    emit ledStateChanged();
}

bool Info2GuiApplication::ledState() {
    return led;
}

void Info2GuiApplication::changeLedState(bool state){
    setLedState(state);
}

void Info2GuiApplication::terminate() {
    this->ledsThread->quit();
    this->ledsThread->wait();
}

key_t Info2GuiApplication::getKey() {
    key_t key;
    if ((key = ftok("/", 'b')) == -1) {
        perror("ftok fails\n");
        return -1;
    }
    return key;
}

void* Info2GuiApplication::init_shared_memory() {
    int shmid;

     key_t key;
    if ((key = getKey()) == -1) return nullptr;

     if ((shmid = shmget(key, 2, IPC_CREAT | 0644)) == -1) {
        perror("memory segment creation fails\n");
        return nullptr;
    }

     if (shmid < 0) exit(1);
    void* data = shmat(shmid, nullptr, 0);
    int* mm = (int*)(data);
    return mm;
}
