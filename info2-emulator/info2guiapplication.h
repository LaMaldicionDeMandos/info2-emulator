#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>

class Info2GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    explicit Info2GuiApplication(int argc, char* argv[]);
};

#endif // INFO2GUIAPPLICATION_H
