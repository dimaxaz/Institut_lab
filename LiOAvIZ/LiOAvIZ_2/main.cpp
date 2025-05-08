#include <iostream>
#include <ctime>
#include <cstdlib>

void multiplyMatrices(int size) {
    int** a = new int* [size];
    int** b = new int* [size];
    int** c = new int* [size];

    for (int i = 0; i < size; ++i) {
        a[i] = new int[size];
        b[i] = new int[size];
        c[i] = new int[size];
    }

    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = rand() % 100 + 1;
        }
    }

    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            b[i][j] = rand() % 100 + 1;
        }
    }

    clock_t start = clock(); 

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int elem_c = 0;
            for (int r = 0; r < size; r++) {
                elem_c += a[i][r] * b[r][j];
            }
            c[i][j] = elem_c;
        }
    }

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Size: " << size << " x " << size << ", Time taken: " << time_taken << " sec" << std::endl;

    for (int i = 0; i < size; ++i) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;
}

int main() {
    int sizes[] = { 100, 200, 400, 1000, 2000 };
    for (int size : sizes) {
        multiplyMatrices(size);
    }
    return 0;
}
