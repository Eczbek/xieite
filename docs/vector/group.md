# `gcufl/vector/group.hpp`
```cpp
template <typename V, std::invocable<V> C>
std::unordered_map<std::invoke_result_t<C(V)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept;
```
```cpp
template <typename V, std::invocable<V, std::size_t> C>
std::unordered_map<std::invoke_result_t<C(V, std::size_t)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept;
```
The function `gcufl::vector::group` groups elements of a vector into a `std::unordered_map`.
<br/>
The resulting unordered-map's keys depend on the return value of the callback.
## Example
```cpp
#include <gcufl/vector/group.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
	const std::vector<int> values { 1, 2, 3, 4, 5 };
	const auto callback = [](const int value) -> bool {
		return value % 2;
	};
	const std::unordered_map<bool, std::vector<int>> groups = gcufl::vector::group(values, callback);

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
