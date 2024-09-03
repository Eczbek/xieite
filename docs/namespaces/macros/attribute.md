# [XIEITE](../../macros.md)\_ATTRIBUTE\_...
Defined in header ["attribute.hpp"](../../../src/macros/attribute.hpp)

&nbsp;

## Description
Macros for non-standard compiler-specific statement, label, type, variable, and function attributes. `XIEITE_ATTRIBUTE_PACKED()` has special usage. See header file for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_ATTRIBUTE_ASSUME(...) /* ... */
```
#### 2)
```cpp
#define XIEITE_ATTRIBUTE_FALLTHROUGH() /* ... */
```
#### 3)
```cpp
#define XIEITE_ATTRIBUTE_PACKED(...) /* ... */
```
#### 4)
```cpp
#define XIEITE_ATTRIBUTE_FORCE_INLINE /* ... */
```
#### 5)
```cpp
#define XIEITE_ATTRIBUTE_LIKELY /* ... */
```
#### 6)
```cpp
#define XIEITE_ATTRIBUTE_UNLIKELY /* ... */
```
#### 7)
```cpp
#define XIEITE_ATTRIBUTE_MAYBE_UNUSED /* ... */
```
#### 8)
```cpp
#define XIEITE_ATTRIBUTE_NO_DEBUG /* ... */
```
#### 9)
```cpp
#define XIEITE_ATTRIBUTE_NO_DISCARD /* ... */
```
#### 10)
```cpp
#define XIEITE_ATTRIBUTE_NO_INLINE /* ... */
```
#### 11)
```cpp
#define XIEITE_ATTRIBUTE_NO_RETURN /* ... */
```
#### 12)
```cpp
#define XIEITE_ATTRIBUTE_STANDARD_CALL /* ... */
```
#### 13)
```cpp
#define XIEITE_ATTRIBUTE_USED /* ... */
```
#### 14)
```cpp
#define XIEITE_ATTRIBUTE_EXPORT /* ... */
```
#### 15)
```cpp
#define XIEITE_ATTRIBUTE_IMPORT /* ... */
```
#### 16)
```cpp
#define XIEITE_ATTRIBUTE_NO_EXPORT /* ... */
```
#### 17)
```cpp
#define XIEITE_ATTRIBUTE_DEPRECATED /* ... */
```
#### 18)
```cpp
#define XIEITE_ATTRIBUTE_HOT /* ... */
```
#### 19)
```cpp
#define XIEITE_ATTRIBUTE_COLD /* ... */
```
#### 20)
```cpp
#define XIEITE_ATTRIBUTE_NON_NULL /* ... */
```
#### 21)
```cpp
#define XIEITE_ATTRIBUTE_RETURNS_NON_NULL /* ... */
```
#### 22)
```cpp
#define XIEITE_ATTRIBUTE_NO_UNIQUE_ADDRESS /* ... */
```

&nbsp;

## Example
```cpp
#include "attribute.hpp"

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
