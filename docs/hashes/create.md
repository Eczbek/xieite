# [xieite](../xieite.md)\:\:[hashes](../hashes.md)\:\:create
Defined in header [<xieite/hashes/create.hpp>](../../include/xieite/hashes/create.hpp)

&nbsp;

## Description
Hashes a value. Currently only supports `std::string`s. Collisions may occur

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr std::size_t create(std::string_view string) noexcept;
```
#### Function parameters
- `string` - A `std::string_view`, the value to hash
#### Return type
- `std::size_t`, the hashed result

&nbsp;

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
