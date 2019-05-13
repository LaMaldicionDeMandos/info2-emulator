#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DATA_SIZE 4
#define MEMORY_SIZE sizeof(int) * DATA_SIZE

key_t getKey() {
    key_t key;
    if ((key = ftok("/", 's')) == -1) {
        perror("ftok fails\n");
        return -1;
    }
    return key;
}

int* init_shared_memory() {
    int shmid;

    key_t key;
    if ((key = getKey()) == -1) return nullptr;

    if ((shmid = shmget(key, MEMORY_SIZE, IPC_CREAT | 0644)) == -1) {
        perror("memory segment creation fails\n");
        return nullptr;
    }

    if (shmid < 0) exit(1);
    return static_cast<int*>(shmat(shmid, nullptr, 0));

}


int main(int argc, char *argv[])
{
    int* data = nullptr;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    data = init_shared_memory();

    if (data == nullptr) {
        return 0;
    }

    return app.exec();
}
