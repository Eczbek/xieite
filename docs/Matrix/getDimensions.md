# gcufl::Matrix<V>::getDimensions
```cpp
std::vector<V> getDimensions() const noexcept;
```
Gets the dimensions of the multidimension matrix.
## Example
```cpp
#include <gcufl/Matrix.hpp>
#include <iostream>

int main() {
	gcufl::Matrix<bool> matrix({ 3, 3, 3 });

	for (const std::size_t dimension : matrix.getDimensions())
		std::cout << dimension << ' ';
	std::cout << '\n';
}
```
Output:
```
3 3 3 
```
