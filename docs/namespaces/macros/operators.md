# [XIEITE](../../macros.md) \(operators\)
Defined in header [<xieite/operators.hpp>](../../../include/xieite/operators.hpp)

&nbsp;

## Description
Defines additional logical and bitwise operators, for fun.

&nbsp;

## Synopsis
#### 1)
```cpp
#define nand && /* ... */ &&
```
#### 2)
```cpp
#define nor || /* ... */ ||
```
#### 3)
```cpp
#define xnor ^ /* ... */ ^
```
#### 4)
```cpp
#define nand_eq &= /* ... */ &=
```
#### 5)
```cpp
#define nor_eq |= /* ... */ |=
```
#### 6)
```cpp
#define xnor_eq ^= /* ... */ ^=
```
#### 7)
```cpp
#define bitand & /* ... */ &
```
#### 8)
```cpp
#define bitnor | /* ... */ |
```
#### 9)
```cpp
#define bitxor ^ /* ... */ ^
```
#### 10)
```cpp
#define bitxnor ^ /* ... */ ^
```
#### 11)
```cpp
#define bitand_eq &= /* ... */ &=
```
#### 12)
```cpp
#define bitnand_eq &= /* ... */ &=
```
#### 13)
```cpp
#define bitor_eq |= /* ... */ |=
```
#### 14)
```cpp
#define bitnor_eq |= /* ... */ |=
```
#### 15)
```cpp
#define bitxor_eq ^= /* ... */ ^=
```
#### 16)
```cpp
#define bitxnor_eq ^= /* ... */ ^=
```

&nbsp;

## Example
```cpp
#include <xieite/operators.hpp>

import std;

int main() {
    std::print("{}\n", true xnor true);
    std::print("{}\n", false xnor true);
    std::print("{}\n", true xnor false);
    std::print("{}\n", false xnor false);
}
```
Output:
```
true
false
false
true
```
