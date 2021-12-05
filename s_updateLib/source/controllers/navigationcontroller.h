#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H
#include <QObject>
#include <s_updateLib_global.h>
namespace s_update {
namespace controllers {
class S_UPDATELIB_EXPORT NavigationController: public QObject {
    Q_OBJECT
public:
    NavigationController(QObject *parent = nullptr):
        QObject(parent){}
    ~NavigationController(){}
signals:

};

}

}

#endif // NAVIGATIONCONTROLLER_H
