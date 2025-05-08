#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// Функция сортировки пузырьком
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция сортировки вставками
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция для слияния двух отсортированных подмассивов
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Функция сортировки слиянием
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Вспомогательная функция для оценки времени выполнения алгоритма сортировки
void evaluateSortingAlgorithm(void (*sortFunc)(int[], int), int arr[], int n, const std::string& sortName) {
    int* arrCopy = new int[n];
    std::copy(arr, arr + n, arrCopy);

    clock_t start = clock();
    sortFunc(arrCopy, n);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << sortName << " took " << time_taken << " seconds." << std::endl;

    delete[] arrCopy;
}

// Функция для оценки времени выполнения qsort
void evaluateQSort(int arr[], int n) {
    int* arrCopy = new int[n];
    std::copy(arr, arr + n, arrCopy);

    clock_t start = clock();
    std::qsort(arrCopy, n, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
        });
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "qsort took " << time_taken << " seconds." << std::endl;

    delete[] arrCopy;
}

int main() {
    const int n = 100000;
    int* randomArray = new int[n];
    int* increasingArray = new int[n];
    int* decreasingArray = new int[n];
    int* mixedArray = new int[n];

    for (int i = 0; i < n; i++) {
        randomArray[i] = rand() % 1000;
        increasingArray[i] = i;
        decreasingArray[i] = n - i;
        mixedArray[i] = (i < n / 2) ? i : n - i;
    }

    // Оценка времени выполнения на случайном наборе данных
    std::cout << "Random Array:" << std::endl;
    evaluateSortingAlgorithm(bubbleSort, randomArray, n, "Bubble Sort");
    evaluateSortingAlgorithm(insertionSort, randomArray, n, "Insertion Sort");
    evaluateSortingAlgorithm([](int arr[], int n) { mergeSort(arr, 0, n - 1); }, randomArray, n, "Merge Sort");
    evaluateQSort(randomArray, n);

    // Оценка времени выполнения на возрастающем наборе данных
    std::cout << "\nIncreasing Array:" << std::endl;
    evaluateSortingAlgorithm(bubbleSort, increasingArray, n, "Bubble Sort");
    evaluateSortingAlgorithm(insertionSort, increasingArray, n, "Insertion Sort");
    evaluateSortingAlgorithm([](int arr[], int n) { mergeSort(arr, 0, n - 1); }, increasingArray, n, "Merge Sort");
    evaluateQSort(increasingArray, n);

    // Оценка времени выполнения на убывающем наборе данных
    std::cout << "\nDecreasing Array:" << std::endl;
    evaluateSortingAlgorithm(bubbleSort, decreasingArray, n, "Bubble Sort");
    evaluateSortingAlgorithm(insertionSort, decreasingArray, n, "Insertion Sort");
    evaluateSortingAlgorithm([](int arr[], int n) { mergeSort(arr, 0, n - 1); }, decreasingArray, n, "Merge Sort");
    evaluateQSort(decreasingArray, n);

    // Оценка времени выполнения на смешанном наборе данных
    std::cout << "\nMixed Array:" << std::endl;
    evaluateSortingAlgorithm(bubbleSort, mixedArray, n, "Bubble Sort");
    evaluateSortingAlgorithm(insertionSort, mixedArray, n, "Insertion Sort");
    evaluateSortingAlgorithm([](int arr[], int n) { mergeSort(arr, 0, n - 1); }, mixedArray, n, "Merge Sort");
    evaluateQSort(mixedArray, n);

    delete[] randomArray;
    delete[] increasingArray;
    delete[] decreasingArray;
    delete[] mixedArray;

    return 0;
}
