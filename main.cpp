#include <algorithm>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <ctime>
#include <chrono>
using namespace std;

void add(int *a, int *b, int *c, int size) {
    for (int i = 0; i < size; i++) {
        c[i] = a[i]+b[i];
    }
}

int main() {
    
    //time_t start;
    clock_t start = clock();
    int size = 1 << 10;
    int a[size];
    int b[size];
    int c[size];
    for (int i = 0; i < size; i++) {
        a[i] = 1;
        b[i] = 1;
    }
    
    add(a, b, c, size);

    int error = 0;

    for (int i = 0; i < size; i++) {
        error = max(error, c[i]-1);
    }

    //time_t end;
    clock_t end = clock();

    float ms = float(end-start)/CLOCKS_PER_SEC*1000;

    cout << "error: " << error << endl;
    cout << "time elapsed: " << ms << "ms" << endl;

    return 0;
}
