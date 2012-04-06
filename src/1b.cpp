#include <iostream>

template <typename RandomIterator, typename T>
RandomIterator binary_search(RandomIterator begin, RandomIterator end, const T& value) {

	if (begin == end || value < *begin || value > *(end - 1)) {
		return RandomIterator(0);
	}

	RandomIterator middle = begin + (end - begin) / 2;

	if (value < *middle) {
		return binary_search(begin, middle, value);
	} else if (value > *middle) {
		return binary_search(middle, end, value);
	}

	return middle;
}

int main() {

	const int nums[10] = {8, 16, 19, 91, 168, 198, 816, 819, 891, 918};
	const int find = 19;

	const int* found = binary_search(nums, nums + 10, find);

	std::cout << std::boolalpha << "Found: " << bool(found) << std::endl;

	return 0;
}

