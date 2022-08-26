# gcufl::vector::group
```cpp
template <typename K = std::string, typename V, typename C>
std::unordered_map<K, std::vector<V>> group(const std::vector<V>& values, const C& getGroup) noexcept;
```
Groups values into an unsorted map.
## Example
```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <gcufl/vector.hpp>

int main() {
	std::vector<int> values { 1, 2, 3, 4, 5 };
	std::unordered_map<std::string, std::vector<int>> groups = gcufl::vector::group(values, [](const int value, const int) {
		return value < 3
			? "less"
			: "more";
	});

	std::cout << "less:";
	for (const int value : groups["less"])
		std::cout << ' ' << value;
	std::cout << "\nmore:";
	for (const int value : groups["more"])
		std::cout << ' ' << value;
	std::cout << '\n';
}
```
Output:
```
less: 1 2
more: 3 4 5
```
