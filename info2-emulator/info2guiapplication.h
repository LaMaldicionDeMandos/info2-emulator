#ifndef INFO2GUIAPPLICATION_H
#define INFO2GUIAPPLICATION_H

#include <QGuiApplication>
#include <QTimer>

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
    QString button_name;
    QTimer* timer;
};

#endif // INFO2GUIAPPLICATION_H
