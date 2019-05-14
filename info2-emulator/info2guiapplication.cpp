#include "info2guiapplication.h"

Info2GuiApplication::Info2GuiApplication(int argc, char* argv[]):  QGuiApplication (argc, argv){

}
void Info2GuiApplication::setButtonName(const QString &name) {
    button_name = name;
}

QString Info2GuiApplication::buttonName() {
    return button_name;
}
