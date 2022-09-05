# gcufl::Matrix<V>::operator
```cpp
V& operator[](const std::vector<std::size_t>& indices);

const V& operator[](const std::vector<std::size_t>& indices) const;
```
The operator functions of `gcufl::Matrix<V>`.
## Example
```cpp
#include <gcufl/Matrix.hpp>
#include <iostream>

int main() {
	gcufl::Matrix<int> matrix({ 2, 2 }, { 1, 2, 3, 4 });

	std::cout << matrix[{ 1, 0 }] << '\n';
}
```
Output:
```
3
```
