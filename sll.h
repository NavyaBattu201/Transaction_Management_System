#ifndef SLL_H
#define SLL_H

#include "sllnode.h"
#include <vector>

class sll {
private:
    sllnode *first;
    sllnode *last;
    int len;

public:
    sll();
    void insertinsll(int);
    void printslllist();
    int ispresent(int);
    sllnode *getfirst();
    sllnode *getaccno(int k);
    void M();
    void VX(int);
    void GX(int);
};

#endif // SLL_H
