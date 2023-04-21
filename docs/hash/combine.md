# [`xieite`](../../README.md)`::`[`hash`](../../docs/hash.md)`::combine`
Defined in header [`<xieite/hash/combine.hpp>`](../../include/xieite/hash/combine.hpp)

<br/>

Combines two hashes.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::size_t combine(std::size_t value1, std::size_t value2) noexcept;
```
### Parameters
- `value1` - A `std::size_t` copy, a hash result
- `value2` - Another `std::size_t` copy, also a hash result
### Return value
- A `std::size_t`, the hashes combined using magic

<br/><br/>

## Example
```cpp
#include <functional>
#include <iostream>
#include <xieite/hash/combine.hpp>

int main() {
	std::size_t hash1 = std::hash<std::string>()("Hello, ");
	std::size_t hash2 = std::hash<std::string>()("world!");

	std::cout
		<< hash1
		<< '\n'
		<< hash2
		<< '\n'
		<< xieite::hash::combine(hash1, hash2)
		<< '\n';
}
```
Possible output:
```cpp
2656948393530125995
15509633392553907848
12398195261174047287
```
