# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:LeastInteger\<\>
Defined in fragment [xieite:types.LeastInteger](../../../src/types/least_integer.cpp)

&nbsp;

## Description
An alias to the smallest integer type to accomodate some amount of bits.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t bits>
using LeastInteger = /* std::uint_least8_t, std::uint_least16_t, std::uint_least32_t, or std::uint_least64_t */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Type = xieite::types::LeastInteger<13>;

    std::println("{}", std::same_as<Type, std::uint16_t>);
}
```
Possible output:
```
true
```
