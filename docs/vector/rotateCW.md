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
	const std::vector<std::vector<bool>> tetronimo {
		{ 0, 1, 1 },
		{ 1, 1, 0 },
		{ 0, 0, 0 }
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
0 1 0 
0 1 1 
0 0 1 
```
