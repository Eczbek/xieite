# [XIEITE](../../macros.md)\_FUNCTION\_SIGNATURE
Defined in header [<xieite/macros/function_signature.hpp>](../../../include/xieite/macros/function_signature.hpp)

&nbsp;

## Description
Expands to a function's compiler-specific signature.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_FUNCTION_SIGNATURE /* string-like */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/function_signature.hpp"

int main() {
    std::println("{}", XIEITE_FUNCTION_SIGNATURE);
}
```
Possible output:
```
int main()
```
