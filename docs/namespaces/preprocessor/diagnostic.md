# [XIEITE](../../macros.md)\_DIAGNOSTIC\(\)
Defined in header [<xieite/diagnostic.hpp>](../../../include/xieite/diagnostic.hpp)

&nbsp;

## Description
Diagnostic configuration macros.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_DIAGNOSTIC_PUSH() /* ... */
```
#### 2)
```cpp
#define XIEITE_DIAGNOSTIC_POP() /* ... */
```
#### 3)
```cpp
#define XIEITE_DIAGNOSTIC_WARN_GCC(...) /* ... */
#define XIEITE_DIAGNOSTIC_WARN_CLANG(...) /* ... */
#define XIEITE_DIAGNOSTIC_WARN_MSVC(...) /* ... */
```
#### 4)
```cpp
#define XIEITE_DIAGNOSTIC_ERROR_GCC(...) /* ... */
#define XIEITE_DIAGNOSTIC_ERROR_CLANG(...) /* ... */
#define XIEITE_DIAGNOSTIC_ERROR_MSVC(...) /* ... */
```
#### 5)
```cpp
#define XIEITE_DIAGNOSTIC_IGNORE_GCC(...) /* ... */
#define XIEITE_DIAGNOSTIC_IGNORE_CLANG(...) /* ... */
#define XIEITE_DIAGNOSTIC_IGNORE_MSVC(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/diagnostic.hpp>

XIEITE_DIAGNOSTIC_PUSH()
XIEITE_DIAGNOSTIC_IGNORE_GCC(-Wunused-variable)
XIEITE_DIAGNOSTIC_IGNORE_CLANG(-Wunused-variable)
XIEITE_DIAGNOSTIC_IGNORE_MSVC(4189)

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
