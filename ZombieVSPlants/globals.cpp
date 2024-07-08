#include "globals.h"

QTcpSocket *clientS =  new QTcpSocket();
int zamby=0;
int plant=0;
QHash<int, int> gameHash;

void initializeGlobals() {
    for (int i = 1; i <= 72; ++i) {
        gameHash.insert(i, 0);
    }
}
