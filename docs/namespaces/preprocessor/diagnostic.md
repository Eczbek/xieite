# [XIEITE](../../macros.md)\_DIAGNOSTIC\_...\(\)
Defined in header [<xieite/diagnostic.hpp>](../../../include/xieite/diagnostic.hpp)

&nbsp;

## Description
Compiler-specific diagnostic macros.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_DIAGNOSTIC_MESSAGE(message_) /* ... */
```
#### 2)
```cpp
#define XIEITE_DIAGNOSTIC_WARN(message_) /* ... */
```
#### 3)
```cpp
#define XIEITE_DIAGNOSTIC_ERROR(message_) /* ... */
```
#### 4)
```cpp
#define XIEITE_DIAGNOSTIC_PUSH() /* ... */
```
#### 5)
```cpp
#define XIEITE_DIAGNOSTIC_POP() /* ... */
```
#### 6)
```cpp
#define XIEITE_DIAGNOSTIC_ENABLE_GCC(...) /* ... */
#define XIEITE_DIAGNOSTIC_ENABLE_CLANG(...) /* ... */
#define XIEITE_DIAGNOSTIC_ENABLE_MSVC(...) /* ... */
```
#### 7)
```cpp
#define XIEITE_DIAGNOSTIC_ENFORCE_GCC(...) /* ... */
#define XIEITE_DIAGNOSTIC_ENFORCE_CLANG(...) /* ... */
#define XIEITE_DIAGNOSTIC_ENFORCE_MSVC(...) /* ... */
```
#### 8)
```cpp
#define XIEITE_DIAGNOSTIC_DISABLE_GCC(...) /* ... */
#define XIEITE_DIAGNOSTIC_DISABLE_CLANG(...) /* ... */
#define XIEITE_DIAGNOSTIC_DISABLE_MSVC(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/diagnostic.hpp>

XIEITE_DIAGNOSTIC_PUSH()
XIEITE_DIAGNOSTIC_DISABLE_GCC(-Wunused-variable)
XIEITE_DIAGNOSTIC_DISABLE_CLANG(-Wunused-variable)
XIEITE_DIAGNOSTIC_DISABLE_MSVC(4189)

int main() {
    int x = 5;

XIEITE_DIAGNOSTIC_POP()

    int y = 10;
}
```
Possible compiler output:
```
<source>:13:9: warning: unused variable 'y' [-Wunused-variable]
   90 |         int y = 10;
      |             ^
```
