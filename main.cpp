#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "atomify.h"
#include "states.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Atomify>("Atomify", 1, 0, "Atomify");
    qmlRegisterType<States>("Atomify", 1, 0, "States");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
