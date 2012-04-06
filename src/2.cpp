#include <algorithm>
#include <iostream>
#include <iterator>

void merge(int* A, const int offset, const int mid, const int limit) {

	int* sorted = new int[limit - offset + 1];

	int left = offset;
	int right = mid + 1;

	for (int i = 0; i <= limit - offset; ++i) {
		if (left <= mid) {
			if (right <= limit) {
				if (A[left] <= A[right]) {
					sorted[i] = A[left++];
				} else {
					sorted[i] = A[right++];
				}
			} else {
				sorted[i] = A[left++];
			}
		} else {
			sorted[i] = A[right++];
		}
	}

	std::copy(sorted, sorted + limit - offset + 1, A + offset);
	delete[] sorted;
}

void mergesort(int* A, const int offset, const int limit) {

	if (limit - offset < 1) {
		return;
	}

	const int mid = offset + (limit - offset) / 2;

	mergesort(A, offset, mid);
	mergesort(A, mid + 1, limit);

	merge(A, offset, mid, limit);
}

int main() {

	int nums[] = {6, 54, 38, 95, 8, 24, 83, 0, 56, 1};
	const int limit = 10;

	mergesort(nums, 0, limit - 1);

	std::copy(nums, nums + limit, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}

