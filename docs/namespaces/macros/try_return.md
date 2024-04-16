# [XIEITE](../../macros.md)\_TRY\_RETURN\(\)
Defined in header [<xieite/macros/try_return.hpp>](../../../include/xieite/macros/try_return.hpp)

&nbsp;

## Description
Attempts to return something.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_TRY_RETURN(...) \
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
#include "xieite/macros/try_return.hpp"

template<auto F>
int foo() {
    XIEITE_TRY_RETURN(F());
    XIEITE_TRY_RETURN(F("abc"));
    XIEITE_TRY_RETURN(F(4));
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
