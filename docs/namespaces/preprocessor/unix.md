# [XIEITE](../../macros.md)\_UNIX\_...
Defined in header [<xieite/unix.hpp>](../../../include/xieite/unix.hpp)

&nbsp;

## Description
Macros for identifying the current UNIX standard.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_UNIX_POSIX /* integer */
```
#### 2)
```cpp
#define XIEITE_UNIX_X_OPEN /* integer */
```
#### 3)
```cpp
#define XIEITE_UNIX_LINUX_STANDARD_BASE /* integer */
```
#### 4)
```cpp
#define XIEITE_UNIX_POSIX_/* 1988..1992 */ /* integer */
```
#### 5)
```cpp
#define XIEITE_UNIX_X_OPEN_/* 1989..2008 */ /* integer */
```
#### 6)
```cpp
#define XIEITE_UNIX_LINUX_STANDARD_BASE_/* 1_0..5_0 */ /* integer */
```

&nbsp;

## Example
```cpp
#include <xieite/unix_standard.hpp>

import std;

int main() {
#if XIEITE_UNIX_POSIX >= XIEITE_UNIX_POSIX_2008
    std::println("yep");
#else
    std::println("nope");
#endif
}
```
Possible output:
```
yep
```
