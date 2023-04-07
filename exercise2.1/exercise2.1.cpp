#include <iostream>
using namespace std;

const int MAX_DATA = 119; // 99 + 20 -2 x 15 + 10 + 20 ( nim 99)

void merge(int harun[], int low, int mid, int high) {       //arr diganti dengan nama panggilan 
    int i = low, AR = mid + 1, k = low;                     //j diganti dengan inisial nama awal dan terahir nama saya andi harun al rasyid
    int b[MAX_DATA];
    while (i <= mid && AR <= high) {
        if (harun[i] <= harun[AR]) {
            b[k] = harun[i];
            i++;
        }
        else {
            b[k] = harun[AR];
            AR++;
        }
        k++;
    }
    while (AR <= high) {
        b[k] = harun[AR];
        AR++;
        k++;
    }
    while (i <= mid) {
        b[k] = harun[AR];
        i++;
        k++;
    }
    for (k = low; k <= high; k++) {
        harun[k] = b[k];
    }
}

