#include "globals.h"

QTcpSocket *clientS =  new QTcpSocket();

int zamby=0;
int plant=0;
int locBrain=0;
int lockSun=0;
int Branis=0;
int Suns=0;
QHash<int , int> gamehash;
void setVal(){
    for (int i=1 ; i<=72 ; i++){
        gamehash.insert(i,0);
    }
}
