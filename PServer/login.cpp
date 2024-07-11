#include "login.h"

Login::Login()
{

}

QString Login::matchPSW(QString us, QString ps)
{
    QString filep = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
    JsonManager log(filep);
    log.loadData();
    for (int i = 0; i < log.getUsers().size(); ++i)
        if (us == log.getUsers()[i].userVal())
            if (ps == log.getUsers()[i].pswVal())
                return "1";
    return "0";
}

QString Login::matchPN(QString us, QString pn)
{
    QString filep = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
    JsonManager log(filep);
    log.loadData();
    for (int i = 0; i < log.getUsers().size(); ++i)
        if (us == log.getUsers()[i].userVal())
            if (pn == log.getUsers()[i].nameVal())
                return "1";
    return "0";
}

void Login::changePSW(QString us, QString Nps)
{
    QString filep = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
    JsonManager log(filep);
    log.loadData();
    for (int i = 0; i < log.getUsers().size(); ++i)
        if (us == log.getUsers()[i].userVal())
            log.getUsers()[i].pswVal() = Nps;
    log.saveData();
}
