# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Constant
Defined in header [<xieite/concepts/constant.hpp>](../../../include/xieite/concepts/constant.hpp)

&nbsp;

## Description
Specifies that a type is constant.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Constant = std::is_const_v<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/constant.hpp"

int main() {
    std::println("{}", xieite::concepts::Constant<const int>);
    std::println("{}", xieite::concepts::Constant<int>);
}
```
Output:
```
true
false
```
