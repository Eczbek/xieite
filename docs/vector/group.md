# xieite::vector::group
Declared in `<xieite/vector/group.hpp>`

<br/>

Groups elements of a vector into a `std::unordered_map`. The resulting map's keys depend on the return value of the callback.

<br/><br/>

## Declarations
```cpp
template<typename V, std::invocable<V> C>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<C(V)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept;
```
```cpp
template<typename V, std::invocable<V, std::size_t> C>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<C(V, std::size_t)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <unordered_map> // std::unordered_map
#include <vector> // std::vector
#include <xieite/vector/group.hpp>

int main() {
	const std::vector<int> values { 1, 2, 3, 4, 5 };
	const decltype([](const int value) -> bool {
		return value % 2;
	}) callback;
	const std::unordered_map<bool, std::vector<int>> groups = xieite::vector::group(values, callback);

	std::cout << "true: ";
	for (const int value : groups[true])
		std::cout << value << ' ';
	std::cout << "\nfalse: ";
	for (const int value : groups[false])
		std::cout << value << ' ';
	std::cout << '\n';
}
```
Output:
```
true: 1 3 5
false: 2 4
```
