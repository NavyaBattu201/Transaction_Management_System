#include "sll.h"
#include <algorithm>
#include <iostream>

sll::sll() {
    first = new sllnode;
    last = new sllnode;
    first = last = nullptr;
    len = 0;
}

void sll::GX(int k) {
    int count = 0;
    sllnode *temp = first;
    while (temp != nullptr) {
        if (temp->currbal >= k) {
            count++;
        }
        temp = temp->next;
    }
    std::cout << count << std::endl;
}

sllnode *sll::getfirst() {
    return first;
}

void sll::printslllist() {
    sllnode *temp = first;
    while (temp != nullptr) {
        std::cout << temp->acc << " " << temp->currbal << '\n';
        temp = temp->next;
    }
}

void sll::insertinsll(int x) {
    sllnode *toinsert = new sllnode;
    toinsert->acc = x;
    if (first == nullptr) {
        first = last = toinsert;
        len++;
    } else {
        last->next = toinsert;
        last = toinsert;
        len++;
    }
}

int sll::ispresent(int k) {
    int present = 0;
    sllnode *temp = first;
    while (temp != nullptr) {
        if (temp->acc == k) {
            present++;
        }
        temp = temp->next;
    }
    return present;
}

void sll::M() {
    sllnode *temp = first;
    int max = first->currbal;
    std::vector<int> result;
    while (temp != nullptr) {
        if (temp->currbal > max) {
            max = temp->currbal;
        }
        temp = temp->next;
    }
    sllnode *temp1 = first;
    while (temp1 != nullptr) {
        if (temp1->currbal == max) {
            result.push_back(temp1->acc);
        }
        temp1 = temp1->next;
    }
    std::sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << '\n';
}

void sll::VX(int k) {
    sllnode *temp = first;
    while (temp != nullptr) {
        if (temp->acc == k) {
            std::cout << temp->currbal << '\n';
        }
        temp = temp->next;
    }
}
