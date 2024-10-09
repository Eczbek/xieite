# [XIEITE](../../macros.md) \(keywords\)
Defined in header [<xieite/keywords.hpp>](../../../include/xieite/keywords.hpp)

&nbsp;

## Description
Defines additional logical and bitwise operators, various else-if abbreviations, python-style loops, alternative words for `:`, and special switch case keywords. The logical and bitwise operators mostly preserve the precedence of similar existing operators.

&nbsp;

## Synopsis
#### 1)
```cpp
#define nand /* ... */
```
#### 2)
```cpp
#define nor /* ... */
```
#### 3)
```cpp
#define xnor /* ... */
```
#### 4)
```cpp
#define not_eq /* ... */
```
#### 5)
```cpp
#define nand_eq /* ... */
```
#### 6)
```cpp
#define nor_eq /* ... */
```
#### 7)
```cpp
#define xnor_eq /* ... */
```
#### 8)
```cpp
#define bitnand /* ... */
```
#### 9)
```cpp
#define bitnor /* ... */
```
#### 10)
```cpp
#define bitxnor /* ... */
```
#### 11)
```cpp
#define compl_eq /* ... */
```
#### 12)
```cpp
#define bitand_eq /* ... */
```
#### 13)
```cpp
#define bitnand_eq /* ... */
```
#### 14)
```cpp
#define bitor_eq /* ... */
```
#### 15)
```cpp
#define bitnor_eq /* ... */
```
#### 16)
```cpp
#define bitxor_eq /* ... */
```
#### 17)
```cpp
#define bitxnor_eq /* ... */
```
#### 18)
```cpp
#define bitxnor_eq /* ... */
```
#### 19)
```cpp
#define ifn(...) /* ... */
```
#### 20)
```cpp
#define elif else if
```
#### 21)
```cpp
#define elifn(...) else ifn
```
#### 22)
```cpp
#define if_try(...) /* ... */
```
#### 23)
```cpp
#define ifn_try(...) /* ... */
```
#### 24)
```cpp
#define elif_try else if_try
```
#### 25)
```cpp
#define elifn_try else ifn_try
```
#### 26)
```cpp
#define if_requires(...) if constexpr (requires { __VA_ARGS__; })
```
#### 27)
```cpp
#define ifn_requires(...) if_requires (__VA_ARGS__) {} elif(true)
```
#### 28)
```cpp
#define elif_requires else if_requires
```
#### 29)
```cpp
#define elifn_requires else ifn_requires
```
#### 30)
```cpp
#define if_for(...) /* ... */
```
Allows appending an `else` block to detect `break`s.
#### 31)
```cpp
#define elif_for else if_for
```
#### 32)
```cpp
#define if_while(...) if_for (; __VA_ARGS__;)
```
Allows appending an `else` block to detect `break`s.
#### 33)
```cpp
#define elif_while else if_while
```
#### 34)
```cpp
#define of :
```
For use in range-based `for` loops and defining the underlying type of an enumeration.
#### 35)
```cpp
#define extends :
```
For inheritance.
#### 36)
```cpp
#define inits :
```
For member-initializer lists.
#### 37)
```cpp
#define lest break; case
```
i.e. "for fear that"
#### 38)
```cpp
#define yet break; default
```
#### 39)
```cpp
#define perchance continue; case
```
#### 40)
```cpp
#define otherwise continue; default
```

&nbsp;

## Example
```cpp
#include <xieite/keywords.hpp>

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
