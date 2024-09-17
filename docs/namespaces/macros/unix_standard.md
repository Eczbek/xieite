# [XIEITE](../../macros.md)\_UNIX\_STANDARD\_...
Defined in header [<xieite/unix_standard.hpp>](../../../include/xieite/unix_standard.hpp)

&nbsp;

## Description
Macros for identifying the current UNIX standard.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_1988 /* boolean */
```
#### 2)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_1990 /* boolean */
```
#### 3)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_1993 /* boolean */
```
#### 4)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_1996 /* boolean */
```
#### 5)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_2001 /* boolean */
```
#### 6)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_2008 /* boolean */
```
#### 7)
```cpp
#define XIEITE_UNIX_STANDARD_POSIX_1992 /* boolean */
```
#### 8)
```cpp
#define XIEITE_UNIX_STANDARD_XOPEN_1989 /* boolean */
```
#### 9)
```cpp
#define XIEITE_UNIX_STANDARD_XOPEN_1992 /* boolean */
```
#### 10)
```cpp
#define XIEITE_UNIX_STANDARD_XOPEN_1995 /* boolean */
```
#### 11)
```cpp
#define XIEITE_UNIX_STANDARD_XOPEN_1998 /* boolean */
```
#### 12)
```cpp
#define XIEITE_UNIX_STANDARD_XOPEN_2003 /* boolean */
```
#### 13)
```cpp
#define XIEITE_UNIX_STANDARD_XOPEN_2008 /* boolean */
```
#### 14)
```cpp
#define XIEITE_UNIX_STANDARD_LSB /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/unix_standard.hpp>

import std;

int main() {
#if XIEITE_UNIX_STANDARD_POSIX_2008
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
