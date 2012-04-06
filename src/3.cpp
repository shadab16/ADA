#include <algorithm>
#include <iostream>

int partition(int* A, const int left, const int right) {

	int pivot = A[right];
	int idx = left;

	for (int i = left; i < right; ++i) {
		if (A[i] <= pivot) {
			std::swap(A[i], A[idx++]);
		}
	}

	std::swap(A[idx], A[right]);
	return idx;
}

void quicksort(int* A, const int left, const int right) {

	if (left < right) {

		const int pivot_idx = partition(A, left, right);

		quicksort(A, left, pivot_idx - 1);
		quicksort(A, pivot_idx + 1, right);
	}
}

int main() {

	int nums[] = {7, 2, 0, 3, 5, 4};
	const int count = sizeof(nums) / sizeof(*nums);

	quicksort(nums, 0, count - 1);

	for (int i = 0; i < count; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

