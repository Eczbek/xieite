# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Enumeration\<\>
Defined in header [<xieite/concepts/enumeration.hpp>](../../../include/xieite/concepts/enumeration.hpp)

&nbsp;

## Description
Specifies that a type is an enumeration.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Enumeration = std::is_enum_v<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/enumeration.hpp"

struct Foo {};

enum Bar {};

int main() {
    std::println("{}", xieite::concepts::Enumeration<Foo>);
    std::println("{}", xieite::concepts::Enumeration<Bar>);
}
```
Output:
```
false
true
```
