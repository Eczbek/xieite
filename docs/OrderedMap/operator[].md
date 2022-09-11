# gcufl::OrderedMap<K, V>::operator[]
Declared in `<gcufl/OrderedMap.hpp>`
```cpp
V& operator[](const K key) noexcept;

const V& operator[](const K key) const noexcept;
```
Gets a value by orderable key from an `OrderedMap`.
## Example
```cpp
#include <gcufl/OrderedMap.hpp>
#include <iostream>

int main() {
	gcufl::OrderedMap<char, bool> map;
	map['a'] = true;
	
	std::cout << std::boolalpha
		<< map['a'] << '\n'
		<< map['b'] << '\n';
}
```
Output:
```
true
false
```
