# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Pointer\<\>
Defined in header [<xieite/concepts/pointer.hpp>](../../../include/xieite/concepts/pointer.hpp)

&nbsp;

## Description
Specifies that a type is a pointer, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Pointer = std::is_pointer_v<std::remove_reference_t<Type>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/pointer.hpp"

int main() {
    std::println("{}", xieite::concepts::Pointer<int>);
    std::println("{}", xieite::concepts::Pointer<int*>);
    std::println("{}", xieite::concepts::Pointer<int*&>);
}
```
Output:
```
false
true
true
```
