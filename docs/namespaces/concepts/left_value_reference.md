# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:LeftValueReference\<\>
Defined in header [<xieite/concepts/left_value_reference.hpp>](../../../include/xieite/concepts/left_value_reference.hpp)

&nbsp;

## Description
Specifies that a type is an lvalue reference.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept LeftValueReference = std::is_lvalue_reference_v<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/left_value_reference.hpp"

int main() {
    std::println("{}", xieite::concepts::LeftValueReference<int>);
    std::println("{}", xieite::concepts::LeftValueReference<int&>);
    std::println("{}", xieite::concepts::LeftValueReference<int&&>);
}
```
Output:
```
false
true
false
```
