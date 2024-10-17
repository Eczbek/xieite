# [XIEITE](../../macros.md)\_STATIC\_ASSERT\(\)
Defined in header [<xieite/static_assert.hpp>](../../../include/xieite/static_assert.hpp)

&nbsp;

## Description
Expands to `static_assert`, `_Static_assert`, or a compiler-specific extension to emulate it.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_STATIC_ASSERT(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/static_assert.hpp>

XIEITE_STATIC_ASSERT(true, "this is a test");

int main() {}
```
Output:
```
```
