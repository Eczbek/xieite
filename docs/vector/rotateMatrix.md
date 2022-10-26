# xieite::vector::rotateMatrix
Declared in `<xieite/vector/rotateMatrix.hpp>`
```cpp
template<typename V>
[[nodiscard]]
std::vector<std::vector<V>> rotateMatrix(const std::vector<std::vector<V>>& matrix, int rotations) noexcept;
```
Rotates a 2D vector matrix by 90*. Positive rotations go clockwise, negative rotations go counter-clockwise.
## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/vector/rotateMatrix.hpp>

int main() {
	const std::vector<std::vector<int>> matrix {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	for (const std::vector<int>& row : xieite::vector::rotateMatrix(matrix, 1)) {
		for (const int value : row)
			std::cout << value << ' ';
		std::cout << '\n';
	}
}
```
Output:
```
4 1
5 2
6 3
```
