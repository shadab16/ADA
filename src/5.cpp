#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

int main() {

	using namespace std;

	vector<int> values;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(values));

	priority_queue<int, vector<int>, greater<int> > heap(values.begin(), values.end());

	while (heap.size() > 1) {

		const int element1 = heap.top();
		heap.pop();

		const int element2 = heap.top();
		heap.pop();

		const int element12 = element1 + element2;

		std::cout << "Merge: " << element1 << " " << element2 << "\n";
		heap.push(element12);
	}

	std::cout << "Final Size: " << heap.top() << std::endl;

	return 0;
}

