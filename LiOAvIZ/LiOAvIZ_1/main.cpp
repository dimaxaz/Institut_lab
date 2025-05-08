#include<iostream>
#include<ctime>


using namespace std;

int main() {

	unsigned size = 0;
	cin >> size;

	int* dynamicArray{ new int[size] };
	for (int i = 0; i < size; ++i)
		dynamicArray[i] = rand() % 10;

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
		cout << num << " ";

		if (num < min)
			min = num;

		if (num > max)
			max = num;
	}
	cout << "\n min = " << min <<
		"\n max = " << max << endl;

	delete[] dynamicArray;
	return 0;
}