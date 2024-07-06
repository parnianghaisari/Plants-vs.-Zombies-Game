#include "signup.h"

SignUp::SignUp()
{

}

void SignUp::sign(Users user)
{
    QString filep = "SignUpInformation.json";
    JsonManager sig(filep);
    sig.loadData();
    sig.addUsers(user);
    sig.saveData();
}
