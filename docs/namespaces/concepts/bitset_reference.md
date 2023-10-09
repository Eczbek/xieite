# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BitsetReference
Defined in header [<xieite/concepts/bitset_reference.hpp>](../../../include/xieite/concepts/bitset_reference.hpp)

&nbsp;

## Description
Specifies that a type is a `std::bitset::reference`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept BitsetReference = requires(Type value) {
    { value.~Type() };
    { value = std::declval<bool>() } -> std::same_as<Type&>;
    { value = std::declval<Type>() } -> std::same_as<Type&>;
    { static_cast<bool>(value) } -> std::same_as<bool>;
    { ~value } -> std::same_as<bool>;
    { value.flip() } -> std::same_as<Type&>;
};
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <iostream>
#include <xieite/concepts/bitset_reference.hpp>

int main() {
    std::bitset<8> bitset;
    auto bit = bitset[0];

    std::cout << std::boolalpha << xieite::concepts::BitsetReference<decltype(bit)> << '\n';
}
```
Output:
```
true
```
