# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BitsetReference\<\>
Defined in header [<xieite/concepts/bitset_reference.hpp>](../../../include/xieite/concepts/bitset_reference.hpp)

&nbsp;

## Description
Specifies that a type is a `std::bitset<N>::reference`. Uses a "duck test" because the bitset's size cannot be deduced.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept BitsetReference = /* ... */;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <print>
#include "xieite/concepts/bitset_reference.hpp"

int main() {
    std::bitset<8> bitset;
    auto bit = bitset[0];

    std::println("{}", xieite::concepts::BitsetReference<decltype(bit)>);
}
```
Output:
```
true
```
