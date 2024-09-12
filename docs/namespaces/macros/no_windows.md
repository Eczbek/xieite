# [XIEITE](../../macros.md)\_ \(no windows\)
Defined in header [<xieite/no_windows.hpp>](../../../src/macros/no_windows.hpp)

&nbsp;

## Description
A wrapper for the `<windows.h>` header (if it exists), excluding generally unwanted features. See header file for specifics. Intentionally lacks inclusion guards.

&nbsp;

## Synopsis
#### 1)
```cpp
#include <windows.h>
```
#### 2)
```cpp
#undef APIENTRY
```
#### 3)
```cpp
#undef APIPRIVATE
```
#### 4)
```cpp
#undef CALLBACK
```
#### 5)
```cpp
#undef CDECL
```
#### 6)
```cpp
#undef CONST
```
#### 7)
```cpp
#undef FALSE
```
#### 8)
```cpp
#undef FAR
```
#### 9)
```cpp
#undef far
```
#### 10)
```cpp
#undef IN
```
#### 11)
```cpp
#undef NEAR
```
#### 12)
```cpp
#undef near
```
#### 13)
```cpp
#undef OPTIONAL
```
#### 14)
```cpp
#undef OUT
```
#### 15)
```cpp
#undef PASCAL
```
#### 16)
```cpp
#undef pascal
```
#### 17)
```cpp
#undef STRICT
```
#### 18)
```cpp
#undef TRUE
```
#### 19)
```cpp
#undef VOID
```

&nbsp;

## Example
```cpp
#include <xieite/no_windows.hpp>

import std;

int main() {
    std::println("{}", std::min(4, 17));
}
```
Possible output:
```
4
```
