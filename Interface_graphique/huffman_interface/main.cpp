#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "test.h"

int main(int argc, char *argv[])
{

    testParcoursArbre();
    testSuppresionArbre();
    testCopieArbre();
    testFusionArbre();
    testEtiquette();
    //testDecompositionArbre();
    testAjoutAuto();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
