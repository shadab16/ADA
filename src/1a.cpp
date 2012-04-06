#include <iostream>

template <typename RandomIterator, typename T>
RandomIterator binary_search(RandomIterator begin, RandomIterator end, const T& value) {

	RandomIterator notfound(end);
	--end;

	if (value < *begin || value > *end) {
		return notfound;
	}

	while (begin <= end) {
		RandomIterator middle = begin + (end - begin) / 2;

		if (value < *middle) {
			end = middle - 1;
		} else if (value > *middle) {
			begin = middle + 1;
		} else {
			return middle;
		}
	}

	return notfound;
}

int main() {

	const int nums[10] = {8, 16, 19, 91, 168, 198, 816, 819, 891, 918};
	const int find = 8;

	const int* found = binary_search(nums, nums + 10, find);

	std::cout << std::boolalpha << "Found: " << (found != nums + 10) << std::endl;

	return 0;
}

