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
    if(file.exists()){
        dir->setPath(implementation->scalmis);
        file.setFileName(dir->path()+"/scalmis.zip");
        dir->setPath(dir->currentPath());
        dir->setPath(QDir::cleanPath(dir->filePath(QStringLiteral(".."))));
        QStringList arguments;
        arguments << "x"; // extract files and directories
        arguments << "-y"; // suppress questions
        arguments << QDir::toNativeSeparators(file.fileName());
        arguments << QDir::toNativeSeparators(dir->path());
        QProcess *process = new QProcess(this);
        process->start(program, arguments);
        process->waitForFinished(-1);

        if(QCoreApplication::arguments().length() == 2){
            file.setFileName(currentP+"/_RELEASE");
            if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate))
                return;
            QString ver = QCoreApplication::arguments().at(1);
            QString vl = '"'+ver.toLocal8Bit()+'"';
            file.write("VERSION="+vl.toLocal8Bit());
            file.close();
        }
        process = new QProcess();
        process->start(scalmis);
    }
    emit quitApp();
}
S_updateLib::~S_updateLib(){}
}}
