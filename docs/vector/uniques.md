# xieite::vector::uniques
Declared in `<xieite/vector/uniques.hpp>`

<br/>

Removes duplicate values.

<br/><br/>

## Declaration
```cpp
template<typename V>
[[nodiscard]]
std::vector<V> uniques(const std::vector<V>& values) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/vector/uniques.hpp>

int main() {
	for (const int value : xieite::vector::uniques<int>({ 1, 2, 3, 2, 1 }))
		std::cout << value << ' ';
	std::cout << '\n';
}
```
Output:
```
1 2 3
```
