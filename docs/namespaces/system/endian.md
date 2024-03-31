# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:endian
Defined in header [<xieite/system/endian.hpp>](../../../include/xieite/system/endian.hpp)

&nbsp;

## Description
A namespace of definitions of the system's endianness. See header file for details.

&nbsp;

## Synopsis
#### 1)
```cpp
inline constexpr bool big = /* boolean */;
```
#### 2)
```cpp
inline constexpr bool little = /* boolean */;
```
#### 3)
```cpp
inline constexpr bool mixed = /* boolean */;
```
#### 4)
```cpp
inline constexpr bool none = /* boolean */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/system/endian.hpp"

int main() {
    if (xieite::system::endian::big) {
        std::println("Big-endian");
    }

    if (xieite::system::endian::little) {
        std::println("Little-endian");
    }

    if (xieite::system::endian::mixed) {
        std::println("Mixed-endian");
    }

    if (xieite::system::endian::none) {
        std::println("No-endian");
    }
}
```
Possible output:
```
Little-endian
```
