#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>
#include<string>

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
private:
    QString button_name = "buttonNAme";
};

#endif // INFO2GUIAPPLICATION_H
