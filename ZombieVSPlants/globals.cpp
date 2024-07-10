#include "globals.h"

QTcpSocket *clientS =  new QTcpSocket();

int zamby=0;
int plant=0;
int lockSun=0;
int Branis=800;
int Suns=800;
int RandomB=0;
int RandomS=0;
QHash<int , int> gamehash;
QMap<int, int> gameMap;
void setVal(){
    for (int i=1 ; i<=72 ; i++){
        gamehash.insert(i,0);
    }
}

