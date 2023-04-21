# [`xieite`](../../README.md)`::`[`string`](../../docs/string.md)`::hash`
Defined in header [`<xieite/string/hash.hpp>`](../../include/xieite/string/hash.hpp)

<br/>

"Hashes" a string for use in a `switch`. Collisions may occur.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::size_t hash(std::string_view string) noexcept;
```
### Parameters
- `string` - A `std::string_view` copy, the value to hash
### Return value
- A `std::size_t`, the hashed result

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/hash.hpp>

int main() {
	switch (xieite::string::hash("banana")) {
		case xieite::string::hash("apple"):
			std::cout << "1\n";
			break;
		case xieite::string::hash("banana"):
			std::cout << "2\n";
			break;
		default:
			std::cout << "3\n";
	}
}
```
Output:
```
2
```
