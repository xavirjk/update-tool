#include "s_updatelib.h"
#include <QProcess>
#include <QCoreApplication>
#include <quazip/quazip.h>
#include <quazip/quazipfile.h>
#include <quazip/quazipfileinfo.h>

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
    QString app;

};
S_updateLib::S_updateLib(QObject *parent)
    :QObject(parent)
{
    implementation.reset(new Implementation(this));
}

void S_updateLib::initiateUpdate(){
    if(!QCoreApplication::arguments().contains("update")) return;
    implementation->app = QCoreApplication::arguments().at(3);
    implementation->scalmis = implementation->temp+"/"+implementation->app;
    QDir *dir = new QDir();
    const QString currentP = dir->currentPath();
    const QString scalmis = currentP+"/"+implementation->app+".exe";
    QFile file(scalmis);
    if(file.exists()){
        unzip();
        file.setFileName(currentP+"/_RELEASE");
        if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate))
            return;
        QString ver = QCoreApplication::arguments().at(1);
        QString vl = '"'+ver.toLocal8Bit()+'"';
        file.write("VERSION="+vl.toLocal8Bit());
        file.close();
        QProcess *process = new QProcess(this);
        process->start(scalmis);
    }
    emit quitApp();
}
void S_updateLib::unzip() const{
    QDir *dir = new QDir(implementation->scalmis);
    QuaZip zip(dir->path()+"/"+implementation->app+".zip");
    zip.open(QuaZip::mdUnzip);
    QuaZipFile fl(&zip);
    dir->setPath(dir->currentPath());
    dir->setPath(QDir::cleanPath(dir->filePath(QStringLiteral(".."))));
    for(bool f = zip.goToFirstFile(); f ; f = zip.goToNextFile()){;
        QuaZipFileInfo fileInfo;
        fl.getFileInfo(&fileInfo);
        if(fileInfo.name == implementation->app+"/") continue;
        fl.open(QIODevice::ReadOnly);
        QByteArray ba = fl.readAll();
        fl.close();
        if(fileInfo.name.endsWith("/")){
           dir->mkpath(fileInfo.name);
        }
        else {
            QFile out(dir->path()+"/"+fileInfo.name);
            if(!out.open(QIODevice::WriteOnly)) return;
            out.write(ba);
            out.close();
        }
    }
    zip.close();
}
S_updateLib::~S_updateLib(){}
}}
