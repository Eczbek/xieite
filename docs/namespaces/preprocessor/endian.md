# [XIEITE](../../macros.md)\_ENDIAN\_...
Defined in header [<xieite/endian.hpp>](../../../include/xieite/endian.hpp)

&nbsp;

## Description
Detects the system's endianness.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_ENDIAN_BIG /* boolean */
```
#### 2)
```cpp
#define XIEITE_ENDIAN_LITTLE /* boolean */
```
#### 3)
```cpp
#define XIEITE_ENDIAN_BIG_WORD /* boolean */
```
#### 4)
```cpp
#define XIEITE_ENDIAN_LITTLE_WORD /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/endian.hpp>

import std;

int main() {
#if XIEITE_ENDIAN_BIG
    std::println("big-endian");
#elif XIEITE_ENDIAN_LITTLE
    std::println("little-endian");
#else
    std::println("mixed-endian");
#endif
}
```
Possible output:
```
little-endian
```
