# gcufl::OrderedMap<K, V>::operator[]
```cpp
V& operator[](const K key) noexcept;

const V& operator[](const K key) const noexcept;
```
Gets reference to value by orderable key.
## Example
```cpp
#include <iostream>
#include <gcufl/orderedMap.hpp>

int main() {
	gcufl::OrderedMap<char, bool> map;
	map['a'] = true;

	std::cout
		<< std::boolalpha
		<< map['a'] << '\n',
		<< map['b'] << '\n';
}
```
Output:
```
true
false
```
