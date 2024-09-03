# [XIEITE](../../macros.md)\_FUNCTION\_SIGNATURE
Defined in header ["function_signature.hpp"](../../../src/macros/function_signature.hpp)

&nbsp;

## Description
Expands to a function's compiler-specific signature in string form.

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
