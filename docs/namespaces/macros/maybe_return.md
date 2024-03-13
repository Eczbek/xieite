# [XIEITE](../../macros.md)\_MAYBE\_RETURN\(\)
Defined in header [<xieite/macros/maybe_return.hpp>](../../../include/xieite/macros/maybe_return.hpp)

&nbsp;

## Description
Detects whether a debug mode is active.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_MAYBE_RETURN(...) \
    if constexpr (requires { \
        __VA_ARGS__; \
    }) { \
        return __VA_ARGS__; \
    }
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/maybe_return.hpp"

template<auto F>
int foo() {
    XIEITE_MAYBE_RETURN(F());
    XIEITE_MAYBE_RETURN(F("abc"));
    XIEITE_MAYBE_RETURN(F(4));
}

int main() {
    constexpr auto lambda = [](int n) {
        return n * n;
    };

    std::println("{}", foo<lambda>());
}
```
Output:
```
16
```
