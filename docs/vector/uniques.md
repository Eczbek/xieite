# xieite::vector::uniques
Defined in header `<xieite/vector/uniques.hpp>`

<br/>

Removes duplicate values.

<br/><br/>

## Declaration
```cpp
template<typename T>
[[nodiscard]]
std::vector<T> uniques(const std::vector<T>& values) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
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
