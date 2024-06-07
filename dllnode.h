#ifndef DLLNODE_H
#define DLLNODE_H

class dllnode {
private:
    int accno;
    char type;
    int amount;
    dllnode *next;
    dllnode *prev;

public:
    dllnode();
    friend class dll;
    friend class sll;
};

#endif // DLLNODE_H
