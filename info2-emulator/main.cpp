#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>
#include "info2guiapplication.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    Info2GuiApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/digital-7.ttf");
    QFontDatabase::addApplicationFont(":/subway-ticker.regular.ttf");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("app", &app);
    engine.load(url);

    app.exec();
    app.terminate();
    return 0;
}
