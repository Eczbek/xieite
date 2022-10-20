# gcufl::vector::uniques
Declared in `<gcufl/vector/uniques.hpp>`
```cpp
template<typename V>
[[nodiscard]]
std::vector<V> uniques(const std::vector<V>& values) noexcept;
```
Removes duplicate values.
## Example
```cpp
#include <gcufl/vector/uniques.hpp>
#include <iostream>
#include <vector>

int main() {
	for (const int value : gcufl::vector::uniques<int>({ 1, 2, 3, 2, 1 }))
		std::cout << value << '\n';
}
```
Output:
```
1
2
3
```
