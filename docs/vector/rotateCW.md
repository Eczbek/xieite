# gcufl::vector::rotateCW
```cpp
template <typename V>
std::vector<std::vector<V>> rotateCW(const std::vector<std::vector<V>>& values) noexcept;
```
Rotates a copy of a vector clockwise.
## Example
```cpp
#include <iostream>
#include <vector>
#include <gcufl/vector.hpp>

int main() {
	const std::vector<std::vector<bool>> matrix {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	for (const std::vector<bool>& row: gcufl::vector::rotateCW(tetronimo)) {
		for (const bool value: row)
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
