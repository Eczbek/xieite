# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UnsignedInteger
Defined in header [<xieite/concepts/unsigned_integer.hpp>](../../../include/xieite/concepts/unsigned_integer.hpp)

&nbsp;

## Description
Specifies that a type is an unsigned integral and not a boolean.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept UnsignedInteger = std::unsigned_integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/unsigned_integral.hpp"

int main() {
    std::println("{}", xieite::concepts::UnsignedIntegral<unsigned short int>);
    std::println("{}", xieite::concepts::UnsignedIntegral<bool>);
}
```
Output:
```
true
false
```
