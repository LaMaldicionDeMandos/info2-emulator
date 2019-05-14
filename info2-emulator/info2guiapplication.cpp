#include "info2guiapplication.h"

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(incrementName()));
    timer->start(1000);
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
    setButtonName(QString("Tick: %1").arg(this->counter));
}
