# [xieite](../xieite.md)::[hashes](../hashes.md)::create
Defined in header [<xieite/hashes/create.hpp>](../../include/xieite/hashes/create.hpp)

<br/>

Hashes a value. Currently only supports `std::string`s. Collisions may occur

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::size_t create(std::string_view string) noexcept;
```
### Parameters
- `string` - A `std::string_view`, the value to hash
### Return value
- A `std::size_t`, the hashed result

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/hashes/create.hpp>

int main() {
	switch (xieite::hashes::create("banana")) {
		case xieite::hashes::create("apple"):
			std::cout << "1\n";
			break;
		case xieite::hashes::create("banana"):
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
