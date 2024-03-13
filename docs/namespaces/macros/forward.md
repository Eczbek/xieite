# [XIEITE](../../macros.md)\_FORWARD\(\)
Defined in header [<xieite/macros/forward.hpp>](../../../include/xieite/macros/forward.hpp)

&nbsp;

## Description
A general utility for forwarding values.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_FORWARD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/forward.hpp"
#include "xieite/types/name.hpp"

template<typename Type>
void foo(Type&&) {
    std::println("{}", xieite::types::name<Type>);
}

template<typename Type>
void bar(Type&& value) {
    foo(XIEITE_FORWARD(value));
}

int main() {
    bar(5);
}
```
Output:
```
int
```
