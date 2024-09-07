# [XIEITE](../../macros.md)\_PRAGMA\(\)
Defined in header [<xieite/pragma.hpp>](../../../src/macros/pragma.hpp)

&nbsp;

## Description
A simple wrapper around `_Pragma()` or MSVC's `__pragma()`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_PRAGMA(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/pragma.hpp>

XIEITE_PRAGMA(message("Hello, world!"))

int main() {}
```
Possible compilation output:
```
Hello, world!
```
