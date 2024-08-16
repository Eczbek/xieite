# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Value\<\> \{\}
Defined in header [<xieite/types/value.hpp>](../../../include/xieite/types/value.hpp)

&nbsp;

## Description
A simple value wrapper for metaprogramming purposes.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename value>
struct Value
: std::integral_constant<decltype(value), value> {};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/value.hpp"

int main() {
    std::println("{}", xieite::types::Value<4>::value);
}
```
Possible output:
```
4
```
