# gcufl::vector::rotateCCW
```cpp
template <typename V>
std::vector<std::vector<V>> rotateCCW(const std::vector<std::vector<V>>& values) noexcept;
```
Rotates a copy of a vector counter-clockwise.
## Example
```cpp
#include <gcufl/vector.hpp>
#include <iostream>
#include <vector>

int main() {
	const std::vector<std::vector<bool>> matrix {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	for (const std::vector<bool>& row : gcufl::vector::rotateCCW(tetronimo)) {
		for (const bool value : row)
			std::cout << value << ' ';
		std::cout << '\n';
	}
}
```
Output:
```
3 6
2 5
1 4
```
