# [XIEITE](../../macros.md)\_VERSION\_...
Defined in header [<xieite/macros/version.hpp>](../../../include/xieite/macros/version.hpp)

&nbsp;

## Description
Macros for xieite's current version (major, minor, patch). See header file for definitions.

Also provides checking utilities with optional parameters (major, minor, patch):

&nbsp;

## Synopses
```cpp
#define XIEITE_VERSION_LEAST(...) /* ... */
```
```cpp
#define XIEITE_VERSION_MOST(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/version.hpp>

int main() {
    std::cout
        << std::boolalpha
        << XIEITE_VERSION_LEAST(6, 3) // 6.3.0
        << '\n';
}
```
Output:
```
true
```
