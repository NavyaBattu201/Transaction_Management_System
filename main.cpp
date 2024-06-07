#include <iostream>
#include <cstring>
#include "dll.h"
#include "sll.h"

int main() {
    sll list;
    dll transactions;
    int numacnt, noftrans;
    std::cin >> numacnt >> noftrans;

    for (int i = 0; i < numacnt; i++) {
        int accno;
        std::cin >> accno;
        list.insertinsll(accno);
    }

    for (int i = 0; i < noftrans; i++) {
        int accno, amt;
        char type;
        std::cin >> accno >> type >> amt;
        transactions.insertindll(accno, type, amt, list);
    }

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        if (s == "ITK") {
            int k, x, y;
            char z;
            std::cin >> k >> x >> z >> y;
            transactions.ITK(k, x, z, y, &list);
        } else if (s == "DAM") {
            int m, a;
            std::cin >> m >> a;
            transactions.DAM(m, a, &list);
        } else if (s == "VX") {
            int k;
            std::cin >> k;
            list.VX(k);
        } else if (s == "SY") {
            int k;
            std::cin >> k;
            transactions.SY(k, &list);
        } else if (s == "GX") {
            int k;
            std::cin >> k;
            list.GX(k);
        } else if (s == "FX") {
            int k;
            std::cin >> k;
            transactions.FX(k, &list);
        } else if (s == "RY") {
            int k;
            std::cin >> k;
            transactions.RY(k, &list);
        } else if (s == "M") {
            list.M();
        }
    }

    return 0;
}
