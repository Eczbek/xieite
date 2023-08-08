# [xieite](../xieite.md)\:\:[hashes](../hashes.md)\:\:combine
Defined in header [<xieite/hashes/combine.hpp>](../../include/xieite/hashes/combine.hpp)

&nbsp;

## Description
Combines two hashes

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr std::size_t combine(std::size_t value1, std::size_t value2) noexcept;
```
#### Function parameters
- `value1` - A `std::size_t`, a hash result
- `value2` - Another `std::size_t`, also a hash result
#### Return type
- `std::size_t`, the hashes combined using magic

&nbsp;

## Example
```cpp
#include <functional>
#include <iostream>
#include <xieite/hashes/combine.hpp>

int main() {
    std::size_t hash1 = std::hash<std::string>()("Hello, ");
    std::size_t hash2 = std::hash<std::string>()("world!");

    std::cout
        << hash1 << '\n'
        << hash2 << '\n'
        << xieite::hashes::combine(hash1, hash2) << '\n';
}
```
Possible output:
```cpp
2656948393530125995
15509633392553907848
12398195261174047287
```
