#include "s_updatelib.h"
#include <QDebug>
#include <QProcess>
#include <QCoreApplication>

namespace s_update {
namespace models {
class S_updateLib::Implementation{
public: Implementation(S_updateLib *_updateLib):
        updateLib(_updateLib)
    {
    }
    S_updateLib *updateLib{nullptr};
    QString temp = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QString scalmis = temp+"/scalmis";

};
S_updateLib::S_updateLib(QObject *parent)
    :QObject(parent)
{
    implementation.reset(new Implementation(this));
}

void S_updateLib::initiateUpdate(){
    const QString program = "C:/Program Files/WinRAR/WinRaR.exe";
    QDir *dir = new QDir();
    const QString currentP = dir->currentPath();
    const QString scalmis = currentP+"/scalmis.exe";
    QFile file(scalmis);
    qDebug()<<QCoreApplication::arguments();
    if(file.exists()){
        dir->setPath(implementation->scalmis);
        file.setFileName(dir->path()+"/scalmis.rar");
        QString zipped;
        if(file.exists()) zipped = file.fileName();
        else zipped = dir->path()+"/scalmis.zip";
        qDebug()<<"exists"<<zipped;
        QStringList arguments;
        arguments << "x"; // extract files and directories
        arguments << "-y"; // suppress questions
        arguments << QDir::toNativeSeparators(zipped);
        arguments << QDir::toNativeSeparators("C:/Program Files (x86)");
        QProcess *process = new QProcess(this);
        process->start(program, arguments);
        process->waitForFinished(-1);
        process = new QProcess();
        process->start(scalmis);
    }
    //emit quitApp();
}
S_updateLib::~S_updateLib(){}
}}
