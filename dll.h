#ifndef DLL_H
#define DLL_H

#include "dllnode.h"
#include "sll.h"

class dll {
private:
    dllnode *header;
    dllnode *trailer;
    dllnode *curser;

public:
    dll();
    void insertindll(int, char, int, sll);
    void printdlllist();
    void FX(int, sll *);
    void RY(int, sll *);
    void ITK(int, int, char, int, sll *);
    void DAM(int, int, sll *);
    void processallafterc(sll *);
    void SY(int, sll *);
};

#endif // DLL_H
