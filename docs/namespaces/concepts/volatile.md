# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Volatile\<\>
Defined in header [<xieite/concepts/volatile.hpp>](../../../include/xieite/concepts/volatile.hpp)

&nbsp;

## Description
Specifies that a type is volatile, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Volatile = std::is_volatile_v<std::remove_reference_t<Type>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/volatile.hpp"

int main() {
    std::println("{}", xieite::concepts::Volatile<volatile int>);
    std::println("{}", xieite::concepts::Volatile<int>);
    std::println("{}", xieite::concepts::Volatile<volatile int&>);
}
```
Output:
```
true
false
true
```
