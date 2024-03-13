# [XIEITE](../../macros.md)\_FEATURE\_...
Defined in header [<xieite/macros/feature.hpp>](../../../include/xieite/macros/feature.hpp)

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
#### 2)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_16 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_16 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_32 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_32 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_64 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_64 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_SIGNED_INTEGER_128 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_UNSIGNED_INTEGER_128 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_16 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_32 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_64 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_128 /* boolean */
```
#### 2)
```cpp
#define XIEITE_FEATURE_FLOATING_POINT_BRAIN /* boolean */
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/macros/feature.hpp"

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
