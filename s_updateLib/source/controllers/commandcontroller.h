#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <s_updateLib_global.h>
#include "navigationController.h"
#include "models/s_updatelib.h"
using namespace s_update::models;

namespace s_update {
namespace controllers {
class  S_UPDATELIB_EXPORT CommandController : public QObject
{

    Q_OBJECT
public:
    explicit CommandController(QObject *parent = nullptr, NavigationController *navigationController = nullptr, S_updateLib *updateLib = nullptr);
    ~CommandController();


signals:

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}


#endif // MASTERCONTROLLER_H
