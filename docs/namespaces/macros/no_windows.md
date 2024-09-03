# [XIEITE](../../macros.md) \(No windows\)
Defined in header ["no_windows.hpp"](../../../src/macros/no_windows.hpp)

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
#undef IN
```
#### 10)
```cpp
#undef NEAR
```
#### 11)
```cpp
#undef OPTIONAL
```
#### 12)
```cpp
#undef OUT
```
#### 13)
```cpp
#undef PASCAL
```
#### 14)
```cpp
#undef STRICT
```
#### 15)
```cpp
#undef TRUE
```
#### 16)
```cpp
#undef VOID
```
#### 17)
```cpp
#undef far
```
#### 18)
```cpp
#undef near
```
#### 19)
```cpp
#undef pascal
```

&nbsp;

## Example
```cpp
#include "no_windows.hpp"

import std;

int main() {
    std::println("{}", std::min(4, 17));
}
```
Possible output:
```
4
```
