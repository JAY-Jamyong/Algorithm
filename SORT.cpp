#include <iostream>

using namespace std;

void SelectSort(int N, int array[]) {
	for (int i = 0; i < N-1; i++) {
		int MinIdx = i;
		for (int j = i; j < N; j++) {
			if (array[j] < array[MinIdx]) MinIdx = j;
		}
		
		swap(array[i], array[MinIdx]);
		
	}
}

void InsertSort(int N, int array[]) {
	for (int i = 1; i < N; ++i) {
		for(int j = i; j > 0; --j) {
			if (array[j-1] > array[j]) swap(array[j-1], array[j]);
			else {
				break;
			}
		}
	}
}

void QuickSort (int start, int end, int array[]) {
	int pivot = start;
	int Rvalue = end, Lvalue = start + 1;
	if (start > end) return;
	while (Lvalue < Rvalue) {
		while (Lvalue <= end) {
			if (array[Lvalue] > array[pivot]) break;
			Lvalue ++;
		}

		while (Rvalue > 0) {
			if (array[Rvalue] < array[pivot]) break;
			Rvalue--;
		}
		if (Lvalue > Rvalue) swap(array[Rvalue], array[Lvalue]);
	} 
	swap(array[pivot], array[Rvalue]);
	QuickSort(start, Rvalue, array);
	QuickSort(Lvalue, end, array);
}

int BinarySearch(int target, int S, int E, int array[]) {
	int start = S;
	int end = E;
	int mid = (start + end) / 2;
	if (start > end) return -1;
	if (array[mid] == target) return mid;

	if (array[mid] > target) {
		BinarySearch(target, start, mid - 1, array);
	} else if (array[mid] < target) {
		BinarySearch(target, mid + 1, end, array);
	}
}

int main() {
	int N = 10;

	int array[N] = {8, 5, 4, 2, 7, 0, 1, 3, 6, 9};

	QuickSort(0, 9, array);

	for (int i = 0; i < N; ++i) {
		std::cout << array[i] << " ";
	}

	return 0;
}