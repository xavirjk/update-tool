#include "commandcontroller.h"
namespace s_update {
namespace controllers {
class CommandController::Implementation{
public: Implementation(CommandController *_commandController, NavigationController *_navigationController, S_updateLib *_updateLib):
        commandController(_commandController),
        navigationController(_navigationController),
        updateLib(_updateLib)
    {

    }
    CommandController *commandController{nullptr};
    NavigationController *navigationController{nullptr};
    S_updateLib *updateLib{nullptr};
};
CommandController::CommandController(QObject *parent, NavigationController *navigationController, S_updateLib *updateLib) : QObject(parent)
{
    implementation.reset(new Implementation(this,navigationController,updateLib));

}
CommandController::~CommandController(){}

}}

