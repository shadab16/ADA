#include <algorithm>
#include <istream>
#include <ostream>
#include <iostream>
#include <vector>

class Matrix {
public:
	template <typename InputIterator>
	Matrix(InputIterator, InputIterator);

	Matrix submatrix(int, int, int) const;

	const int& at(int idx) const {
		return data[idx];
	}

	int& at(int idx) {
		return data[idx];
	}

	const int& at(int row, int col) const {
		return data[row * 4 + col];
	}

	int& at(int row, int col) {
		return data[row * 4 + col];
	}
private:
	int data[16];
};

template <typename InputIterator>
Matrix::Matrix(InputIterator first, InputIterator last) {

	for (size_t i = 0; i < 16 && first != last; ++i, ++first) {
		data[i] = *first;
	}
}

Matrix Matrix::submatrix(int i, int j, int n) const {

	std::vector<int> nums;
	nums.reserve(n * n);

	for (int row = i; row < i + n; ++row) {
		for (int col = j; col < j + n; ++col) {
			nums.push_back(at(row, col));
		}
	}

	return Matrix(nums.begin(), nums.end());
}

const Matrix operator +(const Matrix& lhs, const Matrix& rhs) {

	Matrix result(lhs);
	for (size_t i = 0; i < 16; ++i) {
		result.at(i) += rhs.at(i);
	}
	return result;
}

const Matrix operator -(const Matrix& lhs, const Matrix& rhs) {

	Matrix result(lhs);
	for (size_t i = 0; i < 16; ++i) {
		result.at(i) -= rhs.at(i);
	}
	return result;
}

const Matrix operator *(const Matrix& lhs, const Matrix& rhs) {

	/* TODO */
	return lhs;
}

std::ostream& operator <<(std::ostream& os, const Matrix& matrix) {

	for (size_t i = 0; i < 16; ++i) {
		os << matrix.at(i) << "\t";
		if (i % 4 == 0 && i) {
			os << "\n";
		}
	}
	os << std::endl;
	return os;
}

int main() {

	const int a_[] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 1, 2, 3,
		4, 5, 6, 7
	};

	const int b_[] = {
		2, 3, 4, 5,
		6, 7, 8, 9,
		1, 2, 3, 7,
		8, 9, 1, 2
	};

	Matrix A(a_, a_ + 16);
	Matrix B(b_, b_ + 16);

	Matrix C = A * B;
	std::cout << C << std::endl;

	return 0;
}

