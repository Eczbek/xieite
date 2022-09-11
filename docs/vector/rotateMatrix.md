# gcufl::vector::rotateMatrix
Declared in `<gcufl/vector/rotateMatrix.hpp>`
```cpp
template <typename V>
std::vector<std::vector<V>> rotateMatrix(const std::vector<std::vector<V>>& matrix, int rotations) noexcept;
```
Rotates a 2D vector matrix by 90*.
<br/>
Positive rotations go clockwise, negative rotations go counter-clockwise.
## Example
```cpp
#include <gcufl/vector/rotateMatrix.hpp>
#include <iostream>
#include <vector>

int main() {
	const std::vector<std::vector<int>> matrix {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	for (const std::vector<int>& row : gcufl::vector::rotateMatrix(matrix, 1)) {
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
