# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BitsetReference\<\>
Defined in fragment [xieite:concepts.BitsetReference](../../../src/concepts/bitset_reference.cpp)

&nbsp;

## Description
Specifies that a type is a `std::bitset<N>::reference`. Uses a "duck test" because the bitset's size cannot be deduced.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept BitsetReference = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
