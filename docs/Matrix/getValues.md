# gcufl::Matrix<V>::getValues
```cpp
std::vector<V> getValues() const noexcept;
```
Gets the values of the multidimension matrix in one dimension.
## Example
```cpp
#include <gcufl/Matrix.hpp>
#include <iostream>

int main() {
	gcufl::Matrix<int> matrix({ 2, 2 }, { 1, 2, 3, 4 });

	for (const int value : matrix.getValues())
		std::cout << value << ' ';
	std::cout << '\n';
}
```
Output:
```
1 2 3 4 
```
