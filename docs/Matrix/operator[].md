# gcufl::Matrix<V>::operator[]
Declared in `<gcufl/Matrix.hpp>`
```cpp
V& operator[](const std::vector<std::size_t>& indices);

const V& operator[](const std::vector<std::size_t>& indices) const;
```
Gets a value by multiple indices.
## Example
```cpp
#include <gcufl/Matrix.hpp>
#include <iostream>

int main() {
	gcufl::Matrix<char> matrix({ 2, 2 }, { 'a', 'b', 'c', 'd' });

	for (std::size_t x = 0; x < matrix.dimensions[0]; ++x) {
		for (std::size_t y = 0; y < matrix.dimensions[1]; ++y)
			std::cout << matrix[{ x, y }] << ' ';
		std::cout << '\n';
	}
}
```
Output:
```
a b 
c d 
```
