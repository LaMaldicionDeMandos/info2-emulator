#include "info2guiapplication.h"

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(incrementName()));
    timer->start(1000);
    data = init_shared_memory();
}
void Info2GuiApplication::setButtonName(const QString &name) {
    button_name = name;
    emit buttonNameChanged();
}

QString Info2GuiApplication::buttonName() {
    return button_name;
}

void Info2GuiApplication::incrementName() {
    this->counter++;
    *this->data+= 1;
    setButtonName(QString("Tick: %1 - Global tick: %2").arg(this->counter).arg(*this->data));
}

key_t Info2GuiApplication::getKey() {
    key_t key;
    if ((key = ftok("/", 's')) == -1) {
        perror("ftok fails\n");
        return -1;
    }
    return key;
}

int* Info2GuiApplication::init_shared_memory() {
    int shmid;

     key_t key;
    if ((key = getKey()) == -1) return nullptr;

     if ((shmid = shmget(key, sizeof (int), IPC_CREAT | 0644)) == -1) {
        perror("memory segment creation fails\n");
        return nullptr;
    }

     if (shmid < 0) exit(1);
    return static_cast<int*>(shmat(shmid, nullptr, 0));
}
