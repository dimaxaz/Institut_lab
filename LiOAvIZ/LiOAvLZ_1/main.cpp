#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    unsigned size_rows = 0,
        size_cols = 0;
    cin >> size_rows
        >> size_cols;

    int** dynamicArray = new int* [size_rows];
    for (unsigned i = 0; i < size_rows; ++i)
        dynamicArray[i] = new int[size_cols];

    for (unsigned i = 0; i < size_rows; ++i)
        for (unsigned j = 0; j < size_cols; ++j)
            dynamicArray[i][j] = rand() % 100;

    struct Array2DWrapper {
        int** data;
        unsigned size_rows;
        unsigned size_cols;

        struct RowWrapper {
            int* begin_;
            int* end_;
            int* begin() const { return begin_; }
            int* end() const { return end_; }
        };

        RowWrapper operator[](unsigned i) const {
            return RowWrapper{ data[i], data[i] + size_cols };
        }

        int** begin() const { return data; }
        int** end() const { return data + size_rows; }
    };

    Array2DWrapper wrapper{ dynamicArray, size_rows, size_cols };

    for (const auto& row : wrapper) {
        for (int num : Array2DWrapper::RowWrapper{ row, row + wrapper.size_cols })
            cout << setw(3) << num;
        cout << endl;
    }

    unsigned row_index = 0;
    for (const auto& row : wrapper) {
        int rowSum = 0;
        for (int num : Array2DWrapper::RowWrapper{ row, row + wrapper.size_cols })
            rowSum += num;

        cout << "row " << ++row_index << ": " << rowSum << endl;
    }

    unsigned col_index = 0;
    for (const auto& col : wrapper) {
        int colSum = 0;
        for (int num : Array2DWrapper::RowWrapper{ col, col + wrapper.size_cols })
            colSum += num;

        cout << "col " << ++col_index << ": " << colSum << endl;
    }

    for (unsigned i = 0; i < size_rows; ++i)
        delete[] dynamicArray[i];
    delete[] dynamicArray;

    return 0;
}