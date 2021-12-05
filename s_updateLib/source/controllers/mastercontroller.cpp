#include "mastercontroller.h"
#include "QDebug"
namespace s_update{
namespace controllers {
class MasterController::Implementation{
public: Implementation(MasterController *_MasterController):
        masterController(_MasterController){
        navigationController = new NavigationController(masterController);
        updateLib = new S_updateLib(masterController);
        commandController = new CommandController(masterController,navigationController,updateLib);
        connect(updateLib, &S_updateLib::quitApp,masterController,&MasterController::quitApplication);

    }
    MasterController *masterController{nullptr};
    NavigationController *navigationController{nullptr};
    S_updateLib *updateLib{nullptr};
    CommandController *commandController{nullptr};
    QString title = "Scalmis Maintanance";
};

MasterController::MasterController(QObject *parent) : QObject(parent)
{
    implementation.reset(new Implementation(this));
}

const QString &MasterController::sysTitle()const{
    return implementation->title;
}

S_updateLib *MasterController::updateLib(){
    return implementation->updateLib;
}

CommandController *MasterController::commandController(){
    return implementation->commandController;
}

NavigationController *MasterController::navigationController(){
    return implementation->navigationController;
}

void MasterController::quitApplication(){
    emit killEngine();
}

MasterController::~MasterController(){}
}
}
