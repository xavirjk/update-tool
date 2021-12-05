#ifndef S_UPDATELIB_H
#define S_UPDATELIB_H

#include <QObject>
#include <QScopedPointer>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include "s_updateLib_global.h"
namespace s_update {
namespace models {
class S_UPDATELIB_EXPORT S_updateLib: public QObject
{
    Q_OBJECT
public:
    explicit S_updateLib(QObject *parent = nullptr);
    ~S_updateLib();
public slots:
    void initiateUpdate();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;

signals:
    void quitApp();
};

}}


#endif // S_UPDATELIB_H
