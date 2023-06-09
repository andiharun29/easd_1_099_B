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

void mergeSort(int harun[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(harun, low, mid);
    mergeSort(harun, mid + 1, high);
    merge(harun, low, mid, high);
}

void input(int harun[], int& n) {
    cout << "masukkan jumlah elemen (maximum " << MAX_DATA << "): ";
    cin >> n;
    if (n > MAX_DATA) {
        cout << "jumlah elemen maksimum yang dizinkan!" << endl;
        exit(1);
    }
    cout << "masukkan elemen:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> harun[i];
    }
}

void display(int harun[], int n) {
    cout << "elemen yang terurut:" << endl;
    for (int i = 0; i < n; i++) {
        cout << harun[i] << " ";
    }
    cout << endl;
}

int main() {
    int harun[MAX_DATA];
    int n;
    input(harun, n);
    mergeSort(harun, 0, n - 1);
    display(harun, n);
    return 0;

}