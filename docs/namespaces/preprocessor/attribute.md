# [XIEITE](../../macros.md)\_ATTRIBUTE\_...
Defined in header [<xieite/attribute.hpp>](../../../include/xieite/attribute.hpp)

&nbsp;

## Description
Macros for non-standard compiler-specific statement, label, type, variable, and function attributes. `XIEITE_ATTRIBUTE_PACKED()` has special usage. See header for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_ATTRIBUTE_ALIGN_AS(...) /* ... */
```
#### 2)
```cpp
#define XIEITE_ATTRIBUTE_ASSUME(...) /* ... */
```
#### 3)
```cpp
#define XIEITE_ATTRIBUTE_COLD /* ... */
```
#### 4)
```cpp
#define XIEITE_ATTRIBUTE_DEPRECATED /* ... */
```
#### 5)
```cpp
#define XIEITE_ATTRIBUTE_EXPORT /* ... */
```
#### 6)
```cpp
#define XIEITE_ATTRIBUTE_FALLTHROUGH() /* ... */
```
#### 7)
```cpp
#define XIEITE_ATTRIBUTE_FLATTEN /* ... */
```
#### 8)
```cpp
#define XIEITE_ATTRIBUTE_FORCE_INLINE /* ... */
```
#### 9)
```cpp
#define XIEITE_ATTRIBUTE_HOT /* ... */
```
#### 10)
```cpp
#define XIEITE_ATTRIBUTE_IMPORT /* ... */
```
#### 11)
```cpp
#define XIEITE_ATTRIBUTE_LIKELY /* ... */
```
#### 12)
```cpp
#define XIEITE_ATTRIBUTE_LOCAL /* ... */
```
#### 13)
```cpp
#define XIEITE_ATTRIBUTE_MAYBE_UNUSED /* ... */
```
#### 14)
```cpp
#define XIEITE_ATTRIBUTE_NO_DEBUG /* ... */
```
#### 15)
```cpp
#define XIEITE_ATTRIBUTE_NO_DISCARD /* ... */
```
#### 16)
```cpp
#define XIEITE_ATTRIBUTE_NO_INLINE /* ... */
```
#### 17)
```cpp
#define XIEITE_ATTRIBUTE_NO_RETURN /* ... */
```
#### 18)
```cpp
#define XIEITE_ATTRIBUTE_NO_THROW /* ... */
```
#### 19)
```cpp
#define XIEITE_ATTRIBUTE_NO_UNIQUE_ADDRESS /* ... */
```
#### 20)
```cpp
#define XIEITE_ATTRIBUTE_NON_NULL /* ... */
```
#### 21)
```cpp
#define XIEITE_ATTRIBUTE_OPTIMIZE /* ... */
```
#### 22)
```cpp
#define XIEITE_ATTRIBUTE_PACKED(...) /* ... */
```
#### 23)
```cpp
#define XIEITE_ATTRIBUTE_RETURNS_NON_NULL /* ... */
```
#### 24)
```cpp
#define XIETIE_ATTRIBUTE_SECTION(...) /* ... */
```
#### 25)
```cpp
#define XIEITE_ATTRIBUTE_STANDARD_CALL /* ... */
```
#### 26)
```cpp
#define XIEITE_ATTRIBUTE_THREAD /* ... */
```
#### 27)
```cpp
#define XIEITE_ATTRIBUTE_UNLIKELY /* ... */
```
#### 28)
```cpp
#define XIEITE_ATTRIBUTE_USED /* ... */
```
#### 29)
```cpp
#define XIEITE_ATTRIBUTE_WEAK /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/attribute.hpp>

import std;

struct Foo {
    bool a;
    unsigned long long int b;
};

struct XIEITE_ATTRIBUTE_PACKED(Bar {
    bool a;
    unsigned long long int b;
});

int main() {
    std::println("{}", sizeof(Foo));
    std::println("{}", sizeof(Bar));
}
```
Possible output:
```
16
9
```
