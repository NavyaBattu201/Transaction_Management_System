#include "dll.h"
#include <iostream>

dll::dll() {
    header = new dllnode;
    trailer = new dllnode;
    header->next = trailer;
    trailer->prev = header;
    curser = header;
}

void dll::insertindll(int acc, char t, int amm, sll dublist) {
    int present = 0;
    sllnode *temp = (dublist).getfirst();
    while (temp != nullptr) {
        if (temp->acc == acc) {
            present++;
        }
        temp = temp->next;
    }
    if (present == 0) {
        return;
    }
    dllnode *toinsert = new dllnode;
    toinsert->accno = acc;
    toinsert->type = t;
    toinsert->amount = amm;

    toinsert->prev = trailer->prev;
    toinsert->next = trailer;
    (trailer->prev)->next = toinsert;
    trailer->prev = toinsert;
}

void dll::printdlllist() {
    dllnode *temp = header->next;
    while (temp->next != nullptr) {
        std::cout << temp->accno << " " << temp->type << " " << temp->amount << std::endl;
        temp = temp->next;
    }
}

void dll::FX(int k, sll *list) {
    if (curser == trailer->prev || curser == trailer)
        return;
    curser = curser->next;
    for (int i = 1; i <= k; i++) {
        sllnode *temp = list->getfirst();
        while (curser->accno != temp->acc) {
            temp = temp->next;
        }
        if (curser->type == 'D') {
            temp->currbal += curser->amount;
        } else {
            temp->currbal -= curser->amount;
        }
        if (curser->next == trailer) {
            break;
        } else {
            if (i != k) {
                curser = curser->next;
            }
        }
    }
}

void dll::RY(int k, sll *list) {
    sllnode *temp = list->getfirst();
    if (curser == header)
        return;
    for (int i = 1; i <= k; i++) {
        sllnode *temp = (*list).getfirst();
        while (curser->accno != temp->acc) {
            temp = temp->next;
        }
        if (curser->type == 'D') {
            temp->currbal -= curser->amount;
        } else {
            temp->currbal += curser->amount;
        }
        if (curser->prev == header) {
            break;
        } else {
            curser = curser->prev;
        }
    }
}

void dll::ITK(int k, int x, char z, int y, sll *list) {
    dllnode *t = new dllnode;
    t->accno = x;
    t->type = z;
    t->amount = y;
    dllnode *temp = header->next;
    int present = list->ispresent(x);
    if (present > 0) {
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        t->next = temp->next;
        t->prev = temp;
        temp->next = t;
        (t->next)->prev = t;
        dllnode *temp1 = t;
        int count = 0;
        while (temp1 != trailer) {
            if (temp1 == curser)
                count++;
            temp1 = temp1->next;
        }
        if (count > 0) {
            sllnode *temp2 = (*list).getfirst();
            while (curser->accno != temp2->acc) {
                temp2 = temp2->next;
            }
            if (curser->type == 'D') {
                temp2->currbal += t->amount;
            } else {
                temp2->currbal -= t->amount;
            }
        }
    } else if (present == 0) {
        return;
    }
}

void dll::processallafterc(sll *list) {
    dllnode *temp = curser->next;
    while (temp != trailer) {
        sllnode *temp1 = (*list).getfirst();
        while (temp1->acc != temp->accno) {
            temp1 = temp1->next;
        }
        if (temp->type == 'D') {
            temp1->currbal += temp->amount;
        } else {
            temp1->currbal -= temp->amount;
        }
        temp = temp->next;
    }
}

void dll::DAM(int m, int a, sll *list) {
    dllnode *temp = header->next;
    sllnode *temp1 = (*list).getfirst();
    while (temp1->acc != a) {
        temp1 = temp1->next;
    }
    int i = 1;
    while (temp->next != nullptr) {
        if (temp->accno == a) {
            dllnode *temp2 = temp->prev;
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            if (i <= m) {
                if (temp->type == 'D') {
                    temp1->currbal -= temp->amount;
                } else {
                    temp1->currbal += temp->amount;
                }
            }
            delete temp;
            temp = temp2;
        }
        temp = temp->next;
        i++;
    }
}

void dll::SY(int a, sll *list) {
    sllnode *temp1 = (*list).getfirst();
    while (temp1->acc != a) {
        temp1 = temp1->next;
    }
    int bal = temp1->currbal;
    dllnode *temp = header->next;
    while (temp->next != nullptr) {
        if (temp->accno == a) {
            if (temp->type == 'D') {
                bal -= temp->amount;
            } else {
                bal += temp->amount;
            }
        }
        temp = temp->next;
    }
    std::cout << bal << std::endl;
}
