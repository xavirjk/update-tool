#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include <QIcon>
#include "controllers/commandcontroller.h"
#include "controllers/mastercontroller.h"
#include "controllers/navigationController.h"
#include "models/s_updatelib.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    QGuiApplication app(argc, argv);
    QQuickWindow::setGraphicsApi(QSGRendererInterface::Software);

    qmlRegisterType<s_update::controllers::MasterController>("s_update", 1, 0,"MasterController");
    qmlRegisterType<s_update::controllers::CommandController>("s_update", 1, 0,"CommandController");
    qmlRegisterType<s_update::controllers::NavigationController>("s_update",1,0,"NavigationController");


    qmlRegisterType<s_update::models::S_updateLib>("s_update", 1, 0,"S_updateLib");

    s_update::controllers::MasterController masterController;
    QQmlApplicationEngine engine;
    QObject::connect(&masterController,&s_update::controllers::MasterController::killEngine,&QGuiApplication::quit);
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("masterController",&masterController);
    const QUrl url(QStringLiteral("qrc:/views/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
