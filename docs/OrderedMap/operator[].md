# gcufl::OrderedMap<K, V>::operator
```cpp
V& operator[](const K key) noexcept;

const V& operator[](const K key) const noexcept;
```
The operator functions of `gcufl::OrderedMap<K, V>`.
## Example
```cpp
#include <gcufl/OrderedMap.hpp>
#include <iostream>

int main() {
	gcufl::OrderedMap<char, bool> map;
	map['a'] = true;

	std::cout << std::boolalpha << map['a'] << '\n';
}
```
Output:
```
true
false
```
