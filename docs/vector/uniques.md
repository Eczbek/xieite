# xieite::vector::uniques
Defined in header `<xieite/vector/uniques.hpp>`

<br/>

Removes duplicate values.

<br/><br/>

## Declarations
```cpp
template<typename Value>
[[nodiscard]]
std::vector<Value> uniques(const std::vector<Value>& values) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
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
