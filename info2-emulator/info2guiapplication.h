#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>
#include <QTimer>
#include <QSharedMemory>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define LED_ON_COLOR "#dc2c2c"

class Info2GuiApplication : public QGuiApplication
{
    Q_OBJECT
    Q_PROPERTY(QString buttonName READ buttonName WRITE setButtonName NOTIFY buttonNameChanged)
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
    void setButtonName(const QString &name);

    QString buttonName();

signals:
    void buttonNameChanged();

public slots:
    void incrementName();

private:
    int counter = 0;
    int* data;
    QString button_name;
    QTimer* timer;
    QSharedMemory sharedMemory;
    key_t getKey();
    int* init_shared_memory();
};

#endif // INFO2GUIAPPLICATION_H
