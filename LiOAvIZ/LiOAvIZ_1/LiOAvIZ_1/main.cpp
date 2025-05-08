#include<iostream>

using namespace std;

int main() {

	unsigned size = 0;
	cin >> size;

	int* dynamicArray{ new int[size] };
	for (int i = 0; i < size; ++i) 
		cin >> dynamicArray[i];

	struct ArrayWrapper {
		int* begin_;
		int* end_;
		int* begin() const { return begin_; }
		int* end() const { return end_; }
	};

	ArrayWrapper wrapper{ dynamicArray, dynamicArray + size };

	int min = *wrapper.begin();
	int max = *wrapper.begin();

		for (int num : wrapper) {

			if (num < min)
				min = num;

			if (num > max)
				max = num;
		}
		cout << "min = " << min << 
				"\nmax = " << max << endl;

		delete[] dynamicArray;
		return 0;
}