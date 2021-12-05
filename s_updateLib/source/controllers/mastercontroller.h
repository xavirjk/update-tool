#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include "commandcontroller.h"
#include "navigationController.h"
#include "models/s_updatelib.h"
#include <s_updateLib_global.h>

using namespace s_update::models;

namespace s_update {
namespace controllers {

class S_UPDATELIB_EXPORT MasterController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ui_title READ sysTitle CONSTANT)
    Q_PROPERTY(s_update::controllers::NavigationController* ui_navigator READ navigationController CONSTANT)
    Q_PROPERTY(s_update::controllers::CommandController* ui_commander READ commandController CONSTANT)
    Q_PROPERTY(s_update::models::S_updateLib* ui_update READ updateLib CONSTANT)

public:
    explicit MasterController(QObject *parent = nullptr);
    CommandController *commandController();
    NavigationController *navigationController();
    S_updateLib *updateLib();
    const QString &sysTitle()const;
    ~MasterController();

public slots:
    void quitApplication();


signals:
    void killEngine();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}


#endif // MASTERCONTROLLER_H
