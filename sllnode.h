#ifndef SLLNODE_H
#define SLLNODE_H

class sllnode {
private:
    int acc;
    int currbal;
    sllnode *next;

public:
    sllnode();
    friend class dll;
    friend class sll;
};

#endif // SLLNODE_H
