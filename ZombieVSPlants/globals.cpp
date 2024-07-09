#include "globals.h"

QTcpSocket *clientS =  new QTcpSocket();
int zamby=0;
int plant=0;
<<<<<<< HEAD
int locBrain=0;
int lockSun=0;
int Branis=0;
int Suns=0;
QHash<int , int> gamehash;
void setVal(){
    for (int i=1 ; i<=72 ; i++){
        gamehash.insert(i,0);
=======
QHash<int, int> gameHash;

void initializeGlobals() {
    for (int i = 1; i <= 72; ++i) {
        gameHash.insert(i, 0);
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
    }
}
