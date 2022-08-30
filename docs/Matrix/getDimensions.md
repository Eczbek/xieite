# gcufl::Matrix<V>::getDimensions
```cpp
std::vector<V> getDimensions() const noexcept;
```
Gets the dimensions of the multidimension matrix.
## Example
```cpp
#include <iostream>
#include <gcufl/Matrix.hpp>

int main() {
	gcufl::Matrix<bool> matrix({ 3, 3, 3 });

	for (const std::size_t dimension : matrix.getDimensions())
		std::cout << dimension << '\n';
}
```
Output:
```
3
3
3
```
