# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Reference\<\>
Defined in header [<xieite/concepts/reference.hpp>](../../../include/xieite/concepts/reference.hpp)

&nbsp;

## Description
Specifies that a type is an lvalue or rvalue reference.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Reference = std::is_reference_v<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/reference.hpp"

int main() {
    std::println("{}", xieite::concepts::Reference<int>);
    std::println("{}", xieite::concepts::Reference<int&>);
    std::println("{}", xieite::concepts::Reference<int&&>);
}
```
Output:
```
false
true
true
```
