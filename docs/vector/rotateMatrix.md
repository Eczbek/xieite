# xieite::vector::rotateMatrix
Defined in header `<xieite/vector/rotateMatrix.hpp>`

<br/>

Rotates a 2D vector matrix by 90*. Positive rotations go clockwise, negative rotations go counter-clockwise.

<br/><br/>

## Declarations
```cpp
template<typename Value>
[[nodiscard]]
constexpr std::vector<std::vector<Value>> rotateMatrix(const std::vector<std::vector<Value>>& matrix, int rotations) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/vector/rotateMatrix.hpp>

int main() {
	std::vector<std::vector<int>> matrix {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	for (std::vector<int>& row : xieite::vector::rotateMatrix(matrix, 1)) {
		for (int value : row)
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
