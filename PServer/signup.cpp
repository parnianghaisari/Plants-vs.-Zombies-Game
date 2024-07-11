#include "signup.h"

#include <QDebug>

SignUp::SignUp()
{

}

void SignUp::sign(Users user)
{
    QString filep = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
    JsonManager sig(filep);
    sig.loadData();
    sig.addUsers(user);
    sig.saveData();
}
