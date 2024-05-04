# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UnsignedIntegral\<\>
Defined in header [<xieite/concepts/unsigned_integral.hpp>](../../../include/xieite/concepts/unsigned_integral.hpp)

&nbsp;

## Description
Specifies that a type is an unsigned integral and not a boolean.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept UnsignedIntegral = std::unsigned_integral<Type_> && !std::same_as<std::remove_cv_t<Type_>, bool>;
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
