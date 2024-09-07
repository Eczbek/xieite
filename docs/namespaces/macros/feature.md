# [XIEITE](../../macros.md)\_FEATURE\_...
Defined in header [<xieite/feature.hpp>](../../../src/macros/feature.hpp)

&nbsp;

## Description
Detects whether some features of the language exist.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_8 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_8 /* boolean */
```
#### 3)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_16 /* boolean */
```
#### 4)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_16 /* boolean */
```
#### 5)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_32 /* boolean */
```
#### 6)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_32 /* boolean */
```
#### 7)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_64 /* boolean */
```
#### 8)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_64 /* boolean */
```
#### 9)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_128 /* boolean */
```
#### 10)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_128 /* boolean */
```
#### 11)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_16 /* boolean */
```
#### 12)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_32 /* boolean */
```
#### 13)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_64 /* boolean */
```
#### 14)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_128 /* boolean */
```
#### 15)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_BRAIN /* boolean */
```
#### 16)
```cpp
#define XIEITE_FEATURE_BASED_POINTER /* boolean */
```
#### 17)
```cpp
#define XIEITE_FEATURE_TYPEOF /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/feature.hpp>

import std;

int main() {
    struct Foo {
#if XIEITE_FEATURE_UNSIGNED_INTEGER_64
        std::uint64_t data;
#else
        std::uint_least64_t data : 64;
#endif
    };

    Foo foo = Foo(7);
    std::println("{}", foo.data);
}
```
Output:
```
7
```
